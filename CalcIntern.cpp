#include <iostream>
#include <stdexcept>
using namespace std;

void sum(int n1, int n2) {
    cout << "Sum of your given two numbers is: " << n1 + n2 << endl;
}

void multiply(int n1, int n2) {
    cout << "Product of numbers is: " << n1 * n2 << endl;
}

void subtract(int n1, int n2) {
    cout << "Difference of two given numbers is: " << n1 - n2 << endl;
}

void divide(int n1, int n2) {
    if (n2 == 0) {
        throw runtime_error("Cannot divide by zero!");
    }
    cout << "Division of two given numbers is: " << static_cast<double>(n1) / n2 << endl;
}

int main() {
    int num1, num2, oper;

    do {
        cout << "Enter two numbers. " << endl;
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        cout << "Choose an operation to be performed:\n press 1 for addition. \n press 2 for multiply. \n press 3 for subtraction.\n press 4 for division.\n press 0 to exit.  " << endl;
        cin >> oper;

        try {
            switch (oper) {
            case 1:
                sum(num1, num2);
                break;
            case 2:
                multiply(num1, num2);
                break;
            case 3:
                subtract(num1, num2);
                break;
            case 4:
                divide(num1, num2);
                break;
            case 0:
                cout << "Thankyou for using me! Come again later" << endl;
                break;
            default:
                cout << "OOPS! Wrong operation chosen. Try Again." << endl;
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }

    } while (oper != 0);

    return 0;
}

