#include <iostream>
#include <sstream>
#include <vector>
#include <exception>
#include <cstring>

static char *strremove(char *str, const char *sub) {
    char *p, *q, *r;
    if (*sub && (q = r = strstr(str, sub)) != NULL) {
        size_t len = strlen(sub);
        while ((r = strstr(p = r + len, sub)) != NULL) {
            while (p < r)
                *q++ = *p++;
        }
        while ((*q++ = *p++) != '\0')
            continue;
    }
    return str;
}

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

class newExcptn : public std::exception
{
	virtual const char* what() const throw()
	{
		return "newExcptn occurred";
	}
} newexc;

class Quadrilateral {
protected:
    double side1, side2, side3, side4;
public:
    Quadrilateral(double s1, double s2, double s3, double s4) {
        side1 = s1;
        side2 = s2;
        side3 = s3;
        side4 = s4;
    }

    void display() {
        std::cout << "Quadrilateral with sides: " <<
                      side1 << " " << side2 << " " <<
                      side3 << " " << side4 << std::endl;
    }
};

class Trapezoid : public Quadrilateral {
public:
    Trapezoid(double s1, double s2, double s3, double s4) : 
    Quadrilateral(s1, s2, s3, s4) {};
};

class Square : public Quadrilateral {
public:
    Square(double side) : 
    Quadrilateral(side, side, side, side) {};
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

    Trapezoid t1(2, 3, 4, 5);
    Square s1(10);
    
    try 
    {
		throw newexc;
    }
	catch (std::exception& exc)
    {
		std::cout << exc.what() << std::endl;
	}

    // try catch
    std::vector<int> vect;
	vect.push_back(0);	
	vect.push_back(1);	
	// accessing third element, which is non-existence
	try
	{
		vect.at(2);		
	}
	catch (std::exception& exc)
	{
		std::cout << "Exception has occurred! " << exc.what() << std::endl;
	}

    return 0;
}