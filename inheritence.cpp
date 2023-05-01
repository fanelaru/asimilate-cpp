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

class Account {
protected:
    double balance;

public:
    Account(double bal) {
        if(bal > 0) {
            balance = bal;
        }
        else 
            bal = 0.0;
    }

    void credit(double amount) {
        std::cout << "credit Account" << std::endl;
        balance += amount;
    }

    void debit(double amount) {
        if (balance > amount) {
            balance = balance - amount;
        }
        else {
            std::cout << "Fonduri insuficiente" << std::endl;
        }
    }

    double getBalance() {
        return balance;
    }
};

class CheckingAccount : public Account {
private:
    double fee;

public:
        CheckingAccount(double bal, double f) : Account (bal) { 
            fee = f;
            std::cout << "ctor CheckingAccount" << std::endl;
        }
        void debit(double amount) {
            if(balance > amount) 
                balance = balance - amount - fee;
            else
                std::cout << "Insufficient funds" << std::endl;
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

    std::cout << "Asta e de test" << std::endl;

    CheckingAccount myacct(500, .5);
    std::cout << myacct.getBalance() << std::endl;
    myacct.debit(50);
    std::cout << myacct.getBalance() << std::endl;
    myacct.credit(150);
    return 0;
}