//
// Created by Ravin on 2023/3/23.
//

#ifndef VEHICLE_FLOW_DETECTION_ADCONVERT_H
#define VEHICLE_FLOW_DETECTION_ADCONVERT_H

using std::cout;
using std::endl;
using std::cin;

#define RESIZED_FRAME 307200
#define RESIZED_WIDTH 640
#define RESIZED_HEIGHT 480

// 这个类，用于将图片转换为数字信号
class AdConvert{
public:
    // AdConvert();
    // ~AdConvert();
    int init();
    int run();
    int deinit();
    cv::Mat imageData;
    float adData[RESIZED_FRAME];
    // imageData的数据类型应该是cv::Mat，它是OpenCV库中用于表示图像数据的数据类型。
    // cv::Mat是一个矩阵类，可以用来存储和操作图像数据。

    // 1. 读取图片
    int readImage();
    // 2. 图片转换为数字信号
    int imageToAd();
    // 3. 数字信号写入文件
    int writeAd();
    // 4. 读取文件
    int readAd();
    // 5. 数字信号转换为图片
    int adToImage();
    // 6. 显示图片
    int showImage();
    // 7. 释放内存
    int freeMemory();

    int showPixel();
    int showAdData_number();
    int showAdData_image();

private:

};

int AdConvert::readImage(){
    // read image
    cv::Mat image = cv::imread("/Users/raven/CLionProjects/Vehicle-Flow-Detection/Insight-MVT_Annotation_Test/MVI_39031/img00001.jpg");
    // /Users/raven/Insight-MVT_Annotation_Test/MVI_39031/img00001.jpg

    // check if success
    if (image.empty()){
        std::cerr << "Wrong when reading image file!!!\n" << endl;
        return -1;
    }else{
        cout << "read successful! \n";
    }

    // 转换为灰度
    cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
    this->imageData = image.clone();

    return 0;

}

int AdConvert::showImage() {
    if (this->imageData.empty()){
        std::cerr << "NO IMAGE DATA IN AdConvert::imageData." << endl;
        return -1;
    }

    // show image
    cv::namedWindow("pic", cv::WINDOW_NORMAL);
    cv::imshow("pic", this->imageData);
    cv::moveWindow("pic", 600, 300);
    cv::waitKey(0);

    return 0;
}

int AdConvert::imageToAd() {
    // 判个空
    if (this->imageData.empty()){
        std::cerr << "NO IMAGE DATA IN AdConvert::imageData." << endl;
        return -1;
    }

    // 要缩小图像尺寸，太大的图像可能会导致算力不足
    // 输出原图像素的函数在下面
    // 但是其实知道像素是 960*540
    // 在实际应用中，常用的图像大小是 320x240 或者 640x480，这些尺寸既可以保证图像质量，又可以满足实时性的要求。
    // 对于像素尺寸为 960x540 的图像，如果计算资源足够充足，可以考虑将其缩小到 320x180 或者 480x270 的大小，以适应车道流量识别任务的要求。
    cv::Mat resizedImage;
    cv::resize(this->imageData, resizedImage, cv::Size(640, 480), cv::INTER_AREA);

    // 归一化，就是 0-1 之间
    resizedImage.convertTo(resizedImage, CV_32FC1, 1.0/ 255.0);

    // 将图像数据储存为一维的数组
    int index = 0;
    for(int i=0; i<resizedImage.rows; i++)
        for(int j=0; j < resizedImage.cols; j++)
            this->adData[index++] = resizedImage.at<float>(i,j) * 2.0 - 1.0;

    return 0;
}

int AdConvert::showAdData_number(){
    for(int i = 0; i < RESIZED_FRAME; i++)
        cout << adData[i] << "\n" ;
}

int AdConvert::showAdData_image(){

}


// 这个有问题。。。但是不是必须要的方法，懒得管了
int AdConvert::showPixel(){
    for (int i = 0; i < this->imageData.rows; i++) {
        for (int j = 0; j < this->imageData.cols; j++) {
            std::cout << this->imageData.at<uchar>(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

int AdConvert::freeMemory() {
    // free ad

    // free image
//    if(imageData != nullptr){
//        delete[] imageData;
//        imageData = nullptr;
//    }
    return 0;
}

#endif //VEHICLE_FLOW_DETECTION_ADCONVERT_H
