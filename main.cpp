#include <iostream>
#include "cardetc.h"
#include "vid2img.h"
#include "adconvert.h"

#define log(x) std::cout << "\n\t" << x << std::endl
#include <opencv2/opencv.hpp>

int main() {
    VideoToImage v2i;
    AdConvert adc;
    // v2i.testForImageAndVideo();
    // v2i.showFilenames();
    adc.readImage();
    adc.showImage();
    adc.imageToAd();
    adc.showAdData_number();

//    adc.showPixel();


    getchar();
    return 0;
}
