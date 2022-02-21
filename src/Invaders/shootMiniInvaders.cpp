/*!
 * @file    shootMiniInvaders.h
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Toutes les actions en lien avec les tirs des mini invaders
 * @version 1.0
 */
#include <stdlib.h>
#include "../../headers/Invaders/invaders.h"

using namespace nsVariables;

void nsInvaders::verifShootMiniInvaders(std::vector<std::string> & tableOfGame, Sobject & object, std::vector<unsigned> & whichMiniInvaders, const configGame & game) {
    // On verifie si le missile peut se déplacer verticalement sans toucher un autre miniinvader
    for (unsigned i(0); i < object.miniInvaders.size(); ++i)    //Pour tous les mini invaders
    {
        unsigned j (object.miniInvaders[i].nLine + 1);
        for (; ;)
        {
            if (j == game.KSizeLine - 3)    //Si, le missile se trouve sur la dernière ligne
            {
                whichMiniInvaders.push_back(i); //On ajoute le mini invader
                break;
            }
            if (tableOfGame[j][object.miniInvaders[i].nColumn] == game.KEmpty)  //S'il y a aucun mini invader sur la prochaine ligne, on vérifie pour la ligne suivante
                ++j;
            else    //Sinon, on arrête
                break;
        }
    }
}//verifShootMiniInvaders()

void nsInvaders::startShoot(std::vector<std::string> &tableOfGame, Sobject & object,
                            std::vector<unsigned> & whichMiniInvaders) {
    if (whichMiniInvaders.size() != 0)  //Si aucun mini invader ne gène, alors fait tirer un mini invader au hasard
    {
        unsigned choiceOfMiniInvader = rand() % whichMiniInvaders.size();
        /* Ajout du vecteur pos pour le missile (On ajoute ici un seul missile à la fois, il suffit d'augmenter
        choiceOfMiniInvader pour en avoir plusieurs, on choisit n nombres aléatoires)*/
        object.missile.push_back(pos{object.miniInvaders[whichMiniInvaders[choiceOfMiniInvader]].nLine,object.miniInvaders[whichMiniInvaders[choiceOfMiniInvader]].nColumn});
    }
    whichMiniInvaders = {}; //On réinitialise le vecteur
}//startShoot()

