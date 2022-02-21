/*!
 * @file    generateGame.cpp
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Génération de la table de jeu
 * @version 1.0
 */
#include "../../headers/GenerateGame/generateGame.h"
using namespace std;
using namespace nsVariables;


/* Generate the table of game */
vector <string> nsGenerateGame::generateTableOfGame(const configGame & game) {
    vector <string> tableOfGame(game.KSizeSpace);
    for (unsigned i(0); i < game.KSizeSpace; ++i)    //On remplit le vecteur de case vide
    {
        for (unsigned j(0); j < game.KSizeLine; ++j)
        {
            tableOfGame[i] += game.KEmpty;
        }
    }
    return tableOfGame;
}//generateTableofGame()

/* Add all entities in the game */
vector <string> nsGenerateGame::addAllEntities(std::vector<std::string> &tableOfGame, Sobject & object, const configGame & game, const bool & withSpaceShip) {
    for (unsigned i(0); i < game.KInvadersSize; ++i)    //On ajoute tous les invaders sur la table de jeu
    {
        object.invader.push_back(pos{0,i});
    }
    if (withSpaceShip)
    {
        object.spaceShip.push_back(pos{game.KSizeSpace - 1, game.KSizeLine / 2 - 1});   //On ajoute le joueur sur la table de jeu
        object.spaceShip.push_back(pos{game.KSizeSpace - 1, game.KSizeLine / 2});
    }
    /* Pour la protection */
    object.protection.push_back(pos{game.KSizeSpace - 3, game.KSizeLine / 2 - 1});   //On ajoute le joueur sur la table de jeu
    object.protection.push_back(pos{game.KSizeSpace - 3, game.KSizeLine / 2});

    /* - */

    for (unsigned i(2); i < game.KNumberMiniInvaders + 2; ++i)  //On ajoute tous les mini invaders sur la table de jeu
    {
        for (unsigned j(0); j < game.KSizeLine; ++j)
        {
            object.miniInvaders.push_back(pos{i,j});
        }
    }
    return tableOfGame;
}//addAllEntities()


vector <string> nsGenerateGame::addProtect(std::vector<std::string> &tableOfGame, Sobject &object,
                                           const nsVariables::configGame &game) {
    object.protection.push_back(pos{game.KSizeSpace - 3, game.KSizeLine / 2 - 1});   //On ajoute le joueur sur la table de jeu
    object.protection.push_back(pos{game.KSizeSpace - 3, game.KSizeLine / 2});
    return tableOfGame;
}

