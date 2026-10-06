

#include <iostream>
#include "Cards.h"


int pickRandomCard();
int getPickCountNeededForFourSuits(bool verbose);

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int numTrials = 0;
    int totalCardsDrawn = 0;
    for (int i = 0; i < 10000000; i++) {
        int cardsDrawn = getPickCountNeededForFourSuits(false);

        totalCardsDrawn += cardsDrawn;
        numTrials++;
        double avgCardsDrawn = static_cast<double>(totalCardsDrawn) / static_cast<double>(numTrials);

        std::cout << "average cards drawn until four suits: " << avgCardsDrawn << "\n\n";
    }
}