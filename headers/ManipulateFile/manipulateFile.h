/*!
 * @file    manipulateFile.h
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Manipulation de fichier pour l'extraction et l'insertion des points
 * @version 1.0
 */

#ifndef SPACE_MANIPULATEFILE_H
#define SPACE_MANIPULATEFILE_H

#include "../GenerateGame/generateGame.h"
#include <map>

/**
 * @namespace nsManipulateFile
 * @brief Espace de nom pour manipuler les fichiers
 */
namespace nsManipulateFile {

    /*!
     * @brief Extraction du classement de tous les joueurs
     * @param[in/out] mapPoints : map contenant les points et les noms d'utilisateurs
     * @param[in] points : points du joueur
     * @param[in] username : nom d'utilisateur du joueur
     * @param[in] nameInputFile : nom du fichier source
     * @fn void extractionRank (std::map <unsigned ,std::string> & mapPoints, const unsigned & points, const std::string & username, const std::string & nameInputFile);
     */
    void extractionRank (std::map <unsigned ,std::string> & mapPoints, const unsigned & points, const std::string & username, const std::string & nameInputFile);

    /*!
     * @brief Insertion du classement de tous les joueurs
     * @param[in/out] mapPoints : map contenant les points et les noms d'utilisateurs
     * @param[in] nameOutputFile : nom du fichier source
     * @fn void insertionRank (std::map <unsigned ,std::string> & mapPoints, const std::string & nameOutputFile);
     */
    void insertionRank (std::map <unsigned ,std::string> & mapPoints, const std::string & nameOutputFile);

    /*!
     * @brief Extraction de l'expérience de tous les joueurs
     * @param[in/out] mapPoints : map contenant les points et les noms d'utilisateurs
     * @param[in] points : points du joueur
     * @param[in] username : nom d'utilisateur du joueur
     * @param[in] nameInputFile : nom du fichier source
     * @fn void extractionLevel (std::map <std::string ,unsigned > & mapPoints, const unsigned & points, const std::string & username, const std::string & nameInputFile);
     */
    void extractionLevel (std::map <std::string ,unsigned > & mapPoints, const unsigned & points, const std::string & username, const std::string & nameInputFile);

    /*!
     * @brief Insertion de l'expérience de tous les joueurs
     * @param[in/out] mapPoints : map contenant les points et les noms d'utilisateurs
     * @param[in] nameOutputFile : nom du fichier source
     * @fn void insertionLevel (std::map <std::string ,unsigned > & mapPoints, const std::string & nameOutputFile);
     */
    void insertionLevel (std::map <std::string ,unsigned > & mapPoints, const std::string & nameOutputFile);
}

#endif //SPACE_MANIPULATEFILE_H
