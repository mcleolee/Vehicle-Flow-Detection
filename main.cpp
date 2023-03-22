#include <iostream>
#include "cardetc.h"
#include "vid2img.h"
#include "adconvert.h"

#define log(x) std::cout << "\n\t" << x << std::endl

int main() {
    VideoToImage v2i;
    // v2i.testForImageAndVideo();
    // v2i.showFilenames();
    std::cout << "image:" << v2i.countImage() << std::endl;
    std::cout << "video:" << v2i.countVideo() << std::endl;

     log("final bool:" << v2i.final());
    return 0;
}
