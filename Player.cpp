#include "Player.h"

Player::Player(const char* name, int maxHP, int force) :
        m_name(name),
        m_level(1),
        m_coins(0)
{
    if (force <= 0)
    {
        m_force = DEFAULT_FORCE;
    } 
    else
    {
        m_force = force;
    }
    if (maxHP <= 0)
    {
        this->m_HP = DEFAULT_MAX_HP;
        this->m_maxHP = DEFAULT_MAX_HP;

    } 
    else
    {
        this->m_HP = maxHP;
        this->m_maxHP = maxHP;
    }
}

void Player::printInfo()const
{
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_HP, m_coins);
}


void Player::levelUp()
{
    if (m_level != 10) 
    {
        m_level++;
    }
}

int Player::getLevel()const
{
    return m_level;
}

void Player::buff(int pointsToAdd) 
{
    m_force += pointsToAdd;
}


void Player::heal(int pointsToHeal) 
{
    if (m_HP + pointsToHeal < m_maxHP) 
    {
        m_HP += pointsToHeal;
    } 
    else 
    {
        m_HP = m_maxHP;
    }
}

void Player::damage(int damagePoints) 
{
    if (m_HP - damagePoints > 0) 
    {
        m_HP -= damagePoints;
    } 
    else 
    {
        m_HP = 0;
    }
}

bool Player::isKnockedOut()const 
{
    if (m_HP <= 0) 
    {
        return true;
    }
    return false;
}

void Player::addCoins(int coinsToAdd) 
{
    m_coins += coinsToAdd;
}

bool Player::pay(int coinsToPay)
{
    if (m_coins - coinsToPay < 0) {
        return false;
    }
    m_coins -= coinsToPay;
    return true;
}

int Player::getAttackStrength()const
{
    return m_level + m_force;
}
