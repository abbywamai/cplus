// Write down a program that accepts float numbers in every iteration of an infinite loop until
//  the user enters 3.14. In every iteration, this program prints the number entered and 
//  its square. 
// Note: If it is greater than 99.99 the program is broken with the exit sentence.

#include <iostream>

class NumberProcessor {
private:
    float number;

public:
    NumberProcessor() {
        number = 0.0f;
    }

    void acceptNumber() {
        while (true) {
            std::cout << "Enter a float number and enter 3.14 to exit): ";
            std::cin >> number;

            if (number == 3.14f) {
                std::cout << "Exiting program..." << std::endl;
                break;
            }

            std::cout << "Number: " << number << ", Square: " << number * number << std::endl;

            if (number * number > 99.99f) {
                std::cout << "Invalid. Square is greater than 99.99." << std::endl;
                break;
            }
        }
    }
};

int main() {
    NumberProcessor processor;
    processor.acceptNumber();
    return 0;
}
