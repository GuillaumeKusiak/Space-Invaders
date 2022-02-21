/*!
 * @file    input.cpp
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Configuration du mode non canonique
 * @version 1.0
 */

#include <unistd.h>
#include "../../headers/Canonique/setInputMode.h"
#include "../../headers/Player/player.h"

using namespace nsVariables;

void nsSetInputMode::input(Sobject & object, std::vector<std::string> & tableOfGame, unsigned int & points, unsigned & countForPlayerShoot, const configGame & game) {
    char playerInput;
    read (STDIN_FILENO, & playerInput, 1);  //Lorsque le joueur appui sur une touche, elle est stocké
    nsPlayer::player(tableOfGame, playerInput, object, points, countForPlayerShoot, game);  //Puis, on regarde si elle correspond à une touche permettant de faire une action
}

