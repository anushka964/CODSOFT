#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Providing a seed value
    srand(static_cast<unsigned>(time(NULL)));

    // Get a random number
    int random = rand();
    int secretNumber, num;

    cout << "Press 1 to start and -1 to exit: " << endl;
    cin >> num;

    while (num != -1) {
        cout << "Guess the secret number: ";
        cin >> secretNumber;

        if (secretNumber == random) {
            cout << "WOHOO! You are absolutely right. The secret number is: " << random << endl;
            break; // Exit the loop when the correct number is guessed
        } else if (secretNumber < random) {
            cout << "Number is lower than the secret number. Try Again!" << endl;
        } else {
            cout << "Number is greater than the secret number. Try Again!" << endl;
        }

        cout << "Hint: The secret number is in the range of [" << random - 10 << ", " << random + 10 << "]." << endl;
        cout << "Press 1 to continue guessing or -1 to exit: ";
        cin >> num;
    }

    return 0;
}

