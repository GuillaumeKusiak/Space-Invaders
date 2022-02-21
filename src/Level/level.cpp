/*!
 * @file    level.cpp
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Gestion du niveau des joueurs
 * @version 1.0
 */

#include "../../headers/Level/level.h"
#include <iostream>
#include <map>

using namespace std;
using namespace nsManipulateFile;

void nsLevel::levelSystem(const unsigned & points)
{
    unsigned levelPlayer (1);
    unsigned levelPoints (20);
    while (points > levelPoints)
    {
        ++levelPlayer;
        levelPoints *= 2;
    }
    cout << "Vous êtes niveau " << levelPlayer << " !"<< endl;
}//levelSystem()

void nsLevel::levelPlayer (const unsigned & points, const string & username)
{
    map <string, unsigned> mapLevel;
    extractionLevel(mapLevel, points, username, "expPlayer");
    map <string, unsigned>::iterator it;
    it = mapLevel.find(username);
    if (it != mapLevel.end())
        mapLevel[username] += points;
    else
        mapLevel[username] = points;
    insertionLevel(mapLevel,"expPlayer");
    levelSystem(mapLevel[username]);

}//levelPlayer()