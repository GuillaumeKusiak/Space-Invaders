/*!
 * @file    missiles.cpp
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Toutes les actions en lien avec les missiles
 * @version 1.0
 */
#include "../../headers/Missiles/missiles.h"
#include "../../headers/Player/player.h"

using namespace nsPlayer;
using namespace nsVariables;

void nsMissiles::RemoveMissile(Sobject & object, const unsigned int & i){
    unsigned indice = i;    //L'indice du missile qu'il faut supprimer
    while (indice < object.missile.size()-1)    //On amène le missile à supprimer à la fin du vecteur
    {
        std::swap(object.missile[indice],object.missile[indice+1]);
        ++indice;
    }
    object.missile.resize(object.missile.size()-1); //Puis, on resize le vecteur pour le supprimer
}//RemoveMissile()


void nsMissiles::moveMissile(std::vector<std::string> & tableOfGame, Sobject & object, unsigned int & points,
                             unsigned int &playerLife, const configGame & game, unsigned & protectLife){
    if (object.missile.size() != 0) //Si il y a des missiles sur la table de jeu
    {
        for (unsigned i(0); i < object.missile.size(); ++i) //Pour tous les missiles
        {
            for (unsigned j(0); j < object.spaceShip.size();++j)    //Poiur toutes les cases du joueur
            {
                if (object.protection.size() != 0 && (object.missile[i].nColumn == object.protection[j].nColumn) && (object.missile[i].nLine==object.protection[j].nLine))   //Si il y a une collision
                {
                    --protectLife;   //On lui enlève une vie
                    tableOfGame[object.missile[i].nLine - 1][object.missile[i].nColumn] = game.KEmpty;
                    RemoveMissile(object, i);   //Sinon, on le supprime
                }
                if ((object.missile[i].nColumn==object.spaceShip[j].nColumn) && (object.missile[i].nLine==object.spaceShip[j].nLine))   //Si il y a une collision
                {
                    --playerLife;   //On lui enlève une vie
                    if (points >= 50)
                        points-=50;//On lui enlève 50 point
                    else
                        points = 0;
                }
            }
            if (object.missile[i].nLine != game.KSizeLine - 1)  //Si le missile n'est pas tout en bas
            {
                ++object.missile[i].nLine;  //On le fait descendre d'une ligne
                tableOfGame[object.missile[i].nLine - 1][object.missile[i].nColumn] = game.KEmpty;
            }
            else
            {
                tableOfGame[object.missile[i].nLine][object.missile[i].nColumn] = game.KEmpty;
                RemoveMissile(object, i);   //Sinon, on le supprime
            }
        }
    }
}//MoveMissile()
