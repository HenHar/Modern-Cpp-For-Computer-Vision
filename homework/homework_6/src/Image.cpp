//
// Created by hendrik on 26.06.25.
//

#include "Image.hpp"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>

#include "io_tools.hpp"
#include <iostream>


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

    int Image::getIndex(int row, int col) {
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
