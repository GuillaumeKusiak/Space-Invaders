/*!
 * @file    level.h
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Gestion du niveau des joueurs
 * @version 1.0
 */

#ifndef SPACE_LEVEL_H
#define SPACE_LEVEL_H

#include "../GenerateGame/generateGame.h"
#include "../ManipulateFile/manipulateFile.h"

/**
 * @namespace nsLevel
 * @brief Espace de nom pour gérer le level des joueurs
 */
namespace nsLevel
{
    /*!
     * @brief Calcul le niveau par rapport à l'expérience
     * @param[in] points : score du joueur
     * @fn void levelSystem(const unsigned & points);
     */
    void levelSystem(
            const unsigned & points);

    /*!
     * @brief Initialise la map qui stock le nombre de points et le nom d'utilisateur du joueur
     * @param[in] points : score du joueur
     * @param[in] username : nom d'utilisateur du joueur
     * @fn void levelPlayer(const unsigned & points, const std::string & username);
     */
    void levelPlayer(
            const unsigned & points,
            const std::string & username);
}

#endif //SPACE_LEVEL_H
