#include <iostream>
#include <string>

class DivisibilityTester {
private:
    int number;
    bool results[11]; 

public:
    DivisibilityTester(int num) : number(num) {
        performTests();
    }

    void performTests() {
        results[2] = (number & 1) == 0; 
        results[3] = (sumOfDigitsDivisibleBy(number, 3));
        results[4] = (endsWithMultipleOf(number, 4, 100));
        results[5] = (number % 10 == 0 || number % 5 == 0); 
        results[6] = (results[2] && results[3]);
        results[7] = (isDivisibleBy7(number));
        results[8] = (endsWithMultipleOf(number, 8, 1000));
        results[9] = (sumOfDigitsDivisibleBy(number, 9));
        results[10] = (number % 10 == 0); 
        results[25] = (number % 25 == 0);
    }

    bool sumOfDigitsDivisibleBy(int num, int divisor) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return (sum % divisor == 0);
    }

    bool endsWithMultipleOf(int num, int divisor, int limit) {
        if (num < limit)
            return (num % divisor == 0);
        return ((num / divisor) % 10 == 0);
    }

    bool isDivisibleBy7(int num) {
        int lastDigit = num % 10;
        num /= 10;
        int difference = num - 2 * lastDigit;
        return (difference == 0 || difference % 7 == 0);
    }

    void displayResults() {
        std::cout << "Number: " << number << std::endl;
        for (int i = 2; i <= 10; ++i) {
            if (results[i])
                std::cout << "Divisible by " << i << std::endl;
            else
                std::cout << "Not divisible by " << i << std::endl;
        }
        if (results[25])
            std::cout << "Divisible by 25" << std::endl;
        else
            std::cout << "Not divisible by 25" << std::endl;
    }
};

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    DivisibilityTester tester(num);
    tester.displayResults();

    return 0;
}
