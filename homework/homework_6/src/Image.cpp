//
// Created by hendrik on 26.06.25.
//

#include "Image.hpp"
#include <vector>
#include <algorithm>
#include <catch2/catch_test_macros.hpp>

#include "io_tools.hpp"
#include <iostream>
#include <cmath>


namespace igg {
    Image::Image() {
        rows_ = 0;
        cols_ = 0;
    }

    Image::Image(const int rows, const int cols) {
        rows_ = rows;
        cols_ = cols;
        data_.resize(rows * cols);
    }

    int Image::cols() const {
        return cols_;
    }

    int Image::rows() const {
        return rows_;
    }

    int Image::at(const int row, const int col) const {
        const int index = row * cols_ + col;
        return data_[index];
    }

    uint8_t &Image::at(int row, int col) {
        int index = getIndex(row, col);
        return data_[index];
    }


    bool Image::FillFromPgm(const std::string &file_name) {
        io_tools::ImageData image_data = io_tools::ReadFromPgm(file_name);
        if (image_data.rows == 0 || image_data.cols == 0)
            return false;

        std::cout << image_data.max_val << std::endl;
        rows_ = image_data.rows;
        cols_ = image_data.cols;
        data_ = image_data.data;

        std::cout << data_.size() << std::endl;
        return true;
    }

    void Image::WriteToPgm(const std::string &file_name) {
        io_tools::ImageData image_data = {rows_, cols_, 255, data_};
        std::cout << image_data.data.size() << std::endl;
        bool success = io_tools::WriteToPgm(image_data, file_name);
        if (success) std::cout << "Success" << std::endl;
        else std::cout << "Failed" << std::endl;
    }

    std::vector<float> Image::ComputeHistogram(int bins) {
        std::vector<int> histogram(bins, 0);
        int max_value = 255;
        int total_pixel = rows_ * cols_;

        for (const auto &pixel_value : data_) {
            int bin =  std::ceil(pixel_value * bins / max_value);
            bin = std::min(bin, bins - 1);
            histogram[bin]++;
        }

        std::vector<float> histogram_f;
        for (const int &num_pixels: histogram) {
            histogram_f.push_back(static_cast<float>(num_pixels) / total_pixel);
        }

        return histogram_f;
    }


    int Image::getIndex(int row, int col) const {
        return row * cols_ + col;
    }

    uint8_t Image::getMaxVal() {
        if (data_.empty()) {
            return 0; // or handle empty case as needed
        }

        auto max_it = std::max_element(data_.begin(), data_.end());
        std::cout << static_cast<int>(*max_it) << std::endl;
        return *max_it;
    }



} // igg
