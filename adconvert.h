//
// Created by Ravin on 2023/3/23.
//

#ifndef VEHICLE_FLOW_DETECTION_ADCONVERT_H
#define VEHICLE_FLOW_DETECTION_ADCONVERT_H

using std::cout;
using std::endl;
using std::cin;

// 这个类，用于将图片转换为数字信号
class AdConvert{
public:
    AdConvert();
    ~AdConvert();
    int init();
    int run();
    int deinit();
    cv::Mat imageData;
    // imageData的数据类型应该是cv::Mat，它是OpenCV库中用于表示图像数据的数据类型。
    // cv::Mat是一个矩阵类，可以用来存储和操作图像数据。
    // 在上述代码中，读取到的图像数据被保存到imageData中，因此它的数据类型应该是cv::Mat。

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
private:

};

int AdConvert::readImage(){
    // read image
    cv::Mat image = cv::imread("img00001.jpg");
    // /Users/raven/Insight-MVT_Annotation_Test/MVI_39031/img00001.jpg

    // check if success
    if (image.empty()){
        std::cerr << "Wrong when reading image file!!!" << endl;
        return -1;
    }

    // 转换为灰度
    cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);

    this->imageData

}
#endif //VEHICLE_FLOW_DETECTION_ADCONVERT_H
