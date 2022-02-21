/*!
 * @file    invader.cpp
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Toutes les actions en lien avec l'Invader
 * @version 1.0
 */
#include "../../headers/Invaders/invaders.h"
using namespace nsVariables;

void nsInvaders::RemoveInvader(Sobject &object, const unsigned int & i, const configGame & game){
    unsigned indice = i;    //L'indice de l'invader qu'il faut supprimer
    while (indice < object.invader.size()-1)    //On amène l'invader à supprimer à la fin du vecteur
    {
        std::swap(object.invader[indice],object.invader[indice+1]);
        ++indice;
    }
    object.invader.resize(object.invader.size()-1); //Puis, on resize le vecteur pour le supprimer
}//RemoveInvader()

void nsInvaders::moveInvaderRight(std::vector<std::string> & tableOfGame, Sobject & object, const configGame & game) {
    for (int i(object.invader.size() - 1); i > - 1; --i)    //On parcours toutes le vecteur contenant les invaders
    {
        ++object.invader[i].nColumn;    //On les bouger d'une case vers la droite
        tableOfGame[object.invader[i].nLine][object.invader[i].nColumn - 1] = game.KEmpty;  //Puis, on remplace le caractère par une case vide
    }
}

void nsInvaders::moveInvaderLeft(std::vector<std::string> & tableOfGame, Sobject & object, const configGame & game) {
    for (int i(0); i < object.invader.size(); ++i)   //On parcours toutes le vecteur contenant les invaders
    {
        --object.invader[i].nColumn;    //On les bouger d'une case vers la gauche
        tableOfGame[object.invader[i].nLine][object.invader[i].nColumn + 1] = game.KEmpty;  //Puis, on remplace le caractère par une case vide
    }
}//moveInvaderLeft()
