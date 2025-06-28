#include <opencv2/opencv.hpp>
#include <fstream>
#include <vector>
#include "homework_5.h"

using namespace cv;
using namespace std;


void test_serialize() {
    string img_file_name = "lenna.png";
    Mat image = imread("../data/" + img_file_name);

    String binary_filename = "lenna.bin";
    ipb::serialization::Serialize(image, binary_filename);

    Mat loaded_image = ipb::serialization::Deserialize(binary_filename);
    String windowName = "image"; //Name of the window
    namedWindow(windowName); // Create a window
    imshow(windowName, loaded_image); // Show our image inside the created window.
    waitKey(0); // Wait for any keystroke in the window
    destroyWindow(windowName);
}

void test_convertDataset() {
    string img_path = "../data/freiburg/images/";
    string bin_path = "../data/freiburg/bin/";
    ipb::serialization::sifts::ConvertDataset(img_path);
    auto descriptors = ipb::serialization::sifts::LoadDataset(bin_path);

    // display first descriptor
    String windowName = "key points"; //Name of the window
    namedWindow(windowName); // Create a window
    imshow(windowName, descriptors.front()); // Show our image inside the created window.
    waitKey(0); // Wait for any keystroke in the window
    destroyWindow(windowName);
}

int main(int argc, char** argv)
{
    test_serialize();
    test_convertDataset();
    return 0;
}