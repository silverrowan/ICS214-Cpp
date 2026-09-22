#ifndef WEEKDAY_H
#define WEEKDAY_H

enum class Weekday { Saturday = 0, Sunday, Monday, Tuesday, Wednesday, Thursday, Friday };
struct Date {
    int month;
    int day;
    int year;
};

// prompt the user for the year and return the result
int promptForYear();

// prompt the user for the month and return the result
int promptForMonth();

// prompt the user for the day of the month (0-31) and return the result
int promptForDayOfMonth();

/// <summary>
/// prompt the user for year, month, and day of the month.
/// </summary>
/// <returns>Date struct: { month, day, year )</returns>
Date promptForDayMonthYear();

/// <summary>
/// Converts Date to format needed for Zeller's Congruence
/// January and February become months 13 & 14 of previous year
/// </summary>
/// <param name="standardMonths">Date as normally written numerically</param>
/// <returns>Date struct { month, day, year } with Jan & Feb alterations</returns>
Date convertMonthsToZellers(Date standardMonths);

/// <summary>
/// use Zeller’s congrunce algorithm to calculate and return a Weekday as integer
/// January and February are months 13 & 14 of previous year, respectively
/// </summary>
/// <param name="month">int values in range 3-14 </param>
/// <param name="dayOfMonth">int values in range 1-31 </param>
/// <param name="year">int values 0-9999 </param>
/// <returns>int representing day of the week; 0=sat, 1=sun, 2=mon, 3=tues, 4=wed, 5=thur, 6=friday</returns>
int calculateWeekdayNum(int month, int dayOfMonth, int year);

/// <summary>
/// use Zeller’s congrunce algorithm to calculate and return a Weekday as enum
/// </summary>
/// <param name="month">int values in range 3-14 </param>
/// <param name="dayOfMonth">int values in range 1-31 </param>
/// <param name="year">int values >=0 </param>
/// <returns>enum Weekday::value for day of the week</returns>
Weekday calculateWeekday(int month, int dayOfMonth, int year);

/// <summary>
// convert integer (from Zeller's congrunce) into appropriate Weekday enum value. 
// 0=sat, 1=sun, 2=mon, 3=tues, 4=wed, 5=thur, 6=friday
/// </summary>
/// <param name="dayNum">integer representing day of the week</param>
/// <returns>Enum Value of day of the week</returns>
Weekday convertWeekdayNumToDay(int dayNum);

/// <summary>
/// Returns a string representation of Weekday enum value
/// </summary>
/// <param name="day">enum Weekday::value</param>
/// <returns>String of weekday name</returns>
std::string getWeekdayName(Weekday day);

/// <summary>
/// Asks user for a month, day, and year, and displays the day of the week for that date
/// </summary>
void findWeekdayOfUserDate();
#endif //!WEEKDAY_H