#include <iostream>
#include <array>
#include <string>

#include "q12_enums.h"
#include "q12_structs.h"
#include "q12_aliases.h"
#include "q12_deck.h"
#include "q12_constants.h"

void dealPlayer(Player &player, const deck_type &deck, bool dealer)
{
    std::cout << (dealer ? "Dealer" : "You") << " got: ";

    static index_type currentCard{};
    printCard(deck[currentCard]);
    std::cout << '\n';

    player.total += getCardValue(deck[currentCard]);
    if (deck[currentCard].rank == CardRank::RANK_ACE)
    {
        ++player.aces;
    }
    ++currentCard;
}

bool hitOrStand()
{
    std::cout << "Hit or Stand? ";
    std::string input{};
    std::cin >> input;
    return (input == "Hit");
}

void countAces(Player &player)
{
    while (player.aces > 0 && player.total >= q12_constants::maxScore)
    {
        player.total -= 10;
        --player.aces;
    }
}

bool bust(Player &player)
{
    if (player.total > q12_constants::maxScore)
    {
        countAces(player);
    }
    return (player.total > q12_constants::maxScore);
}

GameResult compare(const Player &player, const Player &dealer)
{
    if (player.total > dealer.total)
    {
        return GameResult::PLAYER_WINS;
    }
    else if ( player.total < dealer.total)
    {
        return GameResult::DEALER_WINS;
    }
    else
    {
        return GameResult::TIE;
    }
}

GameResult playBlackjack(const deck_type &deck)
{
    Player player{};
    dealPlayer(player, deck, false);

    Player dealer{};

    do
    {
        dealPlayer(player, deck, false);
    }
    while (!bust(player) && hitOrStand());
    if (bust(player))
    {
        std::cout << "Bust\n";
        return GameResult::DEALER_WINS;
    }

    do
    {
        dealPlayer(dealer, deck, true);
    }
    while (!bust(dealer) && dealer.total <= q12_constants::dealerStandScore);
    if (bust(dealer))
    {
        std::cout << "Bust\n";
        return GameResult::PLAYER_WINS;
    }

    return compare(player, dealer);
}

void printGameResults(const GameResult &result)
{
    switch (result)
    {
        case GameResult::PLAYER_WINS:
            std::cout << "You Win!";
            break;
        case GameResult::DEALER_WINS:
            std::cout << "Dealer Wins";
            break;
        case GameResult::TIE:
            std::cout << "Tie";
            break;
    }
}

int main()
{
    deck_type deck{createDeck()};
    shuffleDeck(deck);
    GameResult result{playBlackjack(deck)};
    printGameResults(result);
    return 0;
}
