/*!
 * @file    torpedos.h
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Toutes les actions des torpilles
 * @version 1.0
 */

#ifndef SPACEINVADERS_TORPEDOS_H
#define SPACEINVADERS_TORPEDOS_H

#include "../GenerateGame/generateGame.h"

/**
 * @namespace nsTorpedos
 * @brief Espace de nom pour les torpilles
 */
namespace nsTorpedos
{
    /*!
     * @brief Supression de la torpille de la table du jeu (symbole dans le jeu : !)
     * @param[in/out] object : position de toutes les entitées
     * @param[in] i : indice de la torpille
     * @fn void RemoveTorpedo (Sobject & object, const unsigned & i);
     */
    void RemoveTorpedo (
            Sobject & object,
            const unsigned & i);

    /*!
     * @brief Déplacement de la torpille (symbole dans le jeu : !)
     * @param[in/out] tableOfGame : table de jeu
     * @param[in/out] object : position de toutes les entitées
     * @param[in/out] points : points du joueur
     * @param[in] game : variables de la table de jeu
     * @param[in/out] nameSkill : nom de la capacité
     * @fn void moveTorpedo (std::vector<std::string> & tableOfGame, Sobject & object, unsigned & points, nsVariables::configGame & game, std::string & nameSkill);
     */
    void moveTorpedo (
            std::vector<std::string> & tableOfGame,
            Sobject & object,
            unsigned & points,
            const nsVariables::configGame & game,
            std::string & nameSkill);
}

#endif //SPACEINVADERS_TORPEDOS_H
