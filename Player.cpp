#include "Player.h"

Player::Player(std::string m_name, int m_maxHP = 100, int force = 5) {
    if(illegal)
    {
        set to deafult vals;
    }
    this->m_coins = 0;
    this->m_level = ONE;
    this->m_force = force;
    this->m_name = m_name;
    this->m_HP = m_maxHP;
    this->m_maxHP = m_maxHP;
}

/*
Player::Player(const Player &player) {
      this->coins =player.coins
      this->m_level = player.m_level;
      this->force = force;
    m_coins(player.m_coins);
    m_force(player.m_force);
    m_level(player.m_level);
    m_name(player.m_name);
    m_maxHP(player.m_maxHP);
    m_HP(player.m_HP);

      this->m_name = m_name;
      this->m_HP = m_maxHP;
      this->m_maxHP = m_maxHP;
}*/

Player &Player::operator=(const Player &player) {

}

void Player::printInfo() {
    printPlayerInfo(m_name, m_level, m_force, m_HP, m_coins);
}


void Player::levelUp() {
    if (m_level != TEN) {
        m_level++;
    }
}

int Player::getLevel() {
    return m_level;
}

void Player::buff(int pointsToAdd) {
    m_force += pointsToAdd;
}


void Player::heal(int pointsToHeal) {
    if (m_HP + pointsToHeal < m_maxHP)
    {
        m_HP += pointsToHeal;
    } else {
        m_HP = m_maxHP;
    }
}

void Player::damage(int damagePoints) {
    if (m_HP-damagePoints>0)
    {
         m_HP -=damagePoints;
    } else {
       m_HP=0;
    }
}

bool Player::isKnockedOut(){
    if (m_HP<=0)
    {
        return true;
    }
    return false;
}

void Player::addCoins(int coinsToAdd)
{
    m_coins+=coinsToAdd;
}

bool Player::pay(int coinsToPay)
{
    if (m_coins-coinsToPay<0)
    {
        return false;
    }
    m_coins-=coinsToPay;
    return true;
}

int Player::getAttackStrength(){
    return m_level+m_force;
}
