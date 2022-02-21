/*!
 * @file    miniInvaders.cpp
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Toutes les actions en lien avec les mini invaders.
 * @version 1.0
 */
#include "../../headers/Invaders/invaders.h"

using namespace nsVariables;

void nsInvaders::moveMiniInvaders(std::vector <std::string> &tableOfGame, Sobject & object, unsigned int &playerLife,
                                  unsigned int &points, const configGame & game) {
    for (int i(object.miniInvaders.size() - 1); i > - 1 ; --i)  //Pour tous les mini invaders
    {
        bool swapProcedure (false);

        if ((object.miniInvaders[i].nColumn == game.KSizeLine-1) || (object.miniInvaders[i].nColumn == 0)) //Présent en début ou en fin de ligne
        {
            if (((object.miniInvaders[i].nLine % 2 != 0) && (object.miniInvaders[i].nColumn != (game.KSizeLine - 1)))    //OU si le mini invader bouge de gauche à droite ET que le mini invader ne se trouve pas à la fin d'une ligne
                || ((object.miniInvaders[i].nLine % 2 == 0) && (object.miniInvaders[i].nColumn != 0))) //OU si le mini invader bouge de droite à gauche ET que le mini invader ne se trouve pas au début d'une ligne
                swapProcedure = true;    //Alors on échange de procédé
            else //Dans tous les autres cas on le laisse descendre d'une case
            {
                ++object.miniInvaders[i].nLine;
                tableOfGame[object.miniInvaders[i].nLine - 1][object.miniInvaders[i].nColumn] = game.KEmpty;
            }
        }

        if (((object.miniInvaders[i].nColumn != (game.KSizeLine - 1)) && (object.miniInvaders[i].nColumn != 0)) || swapProcedure)    //Si le mini invader ne se trouve pas en fin ou en début de ligne OU qu'il faut changer de procédure
        {
            if (object.miniInvaders[i].nLine % 2 != 0)  //Si le mini invader bouge de gauche à droite, on le fait bouger d'une case à droite
            {
                ++object.miniInvaders[i].nColumn;
                tableOfGame[object.miniInvaders[i].nLine][object.miniInvaders[i].nColumn - 1] = game.KEmpty;
            }
            else    //Si le mini invader bouge de droite à gauche, on le fait bouger d'une case à droite
            {
                --object.miniInvaders[i].nColumn;
                tableOfGame[object.miniInvaders[i].nLine][object.miniInvaders[i].nColumn + 1] = game.KEmpty;
            }
        }
    }
}//moveMiniInvaders()

void nsInvaders::RemoveMiniInvaders(Sobject & object, const unsigned int & i){
    unsigned indice = i;    //L'indice du mini invader qu'il faut supprimer
    while (indice < object.miniInvaders.size()-1)   //On amène le mini invader à supprimer à la fin du vecteur
    {
        std::swap(object.miniInvaders[indice],object.miniInvaders[indice+1]);
        ++indice;
    }
    object.miniInvaders.resize(object.miniInvaders.size()-1);    //Puis, on resize le vecteur pour le supprimer
}//RemoveMiniInvaders()

