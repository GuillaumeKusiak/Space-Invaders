/*!
 * @file    rank.h
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Gestion du classement des joueurs
 * @version 1.0
 */
#ifndef SPACE_RANK_H
#define SPACE_RANK_H

#include "../ManipulateFile/manipulateFile.h"

/**
 * @namespace nsRank
 * @brief Espace de nom pour le classement des joueurs
 */
namespace nsRank {

    /*!
     * @brief Gestion du classement
     * @param[in/out] mapPoints : map contenant les points et les noms d'utilisateurs
     * @param[in] points : points du joueur
     * @param[in] username : nom d'utilisateur du joueur
     * @fn void ranking(std::map <unsigned ,std::string> & mapPoints, const unsigned & points, const std::string & username);
     */
    void ranking(std::map <unsigned ,std::string> & mapPoints, const unsigned & points, const std::string & username);

    /*!
     * @brief Gestion du classement
     * @param[in/out] mapPoints : map contenant les points et les noms d'utilisateurs
     * @param[in] points : points du joueur
     * @param[in] username : nom d'utilisateur du joueur
     * @fn void ranking(std::map <unsigned ,std::string> & mapPoints, const unsigned & points, const std::string & username);
     */
    void minUnsignedInMap(const std::map <unsigned , std::string> & myMap, unsigned & min);
}


#endif //SPACE_RANK_H
