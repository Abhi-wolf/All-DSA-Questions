#include <iostream>
#include <string>

/*
Create a class "Person" with a static member variable "count" that keeps track of the number of instances created.
*/

class Person
{
private:
    std::string name;
    static int count;

public:
    Person(std::string n) : name(n)
    {
        count++;
    }

    static int getCount()
    {
        return count;
    }

    std::string getName() const
    {
        return name;
    }
};

int Person::count = 0;

int main()
{
    Person person1("Alice");
    Person person2("Bob");

    std::cout << "Total Persons: " << Person::getCount() << std::endl;
    std::cout << person1.getName() << std::endl;
    std::cout << person2.getName() << std::endl;

    return 0;
}