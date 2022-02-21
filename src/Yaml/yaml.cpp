/*!
 * @file    yaml.cpp
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Actions avec le fichier de configuration config.yaml
 * @version 1.0
 */
#include "../../headers/Yaml/yaml.h"
#include <fstream>
#include <iostream>


using namespace std;
using namespace nsVariables;

void nsYaml::verifConfig(GameConfigure & configuration, configGame & game) {
    if (configuration.GameConfigUnsigned["KSizeSpace"] % 2 != 0 || configuration.GameConfigUnsigned["KSizeLine"] % 2 != 0 &&  (configuration.GameConfigUnsigned["KSizeSpace"] < 10 || configuration.GameConfigUnsigned["KSizeSpace"] > 20)
    || (configuration.GameConfigUnsigned["KSizeLine"] < 10 || configuration.GameConfigUnsigned["KSizeLine"] > 20)
    || (configuration.GameConfigUnsigned["KSizeSpace"]) != configuration.GameConfigUnsigned["KSizeLine"])
    {
        cerr << "Erreur dimensionnement : KSizeSpace et KSizeLine doivent etre compris entre 10 et 20, et doivent etre de la meme valeurs et paires" << endl;
        exit(1);
    }
    else
        addConfig(configuration, game);
}//verifConfig()



void nsYaml::addConfig(GameConfigure & configuration, nsVariables::configGame & game) {
    game.KeyLeft = configuration.GameConfigChar["KeyLeft"];
    game.KeyRight = configuration.GameConfigChar["KeyRight"];
    game.KeyShootLeft = configuration.GameConfigChar["KeyShootLeft"];
    game.KeyShootRight = configuration.GameConfigChar["KeyShootRight"];

    game.KInsideInvader = configuration.GameConfigChar["KInvader"];
    game.KMiniInvaders = configuration.GameConfigChar["KMiniInvaders"];
    game.KInsideMe = configuration.GameConfigChar["KSpaceShip"];

    game.KSizeSpace = configuration.GameConfigUnsigned["KSizeSpace"];
    game.KSizeLine = configuration.GameConfigUnsigned["KSizeLine"];
}//addConfig()

void nsYaml::initMap(GameConfigure & configuration, configGame & game) {

    // Configuration of keys
    configuration.GameConfigChar["KeyLeft"] = 'q'; // To go left
    game.KeyLeft = configuration.GameConfigChar["KeyLeft"];
    configuration.GameConfigChar["KeyRight"] = 'd'; // To go right
    game.KeyRight = configuration.GameConfigChar["KeyRight"];
    configuration.GameConfigChar["KeyShootLeft"] = 'a'; // To shoot on left
    game.KeyShootLeft = configuration.GameConfigChar["KeyShootLeft"];
    configuration.GameConfigChar["KeyShootRight"] = 'e'; // To shoot on right
    game.KeyShootRight = configuration.GameConfigChar["KeyShootRight"];

    // Configuration of entities
    configuration.GameConfigChar["KInvader"] = 'W'; // Invader
    game.KInsideInvader = configuration.GameConfigChar["KInvader"];

    configuration.GameConfigChar["KMiniInvaders"] = 'm'; // Mini invaders
    game.KMiniInvaders = configuration.GameConfigChar["KMiniInvaders"];

    configuration.GameConfigChar["KSpaceShip"] = 'A'; // SpaceShip
    game.KInsideMe = configuration.GameConfigChar["KSpaceShip"];

    configuration.GameConfigUnsigned["KSizeSpace"] = 20;
    game.KSizeSpace = configuration.GameConfigUnsigned["KSizeSpace"];

    configuration.GameConfigUnsigned["KSizeLine"] = 20;
    game.KSizeLine = configuration.GameConfigUnsigned["KSizeLine"];
}//initMat()

void nsYaml::readConfig(GameConfigure & configuration, const string & nameOfFile, configGame & game) {
    fstream file (nameOfFile); // On ouvre le fichier yaml
    if (!file) // Pas de fichier trouvé
    {
        cerr << "File not found" << endl;
        exit(1);
    }
    for (string key; file >> key;) // On récupère une chaine de caractère
    {
        char separation;
        file >> separation; // On récupère un caractère de séparation
        if (separation != ':')// En cas d'erreur de caractère
        {
            cerr << "Erreur, mauvais caractère de séparation" << endl;
            exit(1);
        }
        if (configuration.GameConfigChar.find(key) != configuration.GameConfigChar.end()) // Pour un caractère
        {
            char value;
            file >> value;
            configuration.GameConfigChar[key] = value;
        }
        if (configuration.GameConfigUnsigned.find(key) != configuration.GameConfigUnsigned.end()) // Pour un entier
        {
            unsigned value;
            file >> value;
            configuration.GameConfigUnsigned[key] = value;
        }
    }
    verifConfig(configuration, game);
}//readConfig()
