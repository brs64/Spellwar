/*
 Programme : finirLaPartie
 But : 
 Auteurs : Rafael Masson - Arthur Baros
 Date de derniere modification : 16/01/2024
*/
#include "spellwar.h"
#include <iostream>

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
void finirLaPartie(const Spellwar &grille)
{
    switch (grille.finJeu)
    {
    case abandon:
        // Afficher en bleu "Vous avez gagne la partie grace a une carte Jackpot !!"
        afficherTexteEnCouleur("Vous avez perdu la partie par abandon", rouge);
        break;
    case mortJoueur:
        // Afficher en rouge "Vous avez perdu la partie par abandon :-("
        afficherTexteEnCouleur("Vous avez perdu la partie par la mort de votre magicien", rouge);
        break;
    case victoireJoueur:
        // Afficher en rouge "Vous avez perdu la partie, il ne reste pas suffisament de carte dans le paquet. :-("
        afficherTexteEnCouleur("Vous avez gagne la partie : tout les ennemis sont morts !", vert);
        break;
    }
}