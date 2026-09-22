
#include <iostream>
#include <string>
#include "Weekday.h"
#include "TextInput.h"

enum class Weekday;

/// <summary>
/// use Zeller’s congrunce algorithm to calculate and return a Weekday (string)
/// </summary>
/// <returns>error status code (0: success)</returns>
int main()
{
    std::cout << "Find the day of the week for: \n";

    int month{ promptForMonth() };
    int date{ promptForDayOfMonth() };
    int year{ promptForYear() };

    //std::cout << "Before Transform: yr: " << year << " month: " << month << "\n";
    if (month == 1 || month == 2) {
        month += 12;
        year--;
    }
    //adjustMonthYearNums(month, year);
    //std::cout << "\nAfter Transform: yr: " << year << " month: " << month << "\n";

    int weekdayNum{ calculateWeekdayNum(month, date, year) };
    Weekday weekdayDay{ convertWeekdayNumToDay(weekdayNum) };
    //Weekday weekdayDay{ calculateWeekday(month, date, year) };
    //std::cout << "Weekday number: " << weekdayNum << "\n";
    std::string weekdayNameString{ getWeekdayName(weekdayDay) };
    std::cout << "Weekday enum: " << weekdayNameString << "\n";
}