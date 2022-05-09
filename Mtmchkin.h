#ifndef MTM_HW2_MTMCHKIN_H
#define MTM_HW2_MTMCHKIN_H
#include "Card.h"
#include "Player.h"
#include <iostream>
#include<string>

/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
*/
enum class GameStatus{Win, Loss, MidGame};

class Mtmchkin {
public:

    /*
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
    */
    Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards);


    /*
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
    */
    void playNextCard();


    /*
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isOver() const;


    /*
     *  Get the status of the game:
     *
     *  @return
     *          GameStatus - the current status of the running game
     */
    GameStatus getGameStatus() const;

    Mtmchkin(const Mtmchkin &game);

    ~Mtmchkin();

    Mtmchkin &operator=(const Mtmchkin &game);

private:
    Player m_player;
    Card* m_cards_array;
    int m_num_of_cards;
    GameStatus m_game_status;
    int m_round;
};


#endif //EX2_GAME_H
