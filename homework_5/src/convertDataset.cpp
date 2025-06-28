#include "homework_5.h"
#include <opencv2/opencv.hpp>
#include <filesystem>

cv::Mat calculateSIFT(const std::filesystem::path& img_path) {
    cv::Mat image = cv::imread(img_path.string(), cv::IMREAD_COLOR);

    const cv::Ptr<cv::SIFT> sift = cv::SIFT::create();
    std::vector<cv::KeyPoint> keypoints;
    cv::Mat descriptors;
    sift->detectAndCompute(image, cv::noArray(), keypoints, descriptors);

    return descriptors;
}

void ipb::serialization::sifts::ConvertDataset(const std::filesystem::path& img_path) {
    std::filesystem::path bin_dir = img_path.parent_path().parent_path() / "bin";

    if (!std::filesystem::exists(bin_dir)) {
        std::filesystem::create_directory(bin_dir);
    }

    for (const auto& entry : std::filesystem::directory_iterator(img_path)) {
        if (entry.path().extension() == ".png") {
            std::cout << entry.path().filename() << std::endl;
            cv::Mat descriptors = calculateSIFT(entry.path());
            std::string binary_save_path = bin_dir / entry.path().filename();
            ipb::serialization::Serialize(descriptors, binary_save_path);
        }
    }
}


std::vector<cv::Mat> ipb::serialization::sifts::LoadDataset(const std::filesystem::path& bin_path) {
    std::vector<cv::Mat> descriptors;
    for (const auto &entry: std::filesystem::directory_iterator(bin_path)) {
        if (entry.path().extension() == ".bin") {
            cv::Mat descriptor = ipb::serialization::Deserialize(entry.path().string());
            descriptors.push_back(descriptor);
        }
    }
    return descriptors;
}
