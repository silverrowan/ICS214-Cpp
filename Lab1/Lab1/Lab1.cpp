// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <regex>

int getIntFromUser()

    while (true) {
        int intValue{};
        std::cin >> intValue;

        if (intValue < 0 ) { // valid integer, invalid for range (error case 1)
            std::cout << "Invalid input. Input must be a positive int. Please try again." << std::endl;
        } else if ( intValue ) { // valid integer (success) (may include the followed by non num, check)
            return intValue;
        } else if () {
            //OVERFLOWS. NOT SURE GOES HERE. SUSPECT IT GOES UNDER FAIL
        } else if (  std::cin.fail() ) { // cin failed to parse, contains error case 2 & 3
            if (intValue) { // valid nums followed by invalid (case 2)
                //record valid num into intValue if req'd
                //clear buffer
                //set fail() back to false
                return intValue;
            } else { //no Nums (case 3) -- but ALSO end up here for int overflow
                //set intValue to null?
                //clear buffer
                //set fail() back to false
                std::cout << "Invalid input. Input must be a valid int. Please try again." << std::endl;
                continue; //IF NEEDED. Prob not
            }

        //check valid number //regEx?
            // if valid number (entirely) break out of loop/return int
                    return intValue;
            // prob case1: if valid number but meaningless to program (eg. -1) try again
            // prob case2: if valid number followed by invalid chars, 
            //              discard contents after valid # & ret num
            // prob case3: if invalid number ('input extraction fails'
                    std::cout << "Invalid input. Input must be a valid int. Please try again." << std::endl;
            // prob case4: if valid number; but overflows; treat same as prob case3
    }
        
}

int promptUserForMaxRange()
{
    std::cout << "Enter the maximum range: ";
    int max{ getIntFromUser() };
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
    int guess{ getIntFromUser() };
    return guess;
}

bool promptForPlayAgain() // change to while true
{
    while (true) {
        std::cout << "Do you wish to play again [y/n]: ";
        char response{};
        std::cin >> response;
        if (response == 'y' || response == 'Y')
        {
            std::cout << std::endl;
            return true;
        }
        else if (response == 'n' || response == 'N')
        {
            return false;
        }
        else
        {
            std::cout << "invalid input - try again" << std::endl;
        }
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