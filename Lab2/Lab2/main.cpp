
#include <iostream>

enum class Weekday { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

#include "dates.h"
#include "TextInput.h"
#include <string>

// use Zeller’s congrunce algorithm to calculate and return a Weekday
Weekday calculateWeekday(int month, int dayOfMonth, int year);

//Get enum string from enum number
std::string getWeekdayName(Weekday day);

int main()
{
    std::cout << "Find the day of the week for: \n";

    int month{ promptForMonth() };
    int date{ promptForDayOfMonth() };
    int year{ promptForYear() };

    int weekdayNum{ calculateWeekdayNum(month, date, year) };
    Weekday weekdayDay{ calculateWeekday(month, date, year) };
    std::cout << weekdayNum << "\n";
    //std::cout << weekdayDay;
    //Weekday weekDay{ calculateWeekday( promptForMonth(), promptForDayOfMonth(), promptForYear() ) };

}

int promptForYear() { return promptUserForInt("Year: "); }

int promptForMonth() { return promptUserForInt("Month (number): "); }

int promptForDayOfMonth() { return promptUserForInt("Day of the Month (number): "); }

void adjustMonthYearNums(int month, int year) {
    if (month == 01 || month == 02) {
        month += 12;
        year -= 1;
    } //will this adjust the variable after the function call? Test
}

int calculateWeekdayNum(int month, int dayOfMonth, int year) {
    // Zeller's congruence - to calc day of the week
    // h = (q + 26(m+1)/10 + k + k/4 + j/4 + 5j) % 7
    // 
    // h = dayOfWeekNum : 0=sat, 1=sun, 2=mon, 3=tues, 4=wed, 5=thur, 6=friday
    // q = dayOfMonth
    // m = monthNum... monthNum EXCEPT jan = 13, feb = 14 OF PREV YEAR
    // j = century ( integer division: year/100 )
    // k = yearOfCentury ( year % 100 )


    int century{ year / 100 };
    int yearOfCentury{ year % 100 };
    adjustMonthYearNums(month, year);
    int monthNum{ month };
    int monthNumCalculation{ (26 * (monthNum + 1)) / (10) }; //not sure what to call this - this is or represents - working on it

    int dayOfYearNum = (dayOfMonth + monthNumCalculation +
        yearOfCentury + yearOfCentury / 4 + century / 4 + 5 * century);
    int dayOfWeekNum = dayOfYearNum % 7;

    return dayOfWeekNum;
}

Weekday calculateWeekday(int month, int dayOfMonth, int year) {
    int weekdayNum = calculateWeekdayNum(month, dayOfMonth, year);
    using enum Weekday;
    Weekday weekdayEnum{ weekdayNum };
    return weekdayEnum;

    std::string weekdayList[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
}

//std::string getWeekdayName(Weekday day) {
    //using enum Weekday; //brings enumerators into the current scope
    //Weekday variableName{ value1 };
//}

// There isn’t a straightforward way of printing out the text representation of an
// enumerated type,so we’ll write our own
// Given a Weekday, return a string to represent its name.
// You can do this in several ways:
// 1. multiple if/else if statements
// 2. a switch statement
// 3. create an array of string literals, and index the array by
// doing a static_cast on the Weekday to get its int representation.
// 
//The third option is the best(most elegant / extensible).
//To do this, you need to know how to create an array of string objects(see
//    below) :
//eg: std::string myArray[] = { "a", "b", “c” };.