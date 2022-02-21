/*!
 * @file    manipulateFile.cpp
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Manipulation de fichier pour l'extraction et l'insertion des points
 * @version 1.0
 */
#include "../../headers/ManipulateFile/manipulateFile.h"

#include <iostream>
#include <map>
#include <fstream>
using namespace std;

void nsManipulateFile::extractionRank (map <unsigned ,std::string> & mapPoints, const unsigned & points, const string & username, const string & nameInputFile)
{
    ifstream ifs(nameInputFile);   //On essaye d'ouvrir le fichier d'entrée
    if (!ifs) cerr << "Fichier non trouvé" << endl; //s'il ne s'ouvre pas, alors on arrête
    else    //Sinon, on récupère tous les noms d'utilisateurs et leur nombre de points
    {
        string mots;    //Variable pour extraire les noms d'utilisateurs
        unsigned NbEntier;     //Variable pour extraire leur nombre d epoints
        unsigned switchType (0);    //Variable permettant d'ajouter dans la map le nom d'utilisateur correspondant à son nombre de points
        for ( ; ; )
        {
            if (ifs.eof())  //A la fin du fichier d'entrée, on arrête la lecture
                break;
            if (switchType % 2 == 0)    //Tous les entier+2 on passe à une nouvelle ligne du fichier d'entrée et donc à un autre nom d'utilisateurs et son nombre d epoints
                ifs >> NbEntier;
            else
                ifs >> mots;

            if(ifs.fail())      //Si le caractère n'est pas compatible avec notre demande, alors on en choisis un autre
            {
                ifs.clear();
                char car;
                ifs.get(car);
            }
            else    //Sinon on ajoute le nom d'utilisateur et son nombre de points dans la map
            {
                ++switchType;
                if (((switchType %  2 == 0) && (switchType>1)))   //On l'intègre dans la map si on a un nom d'utilisateur et son nombre de points
                    mapPoints[NbEntier] = mots; //On les mets dans une map pour que ce soit directement trié et que les points soient associés au bon joueur
            }
        }
    }
}//extractionRank()

void nsManipulateFile::insertionRank (map <unsigned ,string> & mapPoints, const string & nameOutputFile)
{
    ofstream ofs (nameOutputFile);  //On essaye d'ouvrir le fichier de sortie
    if(!ofs) { cerr << "Fichier non trouvé" << endl; //s'il ne s'ouvre pas, alors on arrête
    }
    else    //S'il s'ouvre, on va insérer tous les nooms d'utilisateurs et leur nombre de points dans le fichier de sortie
    {
        for (const pair <unsigned ,string> & valeur : mapPoints)     //Puis, on insére tous les noms d'utilisateurs avec leur nombre de points correspondant
            ofs << valeur.first << ' ' << valeur.second << endl;
        ofs.close();    //Pour finir, on ferme le fichier de sortie
    }
}//insertionRank()


void nsManipulateFile::extractionLevel (map <string ,unsigned> & mapPoints, const unsigned & points, const string & username, const string & nameInputFile)
{
    ifstream ifs(nameInputFile);   //On essaye d'ouvrir le fichier d'entrée
    if (!ifs) cerr << "Fichier non trouvé" << endl; //s'il ne s'ouvre pas, alors on arrête
    else    //Sinon, on récupère tous les noms d'utilisateurs et leur nombre de points
    {
        string mots;    //Variable pour extraire les noms d'utilisateurs
        short NbEntier;     //Variable pour extraire leur nombre d epoints
        unsigned switchType (0);    //Variable permettant d'ajouter dans la map le nom d'utilisateur correspondant à son nombre de points
        for ( ; ; )
        {
            if (ifs.eof())  //A la fin du fichier d'entrée, on arrête la lecture
                break;
            if (switchType % 2 == 0)    //Tous les entier+2 on passe à une nouvelle ligne du fichier d'entrée et donc à un autre nom d'utilisateurs et son nombre d epoints
                ifs >> mots;
            else
                ifs >> NbEntier;

            if(ifs.fail())      //Si le caractère n'est pas compatible avec notre demande, alors on en choisis un autre
            {
                ifs.clear();
                char car;
                ifs.get(car);
            }
            else    //Sinon on ajoute le nom d'utilisateur et son nombre de points dans la map
            {
                ++switchType;
                if (((switchType %  2 == 0) && (switchType>1)))   //On l'intègre dans la map si on a un nom d'utilisateur et son nombre de points
                    mapPoints[mots] = NbEntier; //On les mets dans une map pour que ce soit directement trié et que les points soient associés au bon joueur
            }
        }
    }
}//extractionLevel()

void nsManipulateFile::insertionLevel (map <string ,unsigned > & mapPoints, const string & nameOutputFile)
{
    ofstream ofs (nameOutputFile);  //On essaye d'ouvrir le fichier de sortie
    if(!ofs) { cerr << "Fichier non trouvé" << endl; //s'il ne s'ouvre pas, alors on arrête
    }
    else    //S'il s'ouvre, on va insérer tous les nooms d'utilisateurs et leur nombre de points dans le fichier de sortie
    {
        for (const pair <string ,unsigned > & valeur : mapPoints)     //Puis, on insére tous les noms d'utilisateurs avec leur nombre de points correspondant
            ofs << valeur.first << ' ' << valeur.second << endl;
        ofs.close();    //Pour finir, on ferme le fichier de sortie
    }
}//insertionLevel()