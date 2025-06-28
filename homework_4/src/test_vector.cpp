#include "homework_4.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
    ipb::named_vector<string> strings = {"strings", {"t", "rh"}};
    strings.push_back("hello");
    std::cout << "Added new string. Size of vector: " << strings.size() << endl;
    strings.push_back("how are you");
    std::cout << "Added new string. Size of vector: " << strings.size() << endl;
    strings.push_back("my name is hendrik");
    std::cout << "Added new string. Size of vector: " << strings.size() << endl;
    strings.push_back("whats your name?");
    std::cout << "Added new string. Size of vector: " << strings.size() << endl;

    for (int i = 0; i < strings.size(); i++) {
        cout << strings[i] << endl;
    }
    return 0;
}