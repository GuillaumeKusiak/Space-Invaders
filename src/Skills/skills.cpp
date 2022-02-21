//
// Created by gonzales on 12/01/2022.
//

#include "../../headers/Skills/skills.h"
#include "../../headers/GenerateGame/generateGame.h"

#include <iostream>

using namespace std;
using namespace nsVariables;


void nsSkills::skills (const vector <string> & skills, string & nameSkill)
{
    unsigned randomSkills(rand()%(skills.size()));
    if (skills[randomSkills] == skills[0])
        nameSkill = "maxAmmunition";
    else if (skills[randomSkills] == skills[1])
        nameSkill = "maxLifeShield";
    else if (skills[randomSkills] == skills[2])
        nameSkill ="invincibility";
}


void nsSkills::removeSkills(Sobject & object, const unsigned int &i) {
    unsigned indice = i;    //L'indice dé la compétence qu'il faut supprimer
    while (indice < object.skills.size()-1)    //On amène la compétence à supprimer à la fin du vecteur
    {
        std::swap(object.skills[indice],object.skills[indice+1]);
        ++indice;
    }
    object.skills.resize(object.skills.size()-1); //Puis, on resize le vecteur pour le supprimer
}//removeSkills()

void nsSkills::moveSkills(vector<string> &tableOfGame, Sobject & object, const nsVariables::configGame &game,
                          map<string, bool> &skillsGot, const string &nameSkill) {
    if (object.missile.size() != 0) //Si il y a des missiles sur la table de jeu
    {
        for (unsigned i(0); i < object.skills.size(); ++i) //Pour tous les skills
        {
            for (unsigned j(0); j < object.spaceShip.size();++j)    //Pour toutes les cases du joueur
            {
                if ((object.skills[i].nColumn == object.spaceShip[j].nColumn) && (object.skills[i].nLine==object.spaceShip[j].nLine))   //Si il y a une collision
                {
                    skillsGot[nameSkill] = true;
                    tableOfGame[object.missile[i].nLine - 1][object.missile[i].nColumn] = game.KEmpty;
                }
            }
            if (object.skills[i].nLine != game.KSizeLine - 1)  //Si le missile n'est pas tout en bas
            {
                ++object.skills[i].nLine;  //On le fait descendre d'une ligne
                tableOfGame[object.skills[i].nLine - 1][object.skills[i].nColumn] = game.KEmpty;
            }
            else
            {
                tableOfGame[object.skills[i].nLine][object.skills[i].nColumn] = game.KEmpty;
                removeSkills(object, i);   //Sinon, on le supprime
            }
        }
    }
}

void nsSkills::generateSkills(std::vector<std::string> &tableOfGame, Sobject &object, const unsigned & indice) {
        object.skills.push_back(pos{object.miniInvaders[indice].nLine + 1, object.miniInvaders[indice].nColumn});
}//generateSkills
