#ifndef HOMEWORK8_IOSTRATEGIES_HPP
#define HOMEWORK8_IOSTRATEGIES_HPP

#include <png++/png.hpp>

namespace igg {
    struct ImageData {
        int rows;
        int cols;
        int max_val;
        std::vector<png::rgb_pixel> data;
    };

    class IoStrategy {
    public:
        virtual void WriteToDisk(ImageData &data, const std::string &file_name) = 0;
        virtual ImageData ReadFromDisk(const std::string &file_name) = 0;
    };

    class PngIoStrategy : public IoStrategy{
    public:
        void WriteToDisk(ImageData &data, const std::string &file_name) override;
        ImageData ReadFromDisk(const std::string &file_name)  override;
    };

    class PpmIoStrategy : public IoStrategy {
    public:
        void WriteToDisk(ImageData &data, const std::string &file_name) override;
        ImageData ReadFromDisk(const std::string &file_name) override;
    };
}


#endif //HOMEWORK8_IOSTRATEGIES_HPP