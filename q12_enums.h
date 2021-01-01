#ifndef Q12_ENUMS
#define Q12_ENUMS

enum class CardRank
{
    RANK_TWO,
    RANK_THREE,
    RANK_FOUR,
    RANK_FIVE,
    RANK_SIX,
    RANK_SEVEN,
    RANK_EIGHT,
    RANK_NINE,
    RANK_TEN,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,

    MAX_RANK
};

enum class CardSuit
{
    SUIT_CLUBS,
    SUIT_DIAMONDS,
    SUIT_HEARTS,
    SUIT_SPADES,

    MAX_SUITS
};

enum class GameResult
{
    PLAYER_WINS,
    DEALER_WINS,
    TIE
};

#endif
