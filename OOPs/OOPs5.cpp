#include <iostream>

/*
Create a class "Time" with attributes hours and minutes. Implement the << operator to display time in the format "hh:mm".
*/

class Time
{
private:
    int hours;
    int minutes;

public:
    Time(int h, int m) : hours(h), minutes(m) {}

    friend std::ostream &operator<<(std::ostream &os, const Time &time)
    {
        os << time.hours << ":" << (time.minutes < 10 ? "0" : "") << time.minutes;
        return os;
    }
};

int main()
{
    Time time(14, 30);
    std::cout << "Time: " << time << std::endl;

    return 0;
}