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

    //play initial round
    playOneRound();
}

// function guess number: 
// initial condns
// guess tracker = 0;
// generate random number between 0 & 10 (inclusive)

// c: '***Welcome to mystery number ***'
// c: 'enter teh maximum range: '   ;    p: enter 10
// c: ask user: guess the random number between 0 & 10 (inclusive) 
// p: guess number 
// c: if too high: guess lower
// c: if too low: guess higher
// c: add 1 to num guess tracker
// c: if correct: 'correct - it tooy you ___ guesses'.
//                  Do you wish to play again [y/n]: 
// p: y or n
// 


//do { guessNumber() } while ( answer = y )



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
