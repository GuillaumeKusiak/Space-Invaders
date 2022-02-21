/*!
 * @file    yaml.h
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Actions avec le fichier de configuration config.yaml
 * @version 1.0
 */

#ifndef SPACEINVADERS_YAML_H
#define SPACEINVADERS_YAML_H

#include "../GenerateGame/generateGame.h"

/**
 * @namespace nsYaml
 * @brief Espace de nom pour la configuration yaml
 */
namespace nsYaml
{
    /*!
     * @brief initialisation des variables avec des valeurs par défault
     * @param[in/out] configuration : maps regroupant les configurations du fichier yaml
     * @param[in/out] game : variables de la table de jeu
     * @fn initMap(GameConfigure & configuration, nsVariables::configGame & game);
     */
    void initMap(
            GameConfigure & configuration,
            nsVariables::configGame & game);

    /*!
     * @brief lecture du fichier de configuration config.yaml
     * @param[in/out] configuration : maps regroupant les configurations du fichier yaml
     * @param[in] nameOfFile : nom du fichier source
     * @param[in/out] game : variables de la table de jeu
     */
    void readConfig(
            GameConfigure & configuration,
            const std::string & nameOfFile,
            nsVariables::configGame & game);

    /*!
     * @brief vérification des paramètres proposés dans le fichier yaml
     * @param[in/out] configuration : maps regroupant les configurations du fichier yaml
     * @param[in/out] game : variables de la table de jeu
     */
    void verifConfig(
            GameConfigure & configuration,
            nsVariables::configGame & game);

    /*!
     * @brief ajout des configurations aux variables du jeu
     * @param[in/out] configuration
     * @param[in/out] game : variables de la table de jeu
     * @fn void addConfig(GameConfigure & configuration, nsVariables::configGame & game);
     */
    void addConfig(
            GameConfigure & configuration,
            nsVariables::configGame & game);
}

#endif //SPACEINVADERS_YAML_H
