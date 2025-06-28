#include "serialize.hpp"

#include <fstream>
#include <opencv2/opencv.hpp>

using namespace std;


void ipb::serialization::Serialize(const cv::Mat& m, const std::string& filename) {
    const string binary_filename = filename.substr(0, filename.find_last_of('.')) + ".bin";
    ofstream file(binary_filename, ios_base::out | ios_base::binary);

    // Write Mat properties first
    int rows = m.rows;
    int cols = m.cols;
    int type = m.type();

    file.write(reinterpret_cast<const char*>(&rows), sizeof(rows));
    file.write(reinterpret_cast<const char*>(&cols), sizeof(cols));
    file.write(reinterpret_cast<const char*>(&type), sizeof(type));

    // Write the actual data
    file.write(reinterpret_cast<const char*>(m.data), m.total() * m.elemSize());
}


cv::Mat ipb::serialization::Deserialize(const std::string& filename) {
    ifstream file(filename, ios_base::in | ios_base::binary);

    if (!file.is_open()) {
        throw runtime_error("Could not open file: " + filename);
    }

    // Read Mat properties
    int rows, cols, type;
    file.read(reinterpret_cast<char*>(&rows), sizeof(rows));
    file.read(reinterpret_cast<char*>(&cols), sizeof(cols));
    file.read(reinterpret_cast<char*>(&type), sizeof(type));

    // Create Mat with the read dimensions and type
    cv::Mat mat(rows, cols, type);

    // Read the actual data
    file.read(reinterpret_cast<char*>(mat.data), mat.total() * mat.elemSize());

    return mat;
}
