//
// Created by hendrik on 26.06.25.
//

#include "../include/Image.hpp"
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

    void Image::DownScale(int scale) {
        std::vector<uint8_t> scaled_data;
        int new_rows_ = (int)rows_ / scale;
        int new_cols_ = (int)cols_ / scale;

        for (int r = 0; r < rows_; r += scale) {
            for (int c = 0; c < cols_; c += scale) {
                scaled_data.push_back(data_[getIndex(r, c)]);
            }
        }

        rows_ = (int)rows_ / scale;
        cols_ = (int)cols_ / scale;
        data_ = scaled_data;
    }

    void Image::UpScale(int scale) {
        int new_rows = (int)rows_ * scale;
        int new_cols = (int)cols_ * scale;
        std::vector<uint8_t> scaled_data(new_rows * new_cols);

        for (int r = 0; r < new_rows; r++) {
            for (int c = 0; c < new_cols; c++) {
                int old_row = r / scale; // integer division
                int old_col = c / scale;
                scaled_data[r * new_cols + c] = data_[old_row * cols_ + old_col];
            }
        }
        rows_ = new_rows;
        cols_ = new_cols;
        data_ = scaled_data;
    }


    bool Image::FillFromPgm(const std::string &file_name) {
        io_tools::ImageData image_data = io_tools::ReadFromPgm(file_name);
        rows_ = image_data.rows;
        cols_ = image_data.cols;
        data_ = image_data.data;

        return true;
    }

    void Image::WriteToPgm(const std::string &file_name) {
        io_tools::ImageData image_data = {rows_, cols_, 255, data_};
        io_tools::WriteToPgm(image_data, file_name);
    }

    std::vector<float> Image::ComputeHistogram(int bins) const {
        std::vector<int> histogram(bins, 0);
        int max_value = 255;
        int total_pixel = rows_ * cols_;

        if (total_pixel == 0) {
            return std::vector<float>(bins, 0.0f); // Return empty histogram
        }

        for (const auto &pixel_value : data_) {
            int bin =  std::ceil(pixel_value * bins / max_value);
            bin = std::min(bin, bins - 1);
            histogram[bin]++;
        }

        std::vector<float> histogram_f;
        for (const int &num_pixels: histogram) {
            histogram_f.push_back(static_cast<float>(num_pixels) / static_cast<float>(total_pixel));
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
        return *max_it;
    }
} // igg
