/*!
 * @file    updateTableOfGame.h
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Mise à jour de la table de jeu
 * @version 1.0
 */
#include "../../headers/GenerateGame/generateGame.h"
#include <iostream>
using namespace std;
using namespace nsVariables;

const string KReset   ("0");
const string KNoir    ("30");
const string KRouge   ("31");
const string KVert    ("32");
const string KJaune   ("33");
const string KBleu    ("34");
const string KMAgenta ("35");
const string KCyan    ("36");

void nsGenerateGame::couleur(const std::string &coul)
{
    cout << "\033[" << coul <<"m";
}//couleur()


void nsGenerateGame::updateTableOfGame(std::vector<std::string> &tableOfGame, Sobject object, const configGame & game) {  //On met à jour la table de jeu
    for (unsigned i(0); i < object.spaceShip.size(); ++i)
        tableOfGame[object.spaceShip[i].nLine][object.spaceShip[i].nColumn] = game.KInsideMe;
    for (unsigned i(0); i < object.torpedo.size(); ++i)
        tableOfGame[object.torpedo[i].nLine][object.torpedo[i].nColumn] = game.KTorpedo;
    for (unsigned i(0); i < object.invader.size(); ++i)
        tableOfGame[object.invader[i].nLine][object.invader[i].nColumn] = game.KInsideInvader;
    for (unsigned i(0); i < object.missile.size(); ++i)
        tableOfGame[object.missile[i].nLine][object.missile[i].nColumn] = game.KMissile;
    for (unsigned i(0); i < object.miniInvaders.size(); ++i)
        tableOfGame[object.miniInvaders[i].nLine][object.miniInvaders[i].nColumn] = game.KMiniInvaders;
    for (unsigned i(0); i < object.protection.size(); ++i)
        tableOfGame[object.protection[i].nLine][object.protection[i].nColumn] = game.KProtect;
    for (unsigned i(0); i < object.skills.size(); ++i)
        tableOfGame[object.skills[i].nLine][object.skills[i].nColumn] = game.KSkills;
}//updateTableOfGame()

void nsGenerateGame::colorProtect(vector<std::string> & tableOfGame, const unsigned & line, const unsigned & column, unsigned & protectLife)
{
    if (protectLife >= 4)
    {
        couleur(KVert);
        cout << tableOfGame[line][column] << ' ';
    }
    else if (protectLife == 3)
    {
        couleur(KJaune);
        cout << tableOfGame[line][column] << ' ';
    }
    else if (protectLife == 2)
    {
        couleur(KMAgenta);
        cout << tableOfGame[line][column] << ' ';
    }
    else if (protectLife == 1)
    {
        nsGenerateGame::couleur(KRouge);
        cout << tableOfGame[line][column] << ' ';
    }
}//colorProtect()


/* Display the table of game */
void nsGenerateGame::display(std::vector<std::string> & tableOfGame, const configGame & game, unsigned & protectLife) {
    std::system("clear");
    cout << endl;
    for (unsigned i(0); i < game.KSizeLine; ++i)    //On ajoute les bords de la table de jeu
    {
        couleur(KCyan);
        cout << "| ";
        for (unsigned j(0); j < game.KSizeSpace; ++j)
        {
            if (tableOfGame[i][j] == game.KMiniInvaders)
            {
                couleur(KJaune);
                cout << tableOfGame[i][j] << ' ';
            }
            else if (tableOfGame[i][j] == game.KInsideInvader)
            {
                couleur(KRouge);
                cout << tableOfGame[i][j] << ' ';
            }
            else if (tableOfGame[i][j] == game.KTorpedo)
            {
                couleur(KBleu);
                cout << tableOfGame[i][j] << ' ';
            }
            else if (tableOfGame[i][j] == game.KMissile)
            {
                couleur(KRouge);
                cout << tableOfGame[i][j] << ' ';
            }
            else if (tableOfGame[i][j] == game.KInsideMe)
            {
                couleur(KCyan);
                cout << tableOfGame[i][j] << ' ';
            }
            else if (tableOfGame[i][j] == game.KProtect)
                colorProtect(tableOfGame,i,j,protectLife);
            else
                cout << tableOfGame[i][j] << ' ';
        }
        couleur(KCyan);
        cout << " |" << endl;
    }
}//display()