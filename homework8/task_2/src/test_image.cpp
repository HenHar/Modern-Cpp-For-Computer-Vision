#include <iostream>
#include "homework_8.h"

using namespace std;

int test_image() {
    std::shared_ptr<igg::IoStrategy> png_strategy = std::make_shared<igg::PngIoStrategy>();
    std::shared_ptr<igg::IoStrategy> ppm_strategy = std::make_shared<igg::PpmIoStrategy>();

    igg::Image image = igg::Image();

    image.SetIoStrategy(png_strategy);
    image.ReadFromDisk("data/tux.png");
    cout << image.rows() << " " << image.cols() << endl;

    //image.UpScale(4);
    image.DownScale(2);

    cout << image.rows() << " " << image.cols() << endl;
    image.WriteToDisk("data/tux_scaled.png");
    return 0;
}

int main() {
    test_image();
    return 0;
}

