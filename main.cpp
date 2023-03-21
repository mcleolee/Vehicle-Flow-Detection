#include <iostream>
#include "cardetc.h"

int main() {
    std::string testString1 = "fuckme.jpg";
    std::string testString2 = "fuckme.mp4";
    Asset ast;
    bool test1 = ast.isImage(testString1);

    log(test1);

    return 0;
}
