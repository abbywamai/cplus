#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int marks;

public:
    Student() {
        name = "";
        marks = 0;
    }

    void inputDetails() {
        std::cout << "Enter your name: ";
        std::cin >> name;

        do {
            std::cout << "Enter marks (between 0 and 10): ";
            std::cin >> marks;
        } while (marks < 0 || marks > 10);
    }

    void printMessage() {
        std::cout << "Hello, " << name << "! ";

        if (marks < 5)
            std::cout << "Cheer up! Life is great." << std::endl;
        else if (marks >= 5 && marks < 7)
            std::cout << "It is okay." << std::endl;
        else if (marks >= 7 && marks < 10)
            std::cout << "That’s awesome." << std::endl;
    }
};

int main() {
    Student student;
    student.inputDetails();
    student.printMessage();
    return 0;
}
