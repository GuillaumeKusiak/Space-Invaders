/*!
 * @file    shootInvader.cpp
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Toutes les actions en lien avec le tir de l'invader
 * @version 1.0
 */

#include "../../headers/Invaders/invaders.h"
using namespace nsVariables;

void nsInvaders::moveRightVerifShootInvader(Sobject &object, const unsigned int &i, const unsigned int &indexMiniInvader,
                                           unsigned int & index, const configGame & game) {
    if (object.miniInvaders[indexMiniInvader].nColumn <= object.invader[i].nColumn) //Si le mini invader se trouve à gauche de l'invader
        index += object.invader[i].nColumn - object.miniInvaders[indexMiniInvader].nColumn; //Alors on calcul le nombre de case qu'il y a entre le mini invader et l'invader
    else    //Sinon, on calcul le nombre de case qu'il y a entre le mini invader et la case tout à droite + le nombre de case entre la case tout à droite et le invader invader
        index+= (game.KSizeLine - object.miniInvaders[indexMiniInvader].nColumn) + (object.miniInvaders[indexMiniInvader].nColumn - object.invader[i].nColumn);
}//moveRightVerifShootInvader()

void nsInvaders::moveLeftVerifShootInvader(Sobject &object, const unsigned int &i, const unsigned int &indexMiniInvader, 
                                            unsigned int &index) {
    if (object.invader[i].nColumn <= object.miniInvaders[indexMiniInvader].nColumn) //Si le mini invader se trouve à droite de l'invader
        index += object.miniInvaders[indexMiniInvader].nColumn - object.invader[i].nColumn; //Alors on calcul le nombre de case qu'il y a entre le mini invader et l'invader
    else    //Sinon, on calcul le nombre de case entre la case tout à gauche et le mini invader + le nombre de case qu'il y a entre le mini invader et la case tout à gauche
        index += object.miniInvaders[indexMiniInvader].nColumn + (object.invader[i].nColumn - object.miniInvaders[indexMiniInvader].nColumn);
}//moveLeftVerifShootInvader()

bool nsInvaders::verifShootInvader(Sobject &object, const unsigned int & i, const configGame & game) {
    // On verifie si le missile peut se déplacer verticalement sans toucher un mini invader

    unsigned indexMiniInvader(0);
    while (indexMiniInvader < (object.miniInvaders.size() - 1)) //Pour tous les mini invaders
    {
        unsigned index(0);

        //On calcul combien de case il faut pour que le mini invader se trouve sur la même colonne que le mini invader
        if (object.miniInvaders[indexMiniInvader].nLine % 2 != 0)   //Si le mini invader bouge de gauche à droite
            moveLeftVerifShootInvader(object, i, indexMiniInvader, index);
        else
            moveRightVerifShootInvader(object, i, indexMiniInvader, index, game);

        if (index == (object.miniInvaders[indexMiniInvader].nLine - object.invader[i].nLine))   //Si le nombre de case précédemment calculé est égal au nombre de ligne entre l'invader et le mini invader
            return false;   //Alors l'invader ne tire pas
        ++indexMiniInvader;
    }
    return true;    //Si aucun mini invader se trouvera à l'endroit du missile, l'invader peut tirer
}//verifShootInvader()

void nsInvaders::shootInvader(std::vector<std::string> &tableOfGame, Sobject &object, const configGame & game) {
    if (verifShootInvader(object, 0, game)) //On vérifie si l'invader peut tirer avec sa case la plus à gauche
        object.missile.push_back(pos{object.invader[0].nLine + 1, object.invader[0].nColumn});
    if (verifShootInvader(object, game.KInvadersSize - 1, game))    //On vérifie si l'invader peut tirer avec sa case la plus à droite
        object.missile.push_back(pos{object.invader[0].nLine + 1, object.invader[0].nColumn});
}//shootInvader()