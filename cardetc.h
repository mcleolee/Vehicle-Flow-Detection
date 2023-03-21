//
// Created by Ravin on 2023/3/20.
//

#ifndef VEHICLE_FLOW_DETECTION_CARDETC_H
#define VEHICLE_FLOW_DETECTION_CARDETC_H

#define log(x) std::cout << "\n\t" << x << std::endl
using std::cout;
using std::endl;
using std::cin;

class Asset{
public:



    // 判断 asset 是不是图像
    bool isImage(const std::string &filename);

// 判断 asset 是不是视频
    bool isVideo(const std::string &filename);

};

inline bool Asset::isImage(const std::string &filename){
        unsigned long preExt = filename.find_last_of(".");  //
        std::string ext = filename.substr(preExt + 1);
        std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
        if (ext == "jpg" || ext == "jpeg" || ext == "png" || ext == "bmp")
        {
            return true;
        }
        return false;
}
inline bool Asset::isVideo(const std::string &filename)
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




#endif //VEHICLE_FLOW_DETECTION_CARDETC_H