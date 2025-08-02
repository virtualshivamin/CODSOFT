#include <iostream>
#include <cstdlib>   
#include <ctime>     
using namespace std;

int main() {
    
    srand(static_cast<unsigned int>(time(nullptr)));

    // I have given a range of random guessing number from 1 to 100 only.
    int secretNumber = rand() % 100 + 1;
    int userGuess;

    cout << "Guess the number (between 1 and 100): ";

    // Loop will terminate if number guessed 
    while (true) {
        cin >> userGuess;

        if (userGuess < secretNumber) {
            cout << "Too low. Try again: ";
        } else if (userGuess > secretNumber) {
            cout << "Too high. Try again: ";
        } else {
            cout << "Congratulations! You guessed the correct number: " << secretNumber << endl;
            break;
        }
    }

    return 0;
}
