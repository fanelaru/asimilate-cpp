#include <iostream>
#include <sstream>

class Employee {
private:
    std::string name;
    double pay;
public:
    Employee() {
        name = "";
        pay = 0.0;
    }
    Employee(std::string empName, double payRate) {
        name = empName;
        pay = payRate;
    }

    const std::string getName() {
        return name;
    }

    const double getPay() {
        return pay;
    }

    const std::string toString() {
        std::stringstream stm;
        stm << name << ": " << pay;
        return stm.str();
    }

    ~Employee() {
        std::cout << "Call dtor din Employee" << std::endl;
    }
};

class Manager : public Employee {
private:
    bool salaried;
public:
    Manager(std::string name, double payRate, bool isSalaried)
    : Employee(name, payRate) {
        salaried = isSalaried;
    }

    const bool getSalaried() {
        return salaried;
    }
    ~Manager() {
        std::cout << "Call dtor din Manager" << std::endl;
    }
};

int main()
{
    Employee emp1("Fane Babanu", 2300.12);
    Employee emp2("Dana Banana", 2700.21);

    std::cout << emp1.toString() << std::endl;
    std::cout << emp2.toString() << std::endl;

    Manager manag1("Boss de boss", 5000.50, true);

    std::cout << manag1.toString() << std::endl;
    return 0;
}