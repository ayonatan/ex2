#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards):
m_player(playerName),
m_cards_array(new Card[numOfCards]),
m_num_of_cards(numOfCards),
m_game_status(GameStatus::MidGame),
m_round(0){}

void playNextCard()
{
    m_cards_array[m_round].printInfo();
    m_cards_array[m_round].applyEncounter(m_player);
    m_player.printInfo();
    m_round++;
    if (m_round == m_num_of_cards)
    {
        m_round = 0;
    }
    if (m_player.getLevel == TEN)
    {
        m_game_status=GameStatus::Win;
        return;
    }
    if (m_player.isKnockedOut())
    {
        m_game_status=GameStatus::Loss;
        return;
    }
}

GameStatus getGameStatus()const
{
    return m_game_status;
}

bool isOver()const
{
    return m_game_status!=GameStatus::MidGame;
}
