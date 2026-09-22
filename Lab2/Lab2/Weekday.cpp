#include <iostream>
#include <string>
#include "TextInput.h"
#include "Weekday.h"

int promptForYear() { return promptUserForIntInRange("Year: ", 0, 9999); }

int promptForMonth() { return promptUserForIntInRange("Month (number): ", 1, 12); }

int promptForDayOfMonth() { return promptUserForIntInRange("Day of the Month (number): ", 1, 31); }

Date promptForDayMonthYear() {
    Date standard = {
        promptForMonth(),
        promptForDayOfMonth(),
        promptForYear()
    };
    return standard;
}

Date convertMonthsToZellers(Date standardMonths) {
    if (standardMonths.month == 1 || standardMonths.month == 2) {
        standardMonths.month += 12;
        standardMonths.year--;
    }
    return standardMonths;
}

int calculateWeekdayNum(Date date) {
    // Zeller's congruence - to calc day of the week
    // h = (q + 26(m+1)/10 + k + k/4 + j/4 + 5j) % 7
    // 
    // h = dayOfWeekNum : 0=sat, 1=sun, 2=mon, 3=tues, 4=wed, 5=thur, 6=friday
    // q = dayOfMonth
    // m = monthNum... monthNum EXCEPT jan = 13, feb = 14 OF PREV YEAR
    // j = century ( integer division: year/100 )
    // k = yearOfCentury ( year % 100 )


    int century{ date.year / 100 };
    int yearOfCentury{ date.year % 100 };
    int monthNum{ date.month };
    int monthNumCalculation{ (26 * (monthNum + 1)) / (10) }; //not sure what to call this - this is or represents - working on it

    int dayOfYearNum = (date.day + monthNumCalculation +
        yearOfCentury + yearOfCentury / 4 + century / 4 + 5 * century);
    int dayOfWeekNum = dayOfYearNum % 7;

    return dayOfWeekNum;
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

Weekday calculateWeekday(Date date) {
    int weekdayNum = calculateWeekdayNum( date );
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

void findWeekdayOfUserDate() {
    Date date{ promptForDayMonthYear() };
    Date zellersDate{ convertMonthsToZellers(date) };
    int weekdayNum{ calculateWeekdayNum(zellersDate) };

    Weekday weekdayDay{ convertWeekdayNumToDay(weekdayNum) };
    std::string weekdayNameString{ getWeekdayName(weekdayDay) };

    std::cout << "Weekday enum: " << weekdayNameString << "\n";
}