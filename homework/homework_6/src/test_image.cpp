//
// Created by hendrik on 27.06.25.
//

#include <iostream>
#include "Image.hpp"

using namespace std;

void test_image() {
    igg::Image image(10, 10);
    cout << image.rows() << " " << image.cols() << endl;

    igg::Image lenna;
    bool read = lenna.FillFromPgm("../data/lena.ascii.pgm");
    if (read)
        cout << "Read image successfully" << endl;
    else
        cout << "Failed to read image" << endl;

    int value = lenna.at(100, 100);
    cout << value << endl;

    // change rows to defined value
    for (int i = 200; i < 300; i++) {
        for (int j = 0; j < lenna.cols(); j++) {
            lenna.at(i, j) = 255;
        }
    }
    lenna.WriteToPgm("../data/test.ascii.pgm");
    cout << lenna.rows() << " " << lenna.cols() << endl;

}

int main() {
    test_image();
    return 0;
}

