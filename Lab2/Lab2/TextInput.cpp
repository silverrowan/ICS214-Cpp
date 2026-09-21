// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <cstdlib>
#include <climits>
#include <string>

// Clears all characters remaining in the stream buffer
// input parameters: none; output: none
void clearExcessCharacters() { //clears entire (remaining) buffer
    //int maxCharClear = std::numeric_limits<std::streamsize>::max();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // clear up to 100 characters out of the buffer, or until a '\n' character is removed
    //for some reason, didn't seem to quite work right when std::numeric_...::max() was moved into a variable as a string nor an int for this
}

// Collects a user response within the terminal and checks
// the response for a valid integer. Outputs message to 
// terminal and repeats if no valid integer provided.
// NOTE: does not include the prompt to the user
// input parameters: none; output: int of user response
int getIntFromUser() {
    //I would preffer to re-prompt, but that would mean passing in the prompt string
    //      --but then could also combo the prompting functions for max range and guess
    while (true) {
        //problem when guess is = 0 
        int intValue{};
        std::cin >> intValue;

        //auto& checkCin = std::cin;
        if (!std::cin && std::cin.eof()) { // extraction failed (initial char invalid-error case 3, overflow-case 4, & 
            //                                  end of file (eof), entered by user (key combos)
            std::exit(0); //exit program as successfull
        }
        else if (!std::cin) { //overflow & non-integer treated the same. (before creation of '...InRange()'
            std::cin.clear();
            clearExcessCharacters();
            if (intValue == INT_MAX) {
                std::cout << "Maximum int is " << INT_MAX << std::endl;
            }
            std::cout << "Invalid input. Input must be a valid int. Please try again." << std::endl;
        }
        else {
            clearExcessCharacters(); //handles integer followed by invalid characters (error case 2)
            return intValue;
        }
    }
}

// In addition to standard validation of above function getIntFromUser()
// checks that the integer is within a valid range, changes response when
// integer overflows.
// input parameters: int min - smallest acceptable integer (inclusive)
//                  int max - largest acceptable integer (inclusive)
// output: int of user response
int getIntFromUserInRange(int min, int max) {
    while (true) {
        int input{ getIntFromUser() };
        if (input < min || input > max) {
            std::cout << "Invalid input. Range is [  " << min << " to " << max << " ]. Please try again.";
        }
        else {
            return input;
        }
    }
}

// Asks the user to provide the integer for the maximum range of the game, 
// and validates the response.
// input parameters: none; output: int of range maximum 
int promptUserForMaxRange()
{
    std::cout << "Enter the maximum range: ";
    int max{ getIntFromUserInRange(1, INT_MAX) };
    return max;
}

int promptUserForInt(std::string prompt) {
    std::cout << prompt;
    return getIntFromUser();
}

int promptUserForIntInRange(std::string prompt, int min, int max) {
    std::cout << prompt;
    return getIntFromUserInRange(min, max);
}

//std::string promptUserForString(std::string prompt) { //includes basic string validation
//    std::cout << prompt;
//    std::string response{};
//    std::cin >> response;
//
//    if (!std::cin && std::cin.eof()) { //key-combo end of file
//        std::exit(0);
//    }
//    else if (!std::cin) { //overflow, non-string(is this even possible? i guess non ASII?)
//        std::cin.clear();
//        clearExcessCharacters();
//        //if ( response length == string maxium) {
//            std::cout << "Maximum response length is ";  //<< MAXLENGTH
//    }
//    else {
//        clearExcessCharacters();
//        return response;
//    }
//
//}