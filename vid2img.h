//
// Created by Ravin on 2023/3/22.
//

#ifndef VEHICLE_FLOW_DETECTION_VID2IMG_H
#define VEHICLE_FLOW_DETECTION_VID2IMG_H

#include <filesystem>
#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>

using std::cout;
using std::endl;
using std::cin;

namespace fs = std::__fs::filesystem;


class VideoToImage{
public:
    std::vector<std::string> filenames = runTroughAllFiles();
    int totalFiles = filenames.size();

    static bool isImage(const std::string &filename);       // 判断 asset 是不是图像
    static bool isVideo(const std::string &filename);       // 判断 asset 是不是视频
    int testForImageAndVideo();                      // 测试
    std::vector<std::string> runTroughAllFiles();    // 遍历所有文件
    int showFilenames();
    int countImage();
    int countVideo();
    bool final();

private:
    std::string videoPath;
    std::string imagePath;

};

// ============================================ 实现 =============================================== //

inline bool VideoToImage::isImage(const std::string &filename){
    unsigned long preExt = filename.find_last_of('.');  //
    std::string ext = filename.substr(preExt + 1);
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
    if (ext == "jpg" || ext == "jpeg" || ext == "png" || ext == "bmp")
    {
        return true;
    }
    return false;
}
inline bool VideoToImage::isVideo(const std::string &filename)
{
    unsigned long preExt = filename.find_last_of('.');
    std::string ext = filename.substr(preExt + 1);
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
    if (ext == "mp4" || ext == "avi" || ext == "mov" || ext == "wmv")
    {
        return true;
    }
    return false;
}

inline int VideoToImage::testForImageAndVideo(){
    cout << "\n================ test ===================\n\n";
    std::string testString1 = "thisIsATest.jpg";
    std::string testString2 = "thisIsATest.mp4";
    bool test1 = isImage(testString1);
    bool test2 = isVideo(testString1);
    bool test3 = isImage(testString2);
    bool test4 = isVideo(testString2);

    cout << "the result should be 1 0 0 1 \n";
    cout << "the test result is: " << test1 << test2 << test3 << test4 << endl;

    std::cout << "image:" << countImage() << std::endl;
    std::cout << "video:" << countVideo() << std::endl;

    cout << "final bool:" << final() << endl;
    cout << "\n================ test end =================\n";

    return 0;
}



inline std::vector<std::string> VideoToImage::runTroughAllFiles(){
    std::vector<std::string> filenames;
    fs::path showPath("/Users/raven/Insight-MVT_Annotation_Test/MVI_39031");  // 这里是文件夹路径
    for(const auto& entry : fs::directory_iterator(showPath)) // 遍历
        if(!fs::is_directory(entry.status())) // 如果不是文件夹
            filenames.push_back(entry.path().filename().string()); // add into vector
    return filenames;
}

/*
 *  这个程序将遍历文件夹中的所有文件名，并将它们添加到filenames向量中。
 *  你可以使用push_back()方法将每个文件名添加到向量中。最后，程序将打印所有文件名。
 *  请注意，我们使用entry.path().filename().string()获取文件名字符串，
 *  因为entry.path().filename()返回一个std::filesystem::path对象，而不是一个字符串。
 *  使用string()方法将其转换为字符串类型。
 */


inline int VideoToImage::showFilenames(){
    cout << "This is all file names: \n";
    for(const auto& filename : filenames)
        cout << filename << endl;
    return 0;
}

inline int VideoToImage::countImage() {
    int count = 0;
    for(const auto& filename : filenames)
        if(isImage(filename))
            count++;
    return count;
}

// 函数被定义为inline，这意味着编译器可能会在使用函数的地方将其内联展开，而不是调用函数。

// 该函数的作用是计算在VideoToImage对象的filenames向量中包含多少个图像文件。
// 函数使用一个名为count的整数变量来计算找到的图像文件数。
// 在for循环中，它遍历filenames向量中的所有元素，如果当前元素是图像文件，则将计数器count加1。
// 最后，函数返回count变量的值。
//
// 在循环中，filename是filenames向量中的每个元素。
// const auto&表示我们使用filename时不希望修改其值，因此我们使用引用来避免复制。
// isImage(filename)是另一个函数调用，它用于判断给定文件名是否是一个图像文件。
// 如果是，count变量将被增加1。

inline int VideoToImage::countVideo() {
    int count =0;
    for(const auto &filename : filenames)
        if(isVideo(filename))
            count++;
    return count ;
}

bool VideoToImage::final() {
    if( countImage() && countVideo()==0 )
        return true;
    else{
        cout << "no image or there are still videos" << endl;
        return false;
    }
}


#endif //VEHICLE_FLOW_DETECTION_VID2IMG_H
