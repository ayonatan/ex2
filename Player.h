
#ifndef MTM_HW2_PLAYER_H
#define MTM_HW2_PLAYER_H
#include<string>
#include "utilities.h"

const int DEFAULT_FORCE = 5;
const int DEFAULT_MAX_HP = 100;

class Player {
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

public:
    Player(const char* m_name, int m_maxHP = 100, int force = 5);

    Player(const Player &player) = default;

    ~Player() = default;

    Player &operator=(const Player &player) = default;

    void printInfo() const;

    void levelUp();

    int getLevel() const;

    void buff(int pointsToAdd);

    void heal(int pointsToHeal);

    void damage(int damagePoints);

    bool isKnockedOut() const;

    void addCoins(int coinsToAdd);

    bool pay(int coinsToPay);

    int getAttackStrength() const;
};

#endif //MTM_HW2_PLAYER_H
