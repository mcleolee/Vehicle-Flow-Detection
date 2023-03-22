//
// Created by Ravin on 2023/3/22.
//

#ifndef VEHICLE_FLOW_DETECTION_VID2IMG_H
#define VEHICLE_FLOW_DETECTION_VID2IMG_H

#include <filesystem>
#include <vector>
#include <iostream>

#define log(x) std::cout << "\n\t" << x << std::endl

using std::cout;
using std::endl;
using std::cin;

namespace fs = std::__fs::filesystem;

class VideoToImage{
public:

    std::vector<std::string> filenames = runTroughAllFiles();
    int totalFiles = filenames.size();

    bool isImage(const std::string &filename);       // 判断 asset 是不是图像
    bool isVideo(const std::string &filename);       // 判断 asset 是不是视频
    int testForImageAndVideo();                      // 测试
    std::vector<std::string> runTroughAllFiles();    // 遍历所有文件
    int showFilenames();
    int countImage();
    int countVideo();

private:

    std::string videoPath;
    std::string imagePath;

};

// ============================================ 实现 =============================================== //



inline bool VideoToImage::isImage(const std::string &filename){
    unsigned long preExt = filename.find_last_of(".");  //
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
    unsigned long preExt = filename.find_last_of(".");
    std::string ext = filename.substr(preExt + 1);
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
    if (ext == "mp4" || ext == "avi" || ext == "mov" || ext == "wmv")
    {
        return true;
    }
    return false;
}

inline int VideoToImage::testForImageAndVideo(){
    std::string testString1 = "thisIsATest.jpg";
    std::string testString2 = "thisIsATest.mp4";
    bool test1 = isImage(testString1);
    bool test2 = isVideo(testString1);
    bool test3 = isImage(testString2);
    bool test4 = isVideo(testString2);
    log("the result should be 1 0 0 1");
    log(test1);
    log(test2);
    log(test3);
    log(test4);
}



inline std::vector<std::string> VideoToImage::runTroughAllFiles(){
    std::vector<std::string> filenames;
    fs::path showPath("/Users/raven/Insight-MVT_Annotation_Test/MVI_39031");  // 这里是文件夹路径
    for(const auto& entry : fs::directory_iterator(showPath)) // 遍历
        if(!fs::is_directory(entry.status())) // 如果不是文件夹
            filenames.push_back(entry.path().filename().string()); // add into vector

    return filenames;
}

inline int VideoToImage::showFilenames(){
    log("This is all file names: \n");
    for(const auto& filename : filenames)
        cout << filename << endl;
    return 0;
}

inline int VideoToImage::countImage() {
    int count;
    


    return count;
}

inline int VideoToImage::countVideo() {
    int count;



    return count ;
}

/*
 *  这个程序将遍历文件夹中的所有文件名，并将它们添加到filenames向量中。
 *  你可以使用push_back()方法将每个文件名添加到向量中。最后，程序将打印所有文件名。
 *  请注意，我们使用entry.path().filename().string()获取文件名字符串，
 *  因为entry.path().filename()返回一个std::filesystem::path对象，而不是一个字符串。
 *  使用string()方法将其转换为字符串类型。
 */

#endif //VEHICLE_FLOW_DETECTION_VID2IMG_H
