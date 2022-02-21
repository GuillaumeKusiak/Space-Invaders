/*!
 * @file    invader.h
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Toutes les actions en lien avec les mini-envahisseurs et l'envahisseur
 * @version 1.0
 */

#ifndef SPACEINVADERS_INVADERS_H
#define SPACEINVADERS_INVADERS_H

#include "../GenerateGame/generateGame.h"

/*!
 * @namespace nsInvaders
 * @brief Espace de nom pour les mini-envahisseurs et l'envahisseur
 */
namespace nsInvaders
{
    // Pour les mini envahisseurs
    /*!
     * @brief Déplacement des mini-envahisseurs (symbole dans le jeu : m)
     * @param[in/out] tableOfGame : table de jeu
     * @param[in/out] object : position de toutes les entitées
     * @param[in/out] playerLife : vies du joueur
     * @param[in/out] points : points du joueur
     * @param[in] game : variables de la table de jeu
     * @fn : void moveMiniInvaders(std::vector <std::string> & tableOfGame, Sobject & object, unsigned & playerLife, unsigned & points, const nsVariables::configGame & game);
     */
    void moveMiniInvaders(
            std::vector <std::string> & tableOfGame,
            Sobject & object,
            unsigned & playerLife,
            unsigned & points,
            const nsVariables::configGame & game);

    /*!
     * @brief On supprime le mini-envahisseur (symbole dans le jeu : m)
     * @param[in/out] object : position de toutes les entitées
     * @param[in] i : indice du mini-envahisseur
     * @fn void RemoveMiniInvaders (Sobject & object, const unsigned & i);
     */
    void RemoveMiniInvaders (
            Sobject & object,
            const unsigned & i);

    /*!
     * @brief On verifie si le missile peut se déplacer verticalement sans toucher un autre mini-envahisseur
     * @param[in/out] tableOfGame : table de jeu
     * @param[in/out] object : position de toutes les entitées
     * @param[in/out] whichMiniInvaders : les mini-envahisseurs pouvant tirer
     * @param[in] game : variables de la table de jeu
     * @fn void verifShootMiniInvaders(std::vector<std::string> & tableOfGame, Sobject & object, std::vector<unsigned> & whichMiniInvaders, const nsVariables::configGame & game);
     */
    void verifShootMiniInvaders(
            std::vector<std::string> & tableOfGame,
            Sobject & object,
            std::vector<unsigned> & whichMiniInvaders,
            const nsVariables::configGame & game);

    /*!
     * @brief On place le missile au niveau du mini-envahisseur
     * @param[in/out] tableOfGame : table de jeu
     * @param[in/out] object : position de toutes les entitées
     * @param[in/out] whichMiniInvaders : les mini-envahisseurs pouvant tirer
     * @fn void startShoot(std::vector<std::string> & tableOfGame, Sobject & object, std::vector<unsigned> & whichMiniInvaders);
     */
    void startShoot(
            std::vector<std::string> & tableOfGame,
            Sobject & object,
            std::vector<unsigned> & whichMiniInvaders);



    // Pour l'envahisseur
    /*!
     * @brief On supprime l'envahisseur (symbole dans le jeu : W)
     * @param[in/out] object : position de toutes les entitées
     * @param[in] i : indice de l'envahisseur
     * @param[in] game : variables de la table de jeu
     * @fn void RemoveInvader (Sobject & object, const unsigned & i, const nsVariables::configGame & game);
     */
    void RemoveInvader (
            Sobject & object,
            const unsigned & i,
            const nsVariables::configGame & game);

    /*!
     * @brief Déplacement de l'envahisseur à gauche (symbole dans le jeu : W)
     * @param[in/out] tableOfGame : table de jeu
     * @param[in/out] object : position de toutes les entitées
     * @param[in] game : variables de la table de jeu
     * @fn void moveInvaderLeft(std::vector<std::string> & tableOfGame, Sobject & object, const nsVariables::configGame & game);
     */
    void moveInvaderLeft(
            std::vector<std::string> & tableOfGame,
            Sobject & object,
            const nsVariables::configGame & game);

    /*!
     * @brief Déplacement de l'envahisseur à gauche (symbole dans le jeu : W)
     * @param[in/out] tableOfGame : table de jeu
     * @param[in/out] object : position de toutes les entitées
     * @param[in] game : variables de la table de jeu
     * @fn void moveInvaderRight(std::vector<std::string> & tableOfGame, Sobject & object, const nsVariables::configGame & game);
     */
    void moveInvaderRight(
            std::vector<std::string> & tableOfGame,
            Sobject & object,
            const nsVariables::configGame & game);

    /*!
     * @brief Prédiction du nombre de mouvement du mini envahisseur pour arriver à la même colonne que l'envahisseur
     * @param[in/out] object : position de toutes les entitées
     * @param[in] i : indice de l'envahisseur
     * @param[in] indexMiniInvader : indice du mini envahisseur
     * @param[in/out] index : nombre de mouvement
     * @param game : variables de la table de jeu
     * @fn void moveRightVerifShootInvader (Sobject & object, const unsigned & i, const unsigned & indexMiniInvader, unsigned & index, const nsVariables::configGame & game);
     */
    void moveRightVerifShootInvader (
            Sobject & object,
            const unsigned & i,
            const unsigned & indexMiniInvader,
            unsigned & index,
            const nsVariables::configGame & game);

    /*!
     * @brief Prédiction du nombre de mouvement du mini envahisseur pour arriver à la même colonne que l'envahisseur
     * @param[in/out] object : position de toutes les entitées
     * @param[in] i : indice de l'envahisseur
     * @param[in] indexMiniInvader : indice du mini envahisseur
     * @param[in/out] index : nombre de mouvement
     * @fn void moveLeftVerifShootInvader (Sobject & object, const unsigned & i, const unsigned & indexMiniInvader, unsigned & index);
     */
    void moveLeftVerifShootInvader (
            Sobject & object,
            const unsigned & i,
            const unsigned & indexMiniInvader,
            unsigned & index);

    /*!
     * @brief Vérification principale du tir de l'envahisseur
     * @param[in/out] object : position de toutes les entitées
     * @param[in] i : indice de l'envahisseur
     * @param[in] game : variables de la table de jeu
     * @return 0 si le l'invader peut tirer, 1 sinon
     * @fn bool verifShootInvader(Sobject & object, const unsigned & i, const nsVariables::configGame & game);
     */
    bool verifShootInvader(
            Sobject & object,
            const unsigned & i,
            const nsVariables::configGame & game);

    /*!
     * @brief On place le missile au niveau de l'envahisseur
     * @param[in/out] tableOfGame : table de jeu
     * @param[in/out] object : position de toutes les entitées
     * @param[in] game : variables de la table de jeu
     * @fn void shootInvader(std::vector<std::string> & tableOfGame, Sobject & object, const nsVariables::configGame & game);
     */
    void shootInvader(
            std::vector<std::string> & tableOfGame,
            Sobject & object,
            const nsVariables::configGame & game);
}

#endif //SPACEINVADERS_INVADERS_H
