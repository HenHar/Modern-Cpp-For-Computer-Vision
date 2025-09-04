#include <fstream>
#include <sstream>
#include <png++/png.hpp>

#include "IoStrategies.hpp"
#include "Image.hpp"

using namespace std;

namespace igg {
    vector<png::rgb_pixel> getPixelsFromLine(string &line) {
        std::istringstream iss(line);
        std::vector<int> numbers;
        std::vector<png::rgb_pixel> pixels;

        int num;
        // Read all numbers from the line
        while (iss >> num) {
            numbers.push_back(num);
        }

        // Process numbers in groups of 3
        for (size_t i = 0; i + 2 < numbers.size(); i += 3) {
            png::rgb_pixel pixel = png::rgb_pixel(numbers[i], numbers[i + 1], numbers[i + 2]);
            pixels.push_back(pixel);
        }
        return pixels;
    }

    void PpmIoStrategy::WriteToDisk(ImageData &imageData, const std::string &file_name) {
        ofstream file(file_name);

        // Write Mat properties first
        file << "P3" << endl;
        file << "# Generated PPM image" << std::endl;
        file << imageData.cols<< " " << imageData.rows << endl;
        file << "255" << endl;

        int char_count;
        for (int r = 0; r < imageData.rows; r++) {
            for (int c = 0; c < imageData.cols; c++) {
                if (char_count >= 70) {
                    file << std::endl;
                    char_count = 0;
                }

                int index = r * imageData.cols + c;
                png::rgb_pixel pixel = imageData.data.at(index);
                string str_pixel = " " + to_string(pixel.red) + " " + to_string(pixel.green) + " " +
                                   to_string(pixel.blue) + " ";
                file << str_pixel;
                char_count += str_pixel.size();
            }
        }
        file << std::endl;

        file.close();
    }

    ImageData PpmIoStrategy::ReadFromDisk(const std::string &file_name) {
        std::ifstream file(file_name);
        std::string line;
        vector<png::rgb_pixel> pixels;
        int width, height, max_val;

        if (!file.is_open()) {
            std::cerr << "Error opening file!" << std::endl;
        }

        int line_count = 1;
        while (std::getline(file, line)) {
            if (line.empty() || line.front() == '#')
                continue;
            if (line_count == 1) {
                if (line != "P3")
                    std::cerr << "Unsupported format" << std::endl;
            }
            if (line_count == 2) {
                std::stringstream ss(line);
                ss >> width >> height;
            }
            if (line_count == 3) {
                 max_val = stoi(line);
            }
            if (line_count >= 4) {
                vector<png::rgb_pixel> pixels_of_line = getPixelsFromLine(line);
                pixels.insert(pixels.end(), pixels_of_line.begin(), pixels_of_line.end());
            }
            line_count += 1;
        }
        file.close();

        ImageData imageData;
        imageData.rows = height;
        imageData.cols = width;
        imageData.max_val = max_val;
        imageData.data = pixels;
        return imageData;
    }

    void PngIoStrategy::WriteToDisk(ImageData &imageData, const std::string &file_name) {
        int rows = imageData.rows;
        int cols = imageData.cols;
        png::image<png::rgb_pixel> image(cols, rows);
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                image[r][c] = imageData.data[r * cols + c];
            }
        }
        image.write(file_name);
    }

    ImageData PngIoStrategy::ReadFromDisk(const std::string &file_name) {
        png::image<png::rgb_pixel> png_image(file_name);
        ImageData imageData;
        imageData.max_val = Image::MAX_VALUE;
        int cols = png_image.get_width();
        int rows = png_image.get_height();
        imageData.rows = rows;
        imageData.cols = cols;

        imageData.data.resize(rows*cols);
        // Access pixel data
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int index =  r * cols + c;
                imageData.data.at(index) = png_image[r][c];
            }
        }
        return imageData;
    }
}
