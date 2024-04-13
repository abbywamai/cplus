// classes include: employee ,course and client
#include <iostream>
#include <vector>
#include <string>

class Employee {
protected:
    std::string name;
    int id;
    std::string department;

public:
    Employee(std::string name, int id, std::string department) {
        this->name = name;
        this->id = id;
        this->department = department;
    }

    virtual ~Employee() {}

    virtual void displayInfo() const {
        std::cout << "Name: " << name << ", ID: " << id << ", Department: " << department << std::endl;
    }
};

class Accountant : public Employee {
public:
    Accountant(std::string name, int id) : Employee(name, id, "Accounting") {}
};

class Programmer : public Employee {
public:
    Programmer(std::string name, int id) : Employee(name, id, "Programming") {}
};

class SystemsAnalyst : public Employee {
public:
    SystemsAnalyst(std::string name, int id) : Employee(name, id, "Systems Analysis") {}
};

class Course {
private:
    std::string name;
    std::string enrollmentTime;
    double feesPaid;
    double scores;

public:
    Course(std::string name, std::string enrollmentTime, double feesPaid, double scores) {
        this->name = name;
        this->enrollmentTime = enrollmentTime;
        this->feesPaid = feesPaid;
        this->scores = scores;
    }

    ~Course() {}

    void displayInfo() const {
        std::cout << "Course: " << name << ", Enrollment Time: " << enrollmentTime
                  << ", Fees Paid: " << feesPaid << ", Scores: " << scores << std::endl;
    }
};

class Client {
private:
    std::string name;

public:
    Client(std::string name) {
        this->name = name;
    }

    ~Client() {}

    void displayInfo() const {
        std::cout << "Client Name: " << name << std::endl;
    }
};

class Student : public Employee {
private:
    Client employer;
    Course courseDetails;

public:
    Student(std::string name, int id, std::string employerName, std::string courseName,
            std::string enrollmentTime, double feesPaid, double scores)
        : Employee(name, id, "Student"), employer(employerName), courseDetails(courseName, enrollmentTime, feesPaid, scores) {}

    void displayInfo() const {
        Employee::displayInfo();
        employer.displayInfo();
        courseDetails.displayInfo();
    }
};

int main() {
    Accountant acc("Alice Kimanzi", 101);
    Programmer prog("Samuel Gishaga", 102);
    SystemsAnalyst analyst("Abigail Muthoni", 103);

    Student student("Wango Wamai", 201, "Uon ", "OOP 101", "2024-04-01", 100000.0, 85.5);

    std::vector<Employee *> employees;
    employees.push_back(&acc);
    employees.push_back(&prog);
    employees.push_back(&analyst);
    employees.push_back(&student);

    for (const auto &emp : employees) {
        emp->displayInfo();
    }

    return 0;
}
