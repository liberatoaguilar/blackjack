#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>

#include "q12_enums.h"
#include "q12_structs.h"
#include "q12_aliases.h"

void printCard(const Card &card)
{
    switch (card.rank)
    {
        case CardRank::RANK_TWO:
            std::cout << '2';
            break;
        case CardRank::RANK_THREE:
            std::cout << '3';
            break;
        case CardRank::RANK_FOUR:
            std::cout << '4';
            break;
        case CardRank::RANK_FIVE:
            std::cout << '5';
            break;
        case CardRank::RANK_SIX:
            std::cout << '6';
            break;
        case CardRank::RANK_SEVEN:
            std::cout << '7';
            break;
        case CardRank::RANK_EIGHT:
            std::cout << '8';
            break;
        case CardRank::RANK_NINE:
            std::cout << '9';
            break;
        case CardRank::RANK_TEN:
            std::cout << 'T';
            break;
        case CardRank::RANK_JACK:
            std::cout << 'J';
            break;
        case CardRank::RANK_QUEEN:
            std::cout << 'K';
            break;
        case CardRank::RANK_KING:
            std::cout << 'Q';
            break;
        case CardRank::RANK_ACE:
            std::cout << 'A';
            break;
        default:
            std::cout << '?';
    }
    switch (card.suit)
    {
        case CardSuit::SUIT_CLUBS:
            std::cout << "C";
            break;
        case CardSuit::SUIT_DIAMONDS:
            std::cout << "D";
            break;
        case CardSuit::SUIT_HEARTS:
            std::cout << "H";
            break;
        case CardSuit::SUIT_SPADES:
            std::cout << "S";
            break;
        default:
            std::cout << '?';
    }
}

deck_type createDeck()
{
    deck_type deck{};
    index_type currentCard{};

    for (int currentSuit{}; currentSuit < q12_constants::max_suits; ++currentSuit)
    {
        for (int currentRank{}; currentRank < q12_constants::max_ranks; ++currentRank)
        {
            deck[currentCard].rank = static_cast<CardRank>(currentRank);
            deck[currentCard].suit = static_cast<CardSuit>(currentSuit);
            ++currentCard;
        }
    }
    return deck;
}

void printDeck(const deck_type &deck)
{
    for (const Card &card : deck)
    {
        printCard(card);
        std::cout << ' ';
    }
    std::cout << '\n';
}

void shuffleDeck(deck_type &deck)
{
    static mt_t mt{static_cast<mt_rt>(std::time(nullptr))};
    std::shuffle(deck.begin(),deck.end(),mt);
}

int getCardValue(const Card &card)
{
    switch (card.rank)
    {
        case CardRank::RANK_TWO:
            return 2;
        case CardRank::RANK_THREE:
            return 3;
        case CardRank::RANK_FOUR:
            return 4;
        case CardRank::RANK_FIVE:
            return 5;
        case CardRank::RANK_SIX:
            return 6;
        case CardRank::RANK_SEVEN:
            return 7;
        case CardRank::RANK_EIGHT:
            return 8;
        case CardRank::RANK_NINE:
            return 9;
        case CardRank::RANK_TEN:
        case CardRank::RANK_JACK:
        case CardRank::RANK_QUEEN:
        case CardRank::RANK_KING:
            return 10;
        case CardRank::RANK_ACE:
            return 11;
        default:
            return 0;
    }
}
