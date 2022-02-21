/*!
 * @file    variables.h
 * @date 11 Janvier
 * @authors Matthieu Sauva - Victor Bouveret - Mattias Gervilliers - Lenny Gonzales - Guillaume Kusiak
 * @brief Contenance de toutes les variables
 * @version 1.0
 */

#ifndef SPACE_VARIABLES_H
#define SPACE_VARIABLES_H
#include <string>
#include <vector>

/**
 * @namespace nsVariables
 * @brief Espace de nom pour les variables du jeu
 */
namespace nsVariables
{
    /*!
    * @struct configGame
    * @brief Regroupe toutes les variables de la table de jeu
    */
    struct configGame
    {
        /* Pour la protection */
        char KProtect = '-';
        /* - */

        /* Pour les mini-envahisseurs */
        unsigned KNumberMiniInvaders = 2;
        char KMiniInvaders = 'm'; // symbole des mini-envahisseurs
        /* - */

        /* Pour l'affichage de l'ecran */
        char KEmpty = ' ';  // case vide de l'écran
        unsigned KSizeLine;   // Nombre de lignes de l'écran (de l'espace)
        unsigned KSizeSpace;   // Nombre de colonnes de l'écran (de l'espace)
        /* - */

        /* Pour l'envahisseur */
        char KInsideInvader;  // caractèrere formant l'envahisseur
        char KMissile = 'T'; // symbole du missile
        unsigned KInvadersSize =  4;   // nombre de caractères qui forment l'envahisseur
        unsigned KInvadersMiddle = KInvadersSize / 2;
        /* - */

        /* Pour le joueur */
        char KInsideMe = 'A'; // symbole du vaisseau
        char KTorpedo = '!'; // symbole de la torpille
        /* - */

        // Pour les touches de déplacements lors du jeu
        char KeyLeft; // déplacement gauche
        char KeyRight; // déplacement droit
        char KeyShootLeft; // tir au niveau vaisseau gauche
        char KeyShootRight; // tir au niveau vaisseau droit

        // Pour les Capacités
        const std::vector <std::string> skills{"maxAmmunition","maxShieldLife","invincibility"}; // Toutes les capacités disponibles
        char KSkills = '$'; // symbole de la capacité
        /* - */

    };
}


#endif //SPACE_VARIABLES_H
