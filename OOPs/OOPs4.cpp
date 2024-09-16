#include <iostream>
#include <string>

/*
Create a class "Employee" with attributes name and salary. Implement overloaded operators + and - to combine
and compare employees based on their salaries.
*/

class Employee
{
private:
    std::string name;
    double salary;

public:
    Employee(std::string n, double s) : name(n), salary(s) {}

    double getSalary() const
    {
        return salary;
    }

    bool operator<(const Employee &other) const
    {
        return salary < other.salary;
    }

    bool operator>(const Employee &other) const
    {
        return salary > other.salary;
    }

    Employee operator+(const Employee &other) const
    {
        return Employee("Combined", salary + other.salary);
    }

    Employee operator-(const Employee &other) const
    {
        return Employee("Difference", salary - other.salary);
    }
};

int main()
{
    Employee emp1("Alice", 5000);
    Employee emp2("Bob", 6000);

    if (emp1 < emp2)
    {
        std::cout << "Bob has a higher salary than Alice." << std::endl;
    }
    else
    {
        std::cout << "Alice has a higher salary than Bob." << std::endl;
    }

    Employee combined = emp1 + emp2;
    std::cout << "Combined Salary: " << combined.getSalary() << std::endl;

    Employee difference = emp1 - emp2;
    std::cout << "Salary Difference: " << difference.getSalary() << std::endl;

    return 0;
}