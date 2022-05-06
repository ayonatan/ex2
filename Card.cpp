#include "Card.h"


Card::Card(CardType type, const CardStats& stats):
    m_effect(type),
    m_stats(stats) {}

void Card::printInfo() const
{
    switch (m_effect) {
        case CardType::Buff:
            printBuffCardInfo(m_stats);
        case CardType::Heal :
            printHealCardInfo(m_stats);
        case CardType::Treasure:
            printTreasureCardInfo(m_stats);
        case CardType::Battle:
            printBattleCardInfo(m_stats);
    }
}

