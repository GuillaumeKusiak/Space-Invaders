/*!
 * @file    gameLoop.cpp
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Configuration de la boucle du jeu
 * @version 1.0
 */

#include "../../headers/GameLoop/gameLoop.h"
#include "../../headers/Canonique/setInputMode.h"
#include "../../headers/Torpedos/torpedos.h"
#include "../../headers/Missiles/missiles.h"
#include "../../headers/Invaders/invaders.h"
#include <iostream>

using namespace std;
using namespace nsGenerateGame;
using namespace nsSetInputMode;
using namespace nsTorpedos;
using namespace nsMissiles;
using namespace nsInvaders;
using namespace nsVariables;
using namespace nsSkills;


void nsGameLoop::transitionMoveInvader(std::vector<std::string> & tableOfGame, Sobject &object,
                                       const nsVariables::configGame & game, bool & side){
    if (object.invader[object.invader.size() - 1].nColumn == game.KSizeLine - 1)
        side = true;    //L'invader se trouve tout à droite
    else if (object.invader[0].nColumn == 0)
        side = false;   //L'invader se trouve à gauche

    if (!side)    //Si l'invader se trouve tout à gauche
        moveInvaderRight(tableOfGame, object, game);
    else    //Si l'invader se trouve tout à droite
        moveInvaderLeft(tableOfGame, object, game);
    if (object.invader.size() != 0)
        shootInvader(tableOfGame, object, game);

}//transitionMoveInvader()

void nsSkills::addSkillsToPlayer(std::vector<std::string> & tableOfGame, Sobject & object,
                                 const nsVariables::configGame & game, structSkills & skills, unsigned int & playerLife,
                                 unsigned int & playerLifeStock, unsigned int & protectLife,
                                 unsigned int & countForPlayerShoot) {

    if (skills.skillsGot["maxAmmunition"]) // Max de munition
    {
        --skills.timeEndSkills;
        countForPlayerShoot = 11;
        skills.currentSkills.push_back("maxAmmunition");
        if (skills.timeEndSkills == 0)
        {
            skills.timeEndSkills = 50;
            countForPlayerShoot = 0;
            skills.skillsGot["maxAmmunition"] = false;
        }
    }
    if (skills.skillsGot["maxLifeShield"]) // + 5 à la vie de la protection
    {
        skills.currentSkills.push_back("maxLifeShield");
        protectLife += 5;
        if (object.protection.size() == 0)
        {
            addProtect(tableOfGame,object,game);
        }
        skills.skillsGot["maxLifeShield"] = false;
    }
    if (skills.skillsGot["invincibility"])
    {
        skills.currentSkills.push_back("invincibility"); // invinsibilité
        if (skills.timeEndSkills2 == 50)
            playerLifeStock = playerLife + 1; // on stock la vie du joueur
        playerLife = playerLifeStock;
        --skills.timeEndSkills2;
        if (skills.timeEndSkills2 == 0)
        {
            skills.timeEndSkills2 = 50;
            skills.skillsGot["invincibility"] = false;
            playerLife -= 1;
        }

    }
}//addSkillsToPlayer

void nsGameLoop::setDifficulty(const unsigned int & nbGame, unsigned int & count) {
    if (nbGame == 1)
        count = 15; // Easy
    if (nbGame == 2)
        count = 13; // Medium
    if (nbGame == 3)
        count = 11; // Hard
}//setDifficulty

void nsSkills::displaySkills(structSkills & skills) {
    for (unsigned i(0); i < skills.currentSkills.size(); ++i)
        cout << skills.currentSkills[i] << ' ';
    cout << endl;
    skills.currentSkills = {};
}//DisplaySkills


