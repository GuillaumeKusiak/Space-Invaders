/*!
 * @file    torpedos.cpp
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Toutes les actions des torpilles
 * @version 1.0
 */

#include "../../headers/Torpedos/torpedos.h"
#include "../../headers/Invaders/invaders.h"
#include "../../headers/Skills/skills.h"

using namespace nsInvaders;
using namespace nsVariables;
using namespace nsSkills;
using namespace std;

void nsTorpedos::RemoveTorpedo(Sobject & object, const unsigned int & i){
    unsigned indice = i;    //L'indice du torpedo qu'il faut supprimer
    while (indice < object.torpedo.size()-1)    //On amène le torpedo à supprimer à la fin du vecteur
    {
        std::swap(object.torpedo[indice],object.torpedo[indice+1]);
        ++indice;
    }
    object.torpedo.resize(object.torpedo.size()-1); //Puis, on resize le vecteur pour le supprimer
}//RemoveTorpedo()

void nsTorpedos::moveTorpedo(std::vector<std::string> & tableOfGame, Sobject & object, unsigned int & points, const configGame & game, string & nameSkill){
    if (object.torpedo.size() != 0) //Si il y a des torpedos sur la table de jeu
    {
        for (unsigned i(0); i < object.torpedo.size(); ++i) //Pour tous les torpedos
        {
            for (unsigned j(0); j < object.invader.size();++j)  //Poiur toutes les cases des invaders
            {
                if ((object.torpedo[i].nColumn==object.invader[j].nColumn) && (object.torpedo[i].nLine==object.invader[j].nLine))    //S'il y a une collision entre l'invader et le torpedo
                {
                    RemoveInvader(object, j, game); //On supprime l'invader
                    points+=20; //On lui rajoute 20 points
                }
            }
            if (object.protection.size() != 0 && (((object.torpedo[i].nColumn == object.protection[0].nColumn) && (object.torpedo[i].nLine == object.protection[0].nLine))
                || ((object.torpedo[i].nColumn == object.protection[1].nColumn) && (object.torpedo[i].nLine == object.protection[1].nLine))))
            {
                tableOfGame[object.torpedo[i].nLine][object.torpedo[i].nColumn]= game.KEmpty;
                RemoveTorpedo(object, i);   //On supprime le torpedo
            }
            for (unsigned j(0); j < object.miniInvaders.size();++j)
            {
                if ((object.torpedo[i].nColumn==object.miniInvaders[j].nColumn) && (object.torpedo[i].nLine==object.miniInvaders[j].nLine))  //S'il y a une collision entre le mini invader et le torpedo
                {
                    tableOfGame[object.torpedo[i].nLine][object.torpedo[i].nColumn]= game.KEmpty;
                    RemoveTorpedo(object, i);   //On supprime le torpedo
                    RemoveMiniInvaders(object, j);  //On supprime le mini invader
                    points+=10; //On lui rajoute 10 points

                    unsigned randGetSkills = rand()%10; //Chance d'obtenir une compétence'
                    if (randGetSkills < 2) {
                        skills(game.skills, nameSkill);
                        generateSkills(tableOfGame, object,j);
                    }
                }
            }
            if (object.torpedo[i].nLine!=0) //Si le torpedo ne se trouve pas sur la dernière ligne
            {
                --object.torpedo[i].nLine;  //On le fait descendre d'une ligne
                tableOfGame[object.torpedo[i].nLine+1][object.torpedo[i].nColumn]= game.KEmpty;
            }
            else
            {
                tableOfGame[object.torpedo[i].nLine][object.torpedo[i].nColumn]= game.KEmpty;
                RemoveTorpedo(object, i);   //On supprime le torpedo
            }
        }
    }
}//moveTorpedo()

