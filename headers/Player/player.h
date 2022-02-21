/*!
 * @file    player.h
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Toutes les actions en lien avec le SpaceShip (joueur)
 * @version 1.0
 */

#ifndef SPACEINVADERS_PLAYER_H
#define SPACEINVADERS_PLAYER_H

#include "../GenerateGame/generateGame.h"
#include <vector>
#include <string>

/**
 * @namespace nsPlayer
 * @brief Espace de nom pour le joueur
 */
namespace nsPlayer
{
    /*!
     * @brief Toutes les actions en lien avec le vaisseau (joueur), déplacement, tir, etc. (symbole dans le jeu : A)
     * @param[in/out] tableOfGame : table de jeu
     * @param[in] charInput : caractère pressé
     * @param[in/out] object : position de toutes les entitées
     * @param[in/out] points : points du joueur
     * @param[in/out] countForPlayerShoot : counter pour les tirs du joueur
     * @param[in] game : variables de la table de jeu
     * @fn void player(std::vector<std::string> & tableOfGame, const char & charInput, Sobject & object, unsigned & points, unsigned & countForPlayerShoot, const nsVariables::configGame & game);
     */
    void player(
            std::vector<std::string> & tableOfGame,
            const char & charInput,
            Sobject & object,
            unsigned & points,
            unsigned & countForPlayerShoot,
            const nsVariables::configGame & game);

    /*!
     * @brief Initialiser le tir de la torpille (symbole dans le jeu : !)
     * @param[in/out] tableOfGame : table de jeu
     * @param[in/out] object : position de toutes les entitées
     * @param[in] cote : le côté du tir
     * @fn void shoot(std::vector<std::string> & tableOfGame, Sobject & object, const unsigned & cote);
     */
    void shoot(
            std::vector<std::string> & tableOfGame,
            Sobject & object,
            const unsigned & cote);
}


#endif //SPACEINVADERS_PLAYER_H
