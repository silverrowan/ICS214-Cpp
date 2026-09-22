#include <iostream>
#include <string>
#include "TextInput.h"
#include "Weekday.h"

int promptForYear() { return promptUserForIntInRange("Year: ", 0, 9999); }

int promptForMonth() { return promptUserForIntInRange("Month (number): ", 1, 12); }

int promptForDayOfMonth() { return promptUserForIntInRange("Day of the Month (number): ", 1, 31); }

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
    int monthNum{ month };
    int monthNumCalculation{ (26 * (monthNum + 1)) / (10) }; //not sure what to call this - this is or represents - working on it

    int dayOfYearNum = (dayOfMonth + monthNumCalculation +
        yearOfCentury + yearOfCentury / 4 + century / 4 + 5 * century);
    int dayOfWeekNum = dayOfYearNum % 7;

    return dayOfWeekNum;
}

std::array<int, 0> convertMonthsToZellers(int month, int dayOfMonth, int year) {
    std::array dateArray{ [month, dayOfMonth, year] };
    if (month == 1 || month == 2) {
        month += 12;
        year--;
    }
}

Weekday convertWeekdayNumToDay(int dayNum) {
    switch ( dayNum ) {
        case 0: return Weekday::Saturday;
        case 1: return Weekday::Sunday;
        case 2: return Weekday::Monday;
        case 3: return Weekday::Tuesday;
        case 4: return Weekday::Wednesday;
        case 5: return Weekday::Thursday;
        case 6: return Weekday::Friday;
        default:
            std::cout << "Invalid weekday value, number must be 0-6, inclusive";
            // return void;
            // better error handling would be nice, how to return error/nothing?
    }
}

Weekday calculateWeekday(int month, int dayOfMonth, int year) {
    int weekdayNum = calculateWeekdayNum(month, dayOfMonth, year);
    return convertWeekdayNumToDay(weekdayNum);
    //using enum Weekday;
    //Weekday weekdayEnum{ weekdayNum };
    //return weekdayEnum;
}

std::string getWeekdayName(Weekday day) {
    // if we're writing our own way to output a string, what is the point of the enum class?
    // we seem to be bypassing it...
    std::string weekdayList[] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
    return weekdayList[static_cast<int>(day)];
}