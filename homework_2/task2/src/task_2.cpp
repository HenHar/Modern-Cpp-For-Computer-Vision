#include  <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

std::vector<std::string> splitString (const std::string &s, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delimiter)) {
        result.push_back (item);
    }

    return result;
}



int main(int argc,  char *argv[]) {
    int requiredInputArguments = 2;
    if (argc - 1 != requiredInputArguments ) {
        std::cerr << "Two arguments as input needed." << std::endl;
        exit(EXIT_FAILURE);
    }

    // preprocess input arguments
    vector<int> inputValues;
    vector<string> extensionTypes;
    for (int i = 1; i < argc; i++) {
        try {
            char delimiter = '.';
            vector<string> splittedString = splitString(argv[i], delimiter);
            inputValues.push_back(stoi(splittedString[0]));
            extensionTypes.push_back(splittedString[1]);

        }    catch(exception &err) {
            cerr << "Error: " << err.what() << endl;
            exit(EXIT_FAILURE);
        }
    }

    // process input arguments
    double result;
    if (extensionTypes[0] == "txt" && extensionTypes[1] == "txt")
        result = (inputValues[0] + inputValues[1]) / requiredInputArguments;
    else if (extensionTypes[0] == "png" && extensionTypes[1] == "png")
        result = inputValues[0] + inputValues[1];
    else if (extensionTypes[0] == "txt" && extensionTypes[1] == "png")
        result = inputValues[0] % inputValues[1];
    else {
        cerr << "File extension not allowed." << endl;
        exit(EXIT_FAILURE);
    }

    cout << result << endl;
    exit(EXIT_SUCCESS);

}