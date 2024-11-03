#include "../include/libs.hpp"

int main() {
    std::vector<image_browser::ImageRow> rows;

    image_browser::ScoredImage image11 = {"../web_app/data/000000.png", 0.98};
    image_browser::ScoredImage image12 = {"./web_app/data/000100.png", 0.96};
    image_browser::ScoredImage image13 = {"./web_app/data/000200.png", 0.88};
    image_browser::ImageRow imageRow1 = {image11, image12, image13};
    rows.push_back(imageRow1);

    image_browser::ScoredImage image21 = {"./web_app/data/000300.png", 0.87};
    image_browser::ScoredImage image22 = {"./web_app/data/000400.png", 0.80};
    image_browser::ScoredImage image23 = {"./web_app/data/000500.png", 0.77};
    image_browser::ImageRow imageRow2 = {image21, image22, image23};
    rows.push_back(imageRow2);

    image_browser::ScoredImage image31 = {"./web_app/data/000600.png", 0.67};
    image_browser::ScoredImage image32 = {"./web_app/data/000700.png", 0.45};
    image_browser::ScoredImage image33 = {"./web_app/data/000800.png", 0.23};
    image_browser::ImageRow imageRow3 = {image31, image32, image33};
    rows.push_back(imageRow3);

    image_browser::CreateImageBrowser("Image Browser", "./web_app/style.css", rows);


    return 0;
}