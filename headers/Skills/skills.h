/*!
 * @file    skills.h
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Gestion des capacités lors du jeu
 * @version 1.0
 */

#ifndef SPACE_SKILLS_H
#define SPACE_SKILLS_H

#include "../GenerateGame/generateGame.h"
#include <iostream>
#include <vector>
#include <map>

/*!
 * @namespace nsSkills
 * @brief Espace de nom pour les capacités
 */
namespace nsSkills{

    /*!
     * @struct structSkills
     * @brief Variables nécessaires au fonctionnement des capacités
     */
    struct structSkills{
        unsigned timeEndSkills = 50; // Pour le max de munition
        unsigned timeEndSkills2 = 50; // Pour l'invinsibilité
        std::vector <std::string> currentSkills;
        std::string nameSkill;
        std::map <std::string, bool> skillsGot;
    };

    /*!
     * @brief Utilisation d'une capacité au hasard selon "maxAmmunition", "maxLifeShield", "invinsibility".
     * @param[in] skills : capacités disponible
     * @param[out] nameSkill : nom de la capacité utilisée
     * @fn void skills (const std::vector <std::string> & skills, std::string & nameSkill);
     */
    void skills (
            const std::vector <std::string> & skills,
            std::string & nameSkill);

    /*!
     * @brief Suppression de la capacité de la table de jeu (symbole dans le jeu : $)
     * @param[in/out] object : position de toutes les entitées
     * @param[in] i : indice de la capacité (symbole)
     * @fn void removeSkills (Sobject & object, const unsigned & i);
     */
    void removeSkills (
            Sobject & object,
            const unsigned & i);

    /*!
     * @brief Déplacement de la capacité sur la table de jeu (symbole dans le jeu : $)
     * @param[in/out] tableOfGame : table de jeu
     * @param[in/out] object : position de toutes les entitées
     * @param[in] game : variables de la table de jeu
     * @param[in/out] skillsGot : capacité active ou non
     * @param[in] nameSkill : nom de la capacité utilisée
     * @fn void moveSkills(std::vector<std::string> & tableOfGame, Sobject & object, const nsVariables::configGame & game, std::map <std::string, bool> & skillsGot, const std::string & nameSkill);
     */
    void moveSkills(
            std::vector<std::string> & tableOfGame,
            Sobject & object,
            const nsVariables::configGame & game,
            std::map <std::string, bool> & skillsGot,
            const std::string & nameSkill);

    /*!
     * @brief Ajout de la capacité sur la table de jeu (symbole dans le jeu : $)
     * @param[in/out] tableOfGame : table de jeu
     * @param object : position de toutes les entitées
     * @param indice : indice de la capacité
     * @fn void generateSkills(std::vector<std::string> & tableOfGame, Sobject & object, const unsigned & indice);
     */
    void generateSkills(
            std::vector<std::string> & tableOfGame,
            Sobject & object,
            const unsigned & indice);

    /*!
     * @brief Ajout des capacités au joueur
     * @param tableOfGame : table de jeu
     * @param object : position de toutes les entitées
     * @param[in] game : variables de la table de jeu
     * @param skills : structure contenant les variables pour le fonctionnement des capacités
     * @param playerLife : vie du joueur
     * @param playerLifeStock : stock temporaire de la vie du joueur
     * @param protectLife : vie de la protection
     * @param countForPlayerShoot : counter pour les tirs du joueur
     * @fn void addSkillsToPlayer( std::vector<std::string> & tableOfGame, Sobject & object, const nsVariables::configGame & game, structSkills & skills, unsigned & playerLife, unsigned & playerLifeStock, unsigned & protectLife, unsigned & countForPlayerShoot);
     */
    void addSkillsToPlayer(
            std::vector<std::string> & tableOfGame,
            Sobject & object,
            const nsVariables::configGame & game,
            structSkills & skills,
            unsigned & playerLife,
            unsigned & playerLifeStock,
            unsigned & protectLife,
            unsigned & countForPlayerShoot);

    /*!
     * @brief Affichage des capacités
     * @param skills : structure contenant les variables pour le fonctionnement des capacités
     * @fn void displaySkills(structSkills & skills);
     */
    void displaySkills(structSkills & skills);
}



#endif //SPACE_SKILLS_H