void nsGameLoop::gameLoop(std::vector<std::string> &tableOfGame, Sobject &object, unsigned int & points,
                          unsigned int & playerLife, const nsVariables::configGame & game, unsigned int & protectLife, structSkills & skills) {

    unsigned nbGame(1); // nombres de parties
    unsigned count; // Pour les niveaux
    unsigned countForTorpedo (0), countForPlayerShoot (0), countForInvader (0), countForMiniInvader (0); // Initialisation des variables

    skills.skillsGot["maxAmmunition"] = false;
    skills.skillsGot["maxLifeShield"] = false;
    skills.skillsGot["invinsibility"] = false;

    bool side; // booléen permettant de vérifier si l'invader est au bord du jeu
    vector <unsigned> whichMiniInvaders;    //Les mini invaders pouvant tirer
    unsigned playerLifeStock; // on stock la vie du joueur
    while(1)    //Boucle infini qui fait marcher constamment le jeu et se fini lorsque le jeu est terminé
    {
        setDifficulty(nbGame, count); // On diffère la vitesse des mouvements des invaders et mini invaders selon la difficulté
        input(object, tableOfGame, points, countForPlayerShoot, game);  //On vérifie si le joueur à taper une touche
        updateTableOfGame(tableOfGame, object, game);   //Met à jour la table du jeu

        if (countForMiniInvader == count)
        {
            moveMiniInvaders(tableOfGame, object, playerLife, points, game);    //On fait bouger le mini invader
            verifShootMiniInvaders(tableOfGame, object, whichMiniInvaders, game);// on vérifie les mini Invaders pouvant tirer
            startShoot(tableOfGame,object, whichMiniInvaders);  //On fait tirer un des mini invaders
            countForMiniInvader = 0;    //On réinitialise le compteur
        }
        if (countForInvader == count)
        {
            nsGameLoop::transitionMoveInvader(tableOfGame, object, game, side); // fonction permettant de réaliser le mouvement de l'Invader
            countForInvader = 0;//On réinitialise le compteur
        }

        addSkillsToPlayer(tableOfGame, object, game, skills, playerLife, playerLifeStock, protectLife, countForPlayerShoot); //Initialisation des capacités

        if (countForTorpedo == 2)   //On fait avancer les missiles et les torpedos
        {
            moveTorpedo(tableOfGame, object, points, game, skills.nameSkill); //Mouvement des torpedos
            moveMissile(tableOfGame, object, points, playerLife, game, protectLife); //Mouvement des missiles
            moveSkills(tableOfGame, object, game, skills.skillsGot, skills.nameSkill);
            countForTorpedo = 0;    //On reinitialise le compteur
        }

        display(tableOfGame, game, protectLife); //On affiche les bords de la table de jeu
        cout << "Vos points : " << "\033[" << "33" <<"m" << points << string(10,' ') << "Niveau du jeu : " << "\033[" << "32" <<"m" << nbGame << endl; // Affichage des points, et du niveau courant
        cout << playerLife << " vies" << " - " << protectLife << " vies pour la protection" << endl; // Affichage des vies et celles de la protection
        displaySkills(skills); // affichage des capacités

        if (object.invader.size() == 0 && object.miniInvaders.size() == 0)  //S'il n'y a plus d'invaders et de mini invaders, le joueur a gagné et on arrête la partie
        {
            if (nbGame < 3)
            {
                ++nbGame;
                object.miniInvaders.resize(0);
                object.invader.resize(0);
                addAllEntities(tableOfGame, object, game,0);
                protectLife = 4;
            }
            else
            {
                cout << "You won" << endl; // Victoire
                break;
            }
        }
        if (playerLife == 0)  //Si le joueur n'a plus de vie, alors il a perdu et on arrête la partie
        {
            cout << "You lose" << endl; // Défaite
            break;
        }
        if (protectLife == 0)
        {
            tableOfGame[object.protection[0].nLine][object.protection[0].nColumn] = game.KEmpty;
            tableOfGame[object.protection[1].nLine][object.protection[1].nColumn] = game.KEmpty;
            object.protection.resize(0); // on vide l'object
        }
        ++countForTorpedo, ++countForInvader, ++countForMiniInvader, ++countForPlayerShoot; //On augmente les compteurs de 1
    }
}//gameLoop()
