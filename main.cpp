#include <iostream>
#include "cardetc.h"
#include "vid2img.h"

int main() {
    VideoToImage v2i;
    // v2i.testForImageAndVideo();
    // v2i.showFilenames();
    log("image:" << v2i.countImage());
    log("video:" << v2i.countVideo());
    log(v2i.final());
    return 0;
}
