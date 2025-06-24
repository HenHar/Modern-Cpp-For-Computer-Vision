#include "../include/homework_3.h"


void image_browser::AddFullRow(const image_browser::ImageRow &row, bool first_row) {
    html_writer::OpenRow();
    bool highlight = first_row;
    for (auto &scored_image_tuple : row) {
        auto [img_path, score] = scored_image_tuple;
        html_writer::AddImage(img_path, score, highlight);
        highlight = false; // only first image should be highlighted
    }
    html_writer::CloseRow();
}

void image_browser::CreateImageBrowser(const std::string& title, const std::string& stylesheet, const std::vector<ImageRow>& rows) {
    html_writer::OpenDocument();
    html_writer::AddTitle(title);
    html_writer::AddCSSStyle(stylesheet);
    html_writer::OpenBody();
    bool first_row = true;
    for (auto & row : rows) {
        AddFullRow(row, first_row);
         first_row = false;
    }

    html_writer::CloseBody();
    html_writer::CloseDocument();
}
