#ifndef Q12_ALIASES
#define Q12_ALIASES

#include <ctime>
#include <random>
#include "q12_constants.h"
#include "q12_enums.h"
#include "q12_structs.h"

using deck_type = std::array<Card,q12_constants::deckSize>;
using index_type = deck_type::size_type;
using mt_t = std::mt19937;
using mt_rt = std::mt19937::result_type;

#endif
