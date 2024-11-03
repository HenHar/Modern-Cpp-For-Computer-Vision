#include <iostream>
#include <string>
#include <filesystem>

#include "../include/libs.hpp"

using std::cout;
using std::endl;


void html_writer::OpenDocument() {
    cout << "<!DOCTYPE html>" << endl;;
    cout << "<html>" << endl;
}

void html_writer::CloseDocument() {
   cout << "</html>";
}

void html_writer::AddTitle(const std::string& title) {
    std::string title_line = "<title>" + title + "</title>";
    cout << title_line << endl;;
}

void html_writer::AddCSSStyle(const std::string& stylesheet) {
    cout << "<head>" << endl;
    cout << "<link rel=\"stylesheet\" type=\"text/css\" href=" + stylesheet + " />" << endl;
    cout << "</head>" << endl;
}

void html_writer::OpenBody() {
    cout << "<body>" << endl;
}

void html_writer::CloseBody() {
    cout << "</body>" << endl;
}

void html_writer::OpenRow() {
    cout << "<div class=\"row\">" << endl;
}

void html_writer::CloseRow() {
    cout << "</div>" << endl;
}

void html_writer::AddImage(const std::string& img_path, float score, bool highlight) {
    // split the img file name
    std::filesystem::path fs_img_path{img_path};
    if (!std::filesystem::exists(fs_img_path)) {
        std::cerr << "[ERROR] : Image " << fs_img_path << " does not exist\n";
        exit(EXIT_FAILURE);
    }
    std::string img_filename = fs_img_path.filename();

    // determine the file format
    if (img_filename.find("jpg") == std::string::npos &&
        img_filename.find("png") == std::string::npos) {
        std::cerr << "[ERROR] : Unsupported image format\n";
    }

    // highlithing entry
    std::string column_line = "<div class=\"column\">" ;
    if (highlight == true)
        column_line = "<div class=\"column\" style=\"border: 5px solid green;\">";

    // print HTML line by line 
    cout << column_line << endl;
    cout << "<h2>" + img_filename + "<h2>" << endl;
    cout << "<img src=" + img_path + "/>" << endl;
    cout << "<p>score = " << score <<  "</p>" << endl;
    cout << "</div>" << endl;
}
