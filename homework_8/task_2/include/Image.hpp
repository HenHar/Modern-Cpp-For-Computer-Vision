#ifndef IMAGE_HPP
#define IMAGE_HPP
#include <vector>
#include <memory>

#include "IoStrategies.hpp"
#include "png++/png.hpp"

namespace igg {
    class Image {
    private:
        std::shared_ptr<IoStrategy> io_strategy_ = nullptr;
        int rows_;
        int cols_;
        uint8_t max_val_;
        std::vector<png::rgb_pixel> data_;

        int getIndex(int row, int col) const;

    public:
        static const int MAX_VALUE = 255;

        Image();
        Image(int rows, int cols);
        int rows() const;
        int cols() const;
        bool ReadFromDisk(const std::string &file_name);
        bool WriteToDisk(const std::string &file_name);
        png::rgb_pixel at(int row, int col) const;
        png::rgb_pixel &at(int row, int col);
        void SetIoStrategy(std::shared_ptr<IoStrategy> strategy_ptr);
        void DownScale(int scale);
        void UpScale(int scale);
    };
} // igg
#endif //IMAGE_HPP
