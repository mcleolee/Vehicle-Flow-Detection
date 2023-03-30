//
// Created by Ravin on 2023/3/30.
//

#ifndef VEHICLE_FLOW_DETECTION_IMG2VID_H
#define VEHICLE_FLOW_DETECTION_IMG2VID_H

#include <opencv2/opencv.hpp>
#include <fstream>
#include <iostream>

extern "C"
{
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/imgutils.h>
#include <libavutil/opt.h>
}

using std::cout;
using std::endl;
using std::cin;

class ImageToVideo{
public:
    ImageToVideo(std::string inputPath, std::string outputPath, int fps);
    bool convert();


private:
    std::string inputPath;
    std::string outputPath;
    int fps;

    AVFormatContext* formatContext = NULL;
    AVCodec* codec = NULL;
    AVCodecContext* codecContext = NULL;
    AVStream* stream = NULL;
    AVPacket packet;
    uint8_t* buffer = NULL;

};

ImageToVideo::ImageToVideo(std::string inputPath, std::string outputPath, int fps) {
    this->inputPath = inputPath;
    this->outputPath = outputPath;
    this->fps = fps;

}

bool ImageToVideo::convert() {
    // open the input directory
    cv::String inputDir(inputPath);
    std::vector<cv::String> filenames;
    cv::glob(inputDir, filenames);

    // 判空
    if(filenames.empty()){
        std::cerr << "NO images" << filenames[0] << endl;
        return false;
    }

    // read first image to get the size of the video
    cv::Mat frame = cv::imread(filenames[0], cv::IMREAD_UNCHANGED);
    if(frame.empty()){
        std::cerr << "CANNOT read images" << filenames[0] << endl;
    }
    int width = frame.cols;
    int height = frame.rows;

    // Initialize the video codec and format // CG start Here
    avformat_alloc_output_context2(&formatContext, NULL, NULL, outputPath.c_str());
    if (!formatContext) {
        std::cerr << "Could not allocate output format context" << std::endl;
        return false;
    }

    codec = avcodec_find_encoder(formatContext->oformat->video_codec);
    if (!codec) {
        std::cerr << "Could not find video codec" << std::endl;
        return false;
    }

    stream = avformat_new_stream(formatContext, codec);
    if (!stream) {
        std::cerr << "Could not allocate video stream" << std::endl;
        return false;
    }

    codecContext = avcodec_alloc_context3(codec);
    if (!codecContext) {
        std::cerr << "Could not allocate codec context" << std::endl;
        return false;
    }
    codecContext->codec_id = codec->id;
    codecContext->codec_type = AVMEDIA_TYPE_VIDEO;
    codecContext->width = width;
    codecContext->height = height;
    codecContext->time_base = {1, fps};
    codecContext->pix_fmt = AV_PIX_FMT_YUV420P;

    if (formatContext->oformat->flags & AVFMT_GLOBALHEADER)
        codecContext->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;

    if (avcodec_open2(codecContext, codec, NULL) < 0) {
        std::cerr << "Could not open codec" << std::endl;
        return false;
    }

    av_dump_format(formatContext, 0, outputPath.c_str(), 1);

    // Initialize the video packet and buffer
    av_init_packet(&packet);
    packet.data = NULL;
    packet.size = 0;

    buffer = (uint8_t*)av_malloc(width * height * 3);

    // CG ended Here

    if(avio_open(&formatContext->pb, outputPath.c_str(), AVIO_FLAG_WRITE) < 0){
        std::cerr << "Could not open output file" << endl;
        return false;
    }
    if(avformat_write_header(formatContext, NULL) < 0){
        srd::cerr << "Error writing video header " << endl;
        return false;
    }

    // Write each frame to the video
    for (size_t i = 0; i < filenames.size(); i++) {
        cv::Mat frame = cv::imread(filenames[i], cv::IMREAD_UNCHANGED);
        if (frame.empty()) {
            std::cerr << "Could not read image " << filenames[i] << std::endl;
            continue;
        }

        // Convert the frame to YUV420P format
        cv::Mat yuv;
        cv::cvtColor(frame, yuv, cv::COLOR_BGR2YUV_I420);

        // Fill the buffer with the converted frame data
        uint8_t *src_y = yuv.data;
        uint8_t *src_u = yuv.data + width * height;
        uint8_t *src_v = yuv.data + width * height * 5 / 4;
        uint8_t *dst = buffer;
        for (int y = 0; y < height; y++) {
            memcpy(dst, src_y, width);
            dst += width;
            src_y += yuv.step[0];
        }
        for (int y = 0; y < height / 2; y++) {
            memcpy(dst, src_u, width / 2);
            dst += width / 2;
            src_u += yuv.step[1];
        }
        for (int y = 0; y < height / 2; y++) {
            memcpy(dst, src_v, width / 2);
            dst += width / 2;
            src_v += yuv.step[2];
        }

        // Encode the frame
        int ret = avcodec_send_frame(codecContext, av_frame_alloc());
        if (ret < 0) {
            std::cerr << "Error sending frame to encoder" << std::endl;
            continue;
        }
        while (ret >= 0) {
            ret = avcodec_receive_packet(codecContext, &packet);
            if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF)
                break;
            else if (ret < 0) {
                std::cerr << "Error receiving packet from encoder" << std::endl;
                continue;
            }

            // Write the encoded frame to the video
            packet.stream_index = stream->index;
            av_packet_rescale_ts(&packet, codecContext->time_base, stream->time_base);
            av_interleaved_write_frame(formatContext, &packet);

            av_packet_unref(&packet);
        }
    }
    // Flush the encoder
    int ret = avcodec_send_frame(codecContext, NULL);
    if (ret < 0) {
        std::cerr << "Error flushing encoder" << std::endl;
        return false;
    }
    while (ret >= 0) {
        ret = avcodec_receive_packet(codecContext, &packet);
        if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF)
            break;
        else if (ret < 0) {
            std::cerr << "Error receiving packet from encoder" << std::endl;
            continue;
        }

        // Write the encoded frame to the video
        packet.stream_index = stream->index;
        av_packet_rescale_ts(&packet, codecContext->time_base, stream->time_base);
        av_interleaved_write_frame(formatContext, &packet);

        av_packet_unref(&packet);
    }

    av_write_trailer(formatContext);
    // Close the output file
    avio_close(formatContext->pb);

    // Free resources
    avcodec_free_context(&codecContext);
    avformat_free_context(formatContext);
    av_freep(&buffer);

    return true;
}


#endif //VEHICLE_FLOW_DETECTION_IMG2VID_H
