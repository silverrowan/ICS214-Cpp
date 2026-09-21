#ifndef DATES_H
#define DATES_H

enum class Weekday { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

// prompt the user for the year and return the result
int promptForYear();

// prompt the user for the month and return the result
int promptForMonth();

// prompt the user for the day of the month (0-31) and return the result
int promptForDayOfMonth();

//// use Zeller’s congrunce algorithm to calculate and return a Weekday
//Weekday calculateWeekday(int month, int dayOfMonth, int year);

// use Zeller’s congrunce algorithm to calculate and return a Weekday
// 0=sat, 1=sun, 2=mon, 3=tues, 4=wed, 5=thur, 6=friday
int calculateWeekdayNum(int month, int dayOfMonth, int year);

Weekday calculateWeekday(int month, int dayOfMonth, int year)
////Get enum string from enum number
//std::string getWeekdayName(Weekday day);
#endif