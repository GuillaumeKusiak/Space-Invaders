/*!
 * @file    player.cpp
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Toutes les actions en lien avec le SpaceShip (joueur)
 * @version 1.0
 */
#include "../../headers/Player/player.h"
using namespace nsVariables;


void nsPlayer::player(std::vector<std::string> & tableOfGame, const char & charInput, Sobject & object,
                      unsigned int & points, unsigned & countForPlayerShoot, const configGame & game) {
    if ((charInput == game.KeyShootLeft) && (countForPlayerShoot >= 10))    //Si le joueur a taper sur la touche permettant de tirer avec le côté gauche du vaisseau et qu'il peut tirer (compteur)
    {
        shoot(tableOfGame, object, 0);  //On le fait tirer
        countForPlayerShoot = 0;    //On réinitialise le compteur
    }

    else if ((charInput == game.KeyShootRight) && (countForPlayerShoot >= 10))  //Si le joueur a taper sur la touche permettant de tirer avec le côté droite du vaisseau et qu'il peut tirer (compteur)
    {
        shoot(tableOfGame, object, 1);
        countForPlayerShoot = 0;
    }

    else if (charInput == game.KeyLeft) //Si le joueur a taper sur la touche permettant de se déplacer à gauche
    {
        if (object.spaceShip[0].nColumn >= 1)   //On déplace le vaisseau à gauche
        {
            --object.spaceShip[0].nColumn;
            --object.spaceShip[1].nColumn;
            tableOfGame[object.spaceShip[0].nLine][object.spaceShip[0].nColumn + 1] = game.KEmpty; // on remet un case vide
            tableOfGame[object.spaceShip[1].nLine][object.spaceShip[1].nColumn + 1] = game.KEmpty; // on remet un case vide*/
        }
    }
    else if (charInput == game.KeyRight)    //Si le joueur a taper sur la touche permettant de se déplacer à droite
    {
        if (object.spaceShip[1].nColumn <= game.KSizeSpace-2)   //On déplace le vaisseau à droite
        {
            ++object.spaceShip[0].nColumn;
            ++object.spaceShip[1].nColumn;
            tableOfGame[object.spaceShip[0].nLine][object.spaceShip[0].nColumn - 1] = game.KEmpty;
            tableOfGame[object.spaceShip[1].nLine][object.spaceShip[1].nColumn - 1] = game.KEmpty;
        }
    }
}//player()