#include <random>
#include <iostream>
#include <stdlib.h>  

using namespace std;

int main() {
     // Define range
    int min = 0;
    int max = 99;

    // Initialize a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);

    // Generate random number in the range [min, max]
    int randomValue = distrib(gen);
    int guess;
    
    
    do  {
        cout << "Please enter your guess: \n";
        cin >> guess;

        if (!cin.fail()) {
            if (guess < 0 || guess > 99) {
                cerr << "[WARNING] : Number must be between 0 and 99" << endl;
                continue;
            }

            if (guess > randomValue) {
                cout << "The value is smaller" << endl;
            }
            if (guess < randomValue) {
                cout << "The value is bigger" << endl;
            }
        }
        else {
            cerr << "Error encountered, exiting...\n";
            cout << randomValue;
            exit(EXIT_FAILURE);
        }
    } while (guess != randomValue);

    cout << "You have correctly guessed the number: " << randomValue << endl;
    
    exit(EXIT_SUCCESS);
}


