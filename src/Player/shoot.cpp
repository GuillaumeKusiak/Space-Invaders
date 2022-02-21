/*!
 * @file    shoot.cpp
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Toutes les actions en lien avec le SpaceShip (joueur)
 * @version 1.0
 */
#include "../../headers/Player/player.h"

void nsPlayer::shoot(std::vector<std::string> & tableOfGame, Sobject & object, const unsigned int & cote) {
    object.torpedo.push_back(pos{object.spaceShip[0].nLine - 1, object.spaceShip[0].nColumn + cote});
}//shoot()