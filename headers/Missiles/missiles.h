/*!
 * @file    missiles.h
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Toutes les actions en lien avec les missiles
 * @version 1.0
 */

#ifndef SPACEINVADERS_MISSILES_H
#define SPACEINVADERS_MISSILES_H

#include "../GenerateGame/generateGame.h"

/**
 * @namespace nsMissiles
 * @brief Espace de nom pour les missiles
 */
namespace nsMissiles
{
    /*!
     * @brief Déplacement du missile sur le table de jeu (symbole dans le jeu : T)
     * @param[in/out] tableOfGame : table de jeu
     * @param[in/out] object : position de toutes les entitées
     * @param[in/out] points : points du joueur
     * @param[in/out] playerLife : vies du joueur
     * @param[in] game : variables de la table de jeu
     * @fn void moveMissile (std::vector<std::string> & tableOfGame, Sobject & object, unsigned & points, unsigned & playerLife, const nsVariables::configGame & game);
     */
    void moveMissile (
            std::vector<std::string> & tableOfGame,
            Sobject & object,
            unsigned & points,
            unsigned & playerLife,
            const nsVariables::configGame & game,
            unsigned & protectLife);

    /*!
     * @brief Supression du missile (symbole dans le jeu : T)
     * @param[in/out] object : position de toutes les entitées
     * @param[in] i : indice du missile sur la table du jeu
     * @fn void RemoveMissile (Sobject & object, const unsigned & i);
     */
    void RemoveMissile (
            Sobject & object,
            const unsigned & i);

}


#endif //SPACEINVADERS_MISSILES_H
