#ifndef Q12_STRUCTS
#define Q12_STRUCTS

struct Card
{
    CardRank rank{};
    CardSuit suit{};
};

struct Player
{
    int total{};
    int aces{};
};

#endif
