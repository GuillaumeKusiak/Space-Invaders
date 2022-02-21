/*!
 * @file    gameLoop.h
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Configuration de la boucle du jeu
 * @version 1.0
 */

#ifndef SPACEINVADERS_GAMELOOP_H
#define SPACEINVADERS_GAMELOOP_H

#include <vector>
#include <string>
#include "../GenerateGame/generateGame.h"
#include "../Skills/skills.h"

/*!
 * @namespace nsGameLoop
 * @brief Espace de nom pour la boucle du jeu
 */
namespace nsGameLoop
{
    /*!
     * @brief Boucle du jeu
     * @param[in/out] tableOfGame : table de jeu
     * @param[in/out] object : position de toutes les entitées
     * @param[in/out] points : points du joueur
     * @param[in/out] playerLife : vies du joueur
     * @param[in] game : variables de la table de jeu
     * @param[in/out] protectLife : vies de la protection
     * @fn void gameLoop(std::vector <std::string> & tableOfGame, Sobject & object, unsigned & points, unsigned & playerLife, const nsVariables::configGame & game);
     */
    void gameLoop(
            std::vector <std::string> & tableOfGame,
            Sobject & object,
            unsigned & points,
            unsigned & playerLife,
            const nsVariables::configGame & game,
            unsigned & protectLife,
            nsSkills::structSkills & skills);

    /*!
     * @brief déplacement de l'invader
     * @param[in/out] tableOfGame : table de jeu
     * @param[in/out] object : position de toutes les entitées
     * @param[in] game : variables de la table de jeu
     * @param[out] side : booléen
     * @fn void transitionMoveInvader(std::vector <std::string> & tableOfGame, Sobject & object, const nsVariables::configGame & game, bool & side);
     */
    void transitionMoveInvader(
            std::vector <std::string> & tableOfGame,
            Sobject & object,
            const nsVariables::configGame & game,
            bool & side);

    void setDifficulty(const unsigned & nbGame, unsigned & count);
}

#endif //SPACEINVADERS_GAMELOOP_H
