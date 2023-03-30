//
// Created by Ravin on 2023/3/30.
//

#ifndef VEHICLE_FLOW_DETECTION_BACKGROUND_H
#define VEHICLE_FLOW_DETECTION_BACKGROUND_H

class BackgroundSubtractor {
public:
    BackgroundSubtractor(const std::string& imagePathPrefix) : imagePathPrefix(imagePathPrefix) {}

    void process() {
        // Load the image sequence
        std::vector<cv::Mat> images;
        for (int i = 1; i <= 100; i++) {
            std::string filename = imagePathPrefix + "/image" + std::to_string(i) + ".png";
            cv::Mat image = cv::imread(filename, cv::IMREAD_COLOR);
            if (image.empty()) {
                std::cerr << "Could not read image " << filename << std::endl;
                return;
            }
            images.push_back(image);
        }

        // Initialize the background subtractor
        cv::Ptr<cv::BackgroundSubtractorMOG2> bgSubtractor = cv::createBackgroundSubtractorMOG2();

        // Process each image in the sequence
        cv::Mat fgMask;
        for (const cv::Mat& image : images) {
            // Apply the background subtractor to the current image
            bgSubtractor->apply(image, fgMask);

            // Perform morphological operations on the foreground mask to remove noise and small objects
            cv::morphologyEx(fgMask, fgMask, cv::MORPH_OPEN, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));

            // Display the foreground mask
            cv::imshow("Foreground mask", fgMask);

            // Wait for a key press
            cv::waitKey(1);
        }
    }

private:
    std::string imagePathPrefix;
};
// 将图像序列的路径传递给构造函数，然后调用 process() 方法来处理图像序列。
// 在 process() 方法中，我们执行与前面示例中相同的操作，
// 包括加载图像序列、初始化背景模型、应用背景建模算法、对前景掩模进行形态学操作以去除噪声和小的前景对象，以及显示前景掩模。

#endif //VEHICLE_FLOW_DETECTION_BACKGROUND_H
