
#ifndef MTM_HW2_PLAYER_H
#define MTM_HW2_PLAYER_H

#include "utilities.h"
#include <string>

typedef enum level { // enum or enum class ??
    ONE, TWO, THREE, FOR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN
};

class Player {
    std::string m_name;
    level m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    unsigned int m_coins;

public:
    Player(std::string m_name, int m_maxHP = 100, int force = 5);

    Player(const Player &player) = default;

    ~Player() = default;

    Player &operator=(const Player &player) = default;

    void printInfo();

    void levelUp();

    int getLevel();

    void buff(int pointsToAdd);

    void heal(int pointsToHeal);

    void damage(int damagePoints);

    bool isKnockedOut();

    void addCoins(int coinsToAdd);

    bool pay(int coinsToPay);

    int getAttackStrength();
};

#endif //MTM_HW2_PLAYER_H
