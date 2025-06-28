//
// Created by hendrik on 27.06.25.
//

#include <iostream>
#include "homework_6.h"

using namespace std;

void test_image() {
    cout << "Test empty image: " << endl;
    igg::Image image(10, 10);
    cout << image.rows() << " " << image.cols() << endl;

    cout << "Test read from file: " << endl;
    igg::Image lenna;
    bool read = lenna.FillFromPgm("../data/lena.ascii.pgm");
    if (read)
        cout << "Read image successfully" << endl;
    else
        cout << "Failed to read image" << endl;

    cout << "Test at(): " << endl;
    int value = lenna.at(100, 100);
    cout << value << endl;

    // change rows to defined value
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < lenna.cols(); j++) {
            lenna.at(i, j) = 255;
        }
    }

    cout << "Test write: " << endl;
    lenna.WriteToPgm("../data/test.ascii.pgm");
    cout << lenna.rows() << " " << lenna.cols() << endl;


    // test histogram
    cout << "Test Histogram: " << endl;
    auto histogram = lenna.ComputeHistogram(1);
    for (auto &value: histogram) {
        cout << value << " ";
    }
    cout  << endl << "dummy" << endl;
    igg::Image dummy;

    dummy.FillFromPgm("../tests/data/dummy_file.pgm");
    const auto& image_ref = dummy;
    auto histogram_dummy = image_ref.ComputeHistogram(1);
    cout  <<  histogram_dummy.size() << endl;
    cout << histogram_dummy.front();




    // test downscale
    cout << endl << "Test Downscale: " << endl;
    lenna.DownScale(2);
    lenna.WriteToPgm("../data/lenna_downscaled.pgm");


    // test upscale
    cout << "Test Upscale: " << endl;
    lenna.FillFromPgm("../data/lena.ascii.pgm");
    lenna.UpScale(2);
    lenna.WriteToPgm("../data/lenna_upscaled.pgm");

}

int main() {
    test_image();
    return 0;
}

