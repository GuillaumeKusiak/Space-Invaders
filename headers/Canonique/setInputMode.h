/*!
 * @file    setInputMode.h
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Configuration du mode non canonique
 * @version 1.0
 */

#ifndef SPACEINVADERS_SETINPUTMODE_H
#define SPACEINVADERS_SETINPUTMODE_H

#include "../GenerateGame/generateGame.h"

/**
 * @namespace nsSetInputMode
 * @brief Espace de nom pour le mode non canonique
 */
namespace nsSetInputMode
{
    /*!
     * @brief set_input_mode
     * @fn void set_input_mode();
     */
    void set_input_mode();

    void reset_input_mode(void);

    /*!
     * @brief récupération de l'input du joueur
     * @param[in/out] object : position de toutes les entitées
     * @param[in/out] tableOfGame : table de jeu
     * @param[in/out] points : points du joueur
     * @param[in/out] countForPlayerShoot : counter pour les tirs du joueur
     * @param[in] game : variables de la table de jeu
     */
    void input(
            Sobject & object,
            std::vector<std::string> & tableOfGame,
            unsigned & points,
            unsigned & countForPlayerShoot,
            const nsVariables::configGame & game);
}

#endif //SPACEINVADERS_SETINPUTMODE_H
