/*!
 * @file    main.cpp
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Fichier main, lancement du jeu
 * @version 1.0
 */

/*! \mainpage Page principale Space Invader
 *
 *
 * Pour lancer le jeu, executer le fichier SpaceInvader.
 *
 *
 * Le classement des joueurs est situé dans le fichier Classement
 *
 */


#include <iostream>
#include <ctime>
#include "../headers/GenerateGame/generateGame.h"
#include "../headers/GameLoop/gameLoop.h"
#include "../headers/Canonique/setInputMode.h"
#include "../headers/Yaml/yaml.h"
#include "../headers/Rank/rank.h"
#include "../headers/Level/level.h"

using namespace std;
using namespace nsGenerateGame;
using namespace nsGameLoop;
using namespace nsSetInputMode;
using namespace nsVariables;
using namespace nsYaml;
using namespace nsRank;
using namespace nsLevel;
using namespace nsSkills;

int main()
{
    typedef vector<string> VString;
    Sobject object; //On créer une struct pour regrouper tous les objets (invaders, joueur, mini invaders, missiles, torpedos)
    GameConfigure configure;    //On récupère la configuration par défaut du jeu (difficulté, les touches des mouvements, les touches de tirs, ...)
    configGame game;    //On récupère tous les autres paramètres + variables
    structSkills skills; // struct contenant les variables pour les capacités

    /* Pour les variables concerant le joueur */
    unsigned points = 0; // nombre de point
    unsigned playerLife = 3;  //Vie du joueur + Lecture du nombre de vie dans le fichier d'entrée
    unsigned protectLife = 4; // Vie de la protection



    initMap(configure, game); //On génère la carte
    readConfig(configure, "config.yaml", game); //On lit toutes les constantes

    string username;    //Nom d'utilisateur du joueur
    cout << "Entrer un nom d'utilisateur" << endl;
    cin >> username;

    srand(time(NULL));
    set_input_mode();   //?
    VString tableOfGame = generateTableOfGame(game);    //On génère la table de jeu
    addAllEntities(tableOfGame, object, game, 1);  //On ajoute tous les objets (invaders, joueur, mini invaders, missiles, torpedos)
    display(tableOfGame, game, protectLife); //On affiche les bords de la table de jeu
    gameLoop(tableOfGame, object ,points, playerLife, game, protectLife, skills);    //On appelle la fonction qui permet de jouer

    map <unsigned, string> mapPoints;   //On met à jour le classement
    ranking(mapPoints, points, username);
    levelPlayer(points, username);

    return 0;
}
