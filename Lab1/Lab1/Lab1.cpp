// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <climits>

void clearExcessCharacters() { //clears entire (remaining) buffer
    //int maxCharClear = std::numeric_limits<std::streamsize>::max();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // clear up to 100 characters out of the buffer, or until a '\n' character is removed
    //for some reason, didn't seem to quite work right when std::numeric_...::max() was moved into a variable as a string nor an int for this
}

int getIntFromUser() {
    //I would preffer to re-prompt, but that would mean passing in the prompt string
    //      --but then could also combo the prompting functions for max range and guess
    while (true) {
        //problem when guess is = 0 
        int intValue{};
        std::cin >> intValue;

        auto& checkCin = std::cin;
        if (!std::cin) { // extraction failed (initial char invalid-error case 3, overflow-case 4, & eof)
            if (std::cin.eof()) { //end of file (eof), entered by user (key combos)
                std::exit(0); //exit program as successfull
            }
            else { //overflow & non-integer treated the same. (before creation of '...InRange()'
                std::cin.clear();
                clearExcessCharacters();
                if (intValue == INT_MAX) { //added after '...InRange()' added - to avoid treating the same as non-integer
                    return INT_MAX + 1;
                }
                else {
                    std::cout << "Invalid input. Input must be a valid int. Please try again." << std::endl;
                }
            }
        }
        else {
            clearExcessCharacters(); //handles integer followed by invalid characters (error case 2)

            if (intValue < 0) { // valid integer, invalid for range (error case 1)
                std::cout << "Invalid input. Input must be a positive int. Please try again." << std::endl;
            }
            else { //valid integer entry
                return intValue;
            }
        }
    }
}

int getIntFromUserInRange( int min, int max ) {
    while (true) {
        int input{ getIntFromUser() };
        if ( input < min || input > max ) {
            std::cout << "Invalid input. Range is [  " << min << " to " << max << " ]. Please try again.";
        }
        else {
            return input;
        }
    }
}

int promptUserForMaxRange()
{
    std::cout << "Enter the maximum range: ";
    int max{ getIntFromUserInRange( 0, INT_MAX) };
    return max;
}

int pickRandomNumberInRange(int min, int max) // inclusive of min & max
{
    int rangeSize{ max - min + 1 }; 
    int randomNumber{ min + (rand() % rangeSize) };
    return randomNumber;
}

int promptUserForGuess(int maxRange)
{
    std::cout << "Guess a number between 0 and " << maxRange << ": ";
    int guess{ getIntFromUserInRange( 0, maxRange ) };
    return guess;
}

bool promptForPlayAgain() // change to while true
{
    while (true) {
        std::cout << "Do you wish to play again [y/n]: ";
        char response{};
        std::cin >> response;

        auto& checkCin = std::cin;
        auto* rawBuffer = checkCin.rdbuf();

        if (std::cin.peek() == '\n')
        {
            if (response == 'n' || response == 'N')
            {
                return false;
            }
            else if (response == 'y' || response == 'Y')
            {
                std::cout << std::endl;
                return true;
            }
        }
        std::cout << "invalid input - try again" << std::endl;
        clearExcessCharacters();        
    }
}

void playOneRound()
{
    std::cout << "*** Welcome to mystery number ***" << std::endl;
    int max{ promptUserForMaxRange() };
    int targetNumber{ pickRandomNumberInRange(0, max) };
    
    int guess{};
    int guessCount{ 0 };
    do
    {
        guess = promptUserForGuess(max); //guess will show when typed in, dont need to output
        guessCount++;
        if (guess == targetNumber)
        {
            std::cout << "Correct, it took you " << guessCount << " guesses!" << std::endl;
        }
        else if (guess > targetNumber) {
            std::cout << "guess lower..." << std::endl;
        }
        else
        {
            std::cout << "guess higher..." << std::endl;
        }
    } while (guess != targetNumber);
}

int main()
{
    //testing pickRandomNumberInRange() functions correctly
    for (int i = 1; i <= 20; i++)
    {
        std::cout << "number " << i << ": ";
        std::cout << pickRandomNumberInRange(5, 7);
        std::cout << std::endl;
    }
    //add space between test and game
    std::cout << std::endl;

    //seed random number for game
    srand( static_cast<unsigned int>(time(0)) );

    //play game
    playOneRound();
    
    //play again? and continue if y
    while (true) {
        bool again{ promptForPlayAgain() };
        if (again == true)
        {
            playOneRound();
        }
        else
        {
            std::cout << "Thanks for playing!" << std::endl;
        }
    }
}