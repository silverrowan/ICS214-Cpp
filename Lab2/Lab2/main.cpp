
#include <iostream>
#include <string>
#include "Weekday.h"
#include "TextInput.h"

/// <summary>
/// use Zeller’s congrunce algorithm to calculate and return a Weekday (string)
/// </summary>
/// <returns>error status code (0: success)</returns>
int main()
{
    std::cout << "Find the day of the week for: \n";
    findWeekdayOfUserDate();
}