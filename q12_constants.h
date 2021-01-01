#ifndef Q12_CONSTANTS
#define Q12_CONSTANTS

#include "q12_enums.h"
#include "q12_structs.h"

namespace q12_constants
{
    constexpr int max_ranks{static_cast<int>(CardRank::MAX_RANK)};
    constexpr int max_suits{static_cast<int>(CardSuit::MAX_SUITS)};
    constexpr int deckSize{max_ranks*max_suits};
    constexpr int maxScore{21};
    constexpr int dealerStandScore{17};
}

#endif
