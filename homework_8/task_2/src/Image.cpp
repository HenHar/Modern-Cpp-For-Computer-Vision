#include "Image.hpp"
#include <vector>
#include <algorithm>
#include <catch2/catch_test_macros.hpp>

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

    void Image::SetIoStrategy(std::shared_ptr<IoStrategy> strategy_ptr) {
        this->io_strategy_ = strategy_ptr;
    }

    bool Image::ReadFromDisk(const std::string &file_name) {
        // Check if io_strategy is set
        if (io_strategy_) {
            // read image
            ImageData img_data = io_strategy_->ReadFromDisk(file_name);
            // set image data
            this->rows_ = img_data.rows;
            this->cols_ = img_data.cols;
            this->max_val_ = img_data.max_val;
            this->data_ = img_data.data;
            return true;
        }
        // throw error if io_strategy is not set
        std::cerr << "Io Strategy not Set" << std::endl;
        exit(1);
    }

    bool Image::WriteToDisk(const std::string &file_name) {
        if (io_strategy_) {
            ImageData imageData;
            imageData.rows = this->rows_;
            imageData.cols = this->cols_;
            imageData.max_val = this->max_val_;
            imageData.data = this->data_;
            io_strategy_->WriteToDisk(imageData, file_name);
            return true;
        }
        // throw error if io_strategy is not set
        std::cerr << "Io Strategy Not Set" << std::endl;
        exit(1);

    }

    int Image::cols() const {
        return cols_;
    }

    int Image::rows() const {
        return rows_;
    }

    png::rgb_pixel Image::at(const int row, const int col) const {
        const int index = getIndex(row, col);
        return data_[index];
    }

    png::rgb_pixel &Image::at(int row, int col) {
        int index = getIndex(row, col);
        return data_[index];
    }

    void Image::DownScale(int scale) {
        std::vector<png::rgb_pixel> scaled_data;
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
        int new_rows = rows_ * scale;
        int new_cols = cols_ * scale;
        std::vector<png::rgb_pixel> scaled_data(new_rows * new_cols);

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

    int Image::getIndex(int row, int col) const {
        return row * cols_ + col;
    }
} // igg
