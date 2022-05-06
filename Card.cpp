#include "Card.h"


Card::Card(CardType type, const CardStats& stats):
    m_effect(type),
    m_stats(stats) {}

void Card::printInfo() const
{
    switch (m_effect) {
        case Buff:
            printBuffCardInfo(m_stats);
        case Heal :
            printHealCardInfo(m_stats);
        case Treasure:
            printTreasureCardInfo(m_stats);
        case Battle:
            printBattleCardInfo(m_stats);
    }
}

