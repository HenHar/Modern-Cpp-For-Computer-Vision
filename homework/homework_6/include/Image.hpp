//
// Created by hendrik on 26.06.25.
//

#ifndef IMAGE_HPP
#define IMAGE_HPP
#include <cstdint>
#include <vector>
#include <string>

namespace igg {
    class Image {
    public:
        Image();

        Image(int rows, int cols);

        int rows() const;

        int cols() const;

        int at(int row, int col) const;

        uint8_t &at(int row, int col);

        bool FillFromPgm(const std::string &file_name);

        void WriteToPgm(const std::string &file_name);

        std::vector<float> ComputeHistogram(int bins) const;

        void DownScale(int scale);

        void UpScale(int scale);

    private:
        int rows_;
        int cols_;
        std::vector<uint8_t> data_;

        uint8_t getMaxVal();

        int getIndex(int row, int col) const;
    };
} // igg

#endif //IMAGE_HPP
