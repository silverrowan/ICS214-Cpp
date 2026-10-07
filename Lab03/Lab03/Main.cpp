

#include <iostream>
#include "Cards.h"

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int numTrials = 0;
    int totalCardsDrawn = 0;

    //moved here out of the getpick...() cut down ~15s vs whatever checks are needed if generated each time
    static std::array<int, Constants::CARD_COUNT> deck = makeDeck();

    for (int i = 0; i < 10'000'000; i++) {
        int cardsDrawn = getPickCountNeededForFourSuits(false, false, deck);

        totalCardsDrawn += cardsDrawn;
        numTrials++;
    }

    double avgCardsDrawn = static_cast<double>(totalCardsDrawn) / static_cast<double>(numTrials);
    std::cout << "average cards drawn until four suits: " << avgCardsDrawn << "\n\n";
}