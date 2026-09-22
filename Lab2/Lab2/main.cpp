
#include <iostream>
#include <string>
#include "dates.h"
#include "TextInput.h"

enum class Weekday;

//// use Zeller’s congrunce algorithm to calculate and return a Weekday
//Weekday calculateWeekday(int month, int dayOfMonth, int year);
////Get enum string from enum number
//std::string getWeekdayName(Weekday day);

int main()
{
    std::cout << "Find the day of the week for: \n";

    int month{ promptForMonth() };
    int date{ promptForDayOfMonth() };
    int year{ promptForYear() };

    std::cout << "Before Transform: yr: " << year << " month: " << month << "\n";
    if (month == 1 || month == 2) {
        month += 12;
        year--;
    }
    //adjustMonthYearNums(month, year);
    std::cout << "\nAfter Transform: yr: " << year << " month: " << month << "\n";

    int weekdayNum{ calculateWeekdayNum(month, date, year) };
    Weekday weekdayDay{ convertWeekdayNumToDay(weekdayNum) };
    //Weekday weekdayDay{ calculateWeekday(month, date, year) };
    //std::cout << "Weekday number: " << weekdayNum << "\n";
    std::string weekdayNameString{ getWeekdayName(weekdayDay) };
    std::cout << "Weekday enum: " << weekdayNameString << "\n";
}