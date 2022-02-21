/*!
 * @file    generateGame.h
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Génération de la table de jeu
 * @version 1.0
 */

#ifndef SPACEINVADERS_GENERATEGAME_H
#define SPACEINVADERS_GENERATEGAME_H

#include "../Variables/variables.h"
#include <vector>
#include <string>
#include <map>

/*!
 * @struct pos
 * @brief Deux positions nLine : ligne, nColumn : colonne
 */
struct pos {
    size_t nLine;
    size_t nColumn;
};

/*!
 * @struct Sobject
 * @brief Regroupe tous les vecteurs <pos> des entities sur la table du jeu
 */
struct Sobject
{
    std::vector <pos> invader; // Pour l'Invader
    std::vector <pos> missile; // Pour les missiles
    std::vector <pos> spaceShip; // Pour le spaceShip
    std::vector <pos> torpedo; // Pour les torpilles
    std::vector <pos> miniInvaders; // Pour les mini Invaders
    std::vector <pos> protection; // Pour la protection
    std::vector <pos> skills; // Pour les skills
};

/*!
 * @struct GameConfigure
 * @brief Regroupe toutes les maps contenant les configurations du jeu
 */
struct GameConfigure
{
    std::map<std::string, char> GameConfigChar; // Pour les caractères
    std::map<std::string, unsigned> GameConfigUnsigned; // Pour les entiers
    std::map<std::string, std::string> GameConfigString; // Pour les strings
};

/**
 * @namespace nsGenerateGame
 * @brief Espace de nom pour la génération de la table de jeu
 */
namespace nsGenerateGame
{
    /*!
     * @brief Génère la table du jeu
     * @param[in] game : variables de la table du jeu
     * @return vector<std::string>
     * @fn bool std::vector<std::string> generateTableOfGame(const nsVariables::configGame & game);;
     */
    std::vector<std::string> generateTableOfGame(
            const nsVariables::configGame & game);


    /*!
     * @brief Ajout de toutes les entitées
     * @param[in/out] tableOfGame : table de jeu
     * @param[in/out] object : position de toutes les entitées
     * @param[in] game : variables de la table de jeu
     * @param[in] withSpaceShip : avec ou sans le vaisseau
     * @return vector<std::string> : table de jeu
     * @fn std::vector<std::string> addAllEntities(std::vector <std::string> & tableOfGame, Sobject & object, const nsVariables::configGame & game, const bool & withSpaceShip);
     */
    std::vector<std::string> addAllEntities(
            std::vector <std::string> & tableOfGame,
            Sobject & object,
            const nsVariables::configGame & game,
            const bool & withSpaceShip);


    /*!
     * @brief Ajout de la protection sur la table de jeu (symbole dans le jeu : -)
     * @param[in/out] tableOfGame : table de jeu
     * @param[in/out] object : position de toutes les entitées
     * @param[in] game : variables de la table de jeu
     * @return vector<std::string> : table de jeu
     * @fn std::vector<std::string> addProtect(std::vector <std::string> & tableOfGame, Sobject & object, const nsVariables::configGame & game);
     */
    std::vector<std::string> addProtect(
            std::vector <std::string> & tableOfGame,
            Sobject & object,
            const nsVariables::configGame & game);

    /*!
     * @brief Affichage de la table de jeu
     * @param[in/out] tableOfGame : table de jeu
     * @param[in] game : variables de la table de jeu
     * @fn void display(std::vector<std::string> & tableOfGame, const nsVariables::configGame & game);
     */
    void display(
            std::vector<std::string> & tableOfGame,
            const nsVariables::configGame & game,
            unsigned & protectLife);

    /*!
     * @brief Mise à jour de la table de jeu
     * @param[in/out] tableOfGame : table de jeu
     * @param[in/out] object : position de toutes les entitées
     * @param[in] game : variables de la table de jeu
     * @fn void updateTableOfGame(std::vector<std::string> & tableOfGame, Sobject object, const nsVariables::configGame & game);
     */
    void updateTableOfGame(
            std::vector<std::string> & tableOfGame,
            Sobject object,
            const nsVariables::configGame & game);


    /*!
     * @brief Mettre des couleurs dans le terminal
     * @param[in] coul : code de la couleur
     * @fn void couleur(const std::string &coul);
     */
    void couleur(
            const std::string & coul);

    /*!
     * @brief affichage des protections avec des couleurs
     * @param[in/out] tableOfGame : table de jeu
     * @param[in] line : ligne
     * @param[in] column : colonne
     * @param[in/out] protectLife : vies de la protection
     * @fn void colorProtect(std::vector<std::string> & tableOfGame, const unsigned & line, const unsigned & column, unsigned & protectLife);
     */
    void colorProtect(
            std::vector<std::string> & tableOfGame,
            const unsigned & line,
            const unsigned & column,
            unsigned & protectLife);
}

#endif //SPACEINVADERS_GENERATEGAME_H
