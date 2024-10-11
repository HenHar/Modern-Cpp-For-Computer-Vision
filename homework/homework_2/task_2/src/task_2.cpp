#include <iostream>
#include <sstream>
#include <vector>
 #include <set>

using namespace std;

std::vector<std::string> splitString (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

int main( int argc,      // Number of strings in array argv
          char *argv[])  // Array of command-line argument strings
{
    int inputArguments = 2;
    set<string> allowedExtension = { "txt", "png" };

    // check if num of arguments == #inputArguments. First argument is name of file.
    if (argc - 1 != inputArguments) {
        cerr << "Only two arguments allowd." << endl;
        exit(EXIT_FAILURE);
    }
    
    
    // preprocess input
    string extension[inputArguments];
    int values[inputArguments];
    char delimiter = '.';
    for(int count = 1; count < argc; count++) {
        vector<string> substrings = splitString(argv[count], delimiter);

        try{
            values[count-1] = stoi(substrings[0]);
            extension[count-1] = substrings[1];
        }
        catch(exception &err)
        {
            cerr << "Problem" << endl;
            exit(EXIT_FAILURE);
        }        
    }

    // process input
    double result;
    if (extension[0] == "txt" && extension[1] == "txt")
        result = (values[0] + values[1]) / inputArguments;
    else if (extension[0] == "png" && extension[1] == "png")
        result = values[0] + values[1];
    else if (extension[0] == "txt" && extension[1] == "png")
        result = values[0] % values[1];
    else {
        cerr << "File extension not allowed." << endl;
        exit(EXIT_FAILURE);
    }

    cout << result << endl;
    exit(EXIT_SUCCESS);
}