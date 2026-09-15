// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib> //why good practice to incl, doesnt this result in duplicates if in iostream?

int promptUserForMaxRange()
{
    std::cout << "Enter the maximum range: ";
    int max{};
    std::cin >> max; //NOTE does not handle non-int gracefully (yet)
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
    int guess{};
    std::cin >> guess; //NOTE does NOT handle non-int gracefully (yet)
    return guess;
}

bool promptForPlayAgain()
{
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
        promptForPlayAgain();
        //get a warning that not all control paths return a value - but eventually will resolve to y/Y/n/N which will return a value
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
}