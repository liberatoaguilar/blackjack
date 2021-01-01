#ifndef Q12_DECK
#define Q12_DECK

#include "q12_enums.h"
#include "q12_structs.h"
#include "q12_aliases.h"

void printCard(const Card &card);
deck_type createDeck();
void printDeck(const deck_type &deck);
void shuffleDeck(deck_type &deck);
int getCardValue(const Card &card);

#endif
