//
/*!
 * @file    rank.cpp
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Gestion du classement des joueurs
 * @version 1.0
 */
#include "../../headers/Rank/rank.h"

#include <map>

using namespace std;
using namespace nsManipulateFile;

void nsRank::ranking(map <unsigned ,string> & mapPoints, const unsigned & points, const string & username)    //Procédure permettant de faire le classement
{
    extractionRank (mapPoints, points, username, "Classement");  //On extrait tous les nom d'utilisateurs et les points
    mapPoints[points] = username;   //On ajoute le joueur actuelle et son nombre de points
    if (mapPoints.size() > 10)  //Puisque que l'on veut un classement des 10 meilleurs joueurs, alors on supprimera le nombre de points le plus bas
    {
        unsigned min;
        minUnsignedInMap(mapPoints,min);    //Pour cela, on utilise une fonction qui cherche la valeur minimum parmi les clés de la map
        mapPoints.erase(min);   //Et on supprime ce minimum
    }
    insertionRank (mapPoints, "Classement");  //lorsqu'ils sont triés grâce à la map, on les insére dans le fichier
}//ranking()

void nsRank::minUnsignedInMap(const map <unsigned ,std::string> & myMap, unsigned & min)   //Pour trouver le plus petit entier naturel dans une map
{
    vector <unsigned> allKeys;
    for (auto const & element : myMap)  //On récupère toutes les clés et on les mets dans un vecteur
        allKeys.push_back(element.first);
    min = allKeys[0];
    for (unsigned i(1); i < allKeys.size(); ++i)    //Puis, on les tries
    {
        if (allKeys[1] < allKeys[0])
            min = allKeys[1];
    }
}//minUnsignedInMap()

