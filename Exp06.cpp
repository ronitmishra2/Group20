#include <iostream>

class Date {
private:
    int day, month, year;

    // Helper function to determine if a year is a leap year
    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    // Helper function to determine the number of days in a given month
    int daysInMonth(int m, int y) const {
        if (m == 2) {
            return isLeapYear(y) ? 29 : 28;
        }
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        }
        return 31;
    }

public:
    // Constructor
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Relational operators
    bool operator<(const Date& other) const {
        return (year < other.year) ||
               (year == other.year && month < other.month) ||
               (year == other.year && month == other.month && day < other.day);
    }

    bool operator<=(const Date& other) const {
        return *this < other || *this == other;
    }

    bool operator>(const Date& other) const {
        return !(*this <= other);
    }

    bool operator>=(const Date& other) const {
        return !(*this < other);
    }

    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    bool operator!=(const Date& other) const {
        return !(*this == other);
    }

    // Increment operator
    Date& operator++() {
        day++;
        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return *this;
    }

    // Addition operator to add days
    Date operator+(int daysToAdd) const {
        Date result = *this;
        result.day += daysToAdd;
        while (result.day > result.daysInMonth(result.month, result.year)) {
            result.day -= result.daysInMonth(result.month, result.year);
            result.month++;
            if (result.month > 12) {
                result.month = 1;
                result.year++;
            }
        }
        return result;
    }

    // Conversion to int to calculate the number of days elapsed in the current year
    operator int() const {
        int daysElapsed = day;
        for (int i = 1; i < month; ++i) {
            daysElapsed += daysInMonth(i, year);
        }
        return daysElapsed;
    }

    // Function to display the date
    void display() const {
        std::cout << day << "/" << month << "/" << year << std::endl;
    }
};

int main() {
    Date dt(10, 8, 2024);

    // Relational operators
    Date dt2(11, 8, 2024);
    if (dt < dt2) std::cout << "dt is less than dt2" << std::endl;

    // Increment operator
    ++dt;
    dt.display(); // Should print 11/8/2024

    // Addition operator
    Date newDate = dt + 5;
    newDate.display(); // Should print 16/8/2024

    // Conversion to int (days elapsed in the current year)
    int daysElapsed = dt;
    std::cout << "Days elapsed in the current year: " << daysElapsed << std::endl;

    return 0;
}
