/*
 Programme : afficherZoneJeu
 But : 
 Auteurs : Rafael Masson - Arthur Baros
 Date de derniere modification : 16/01/2024
*/
#include "spellwar.h"
#include <iostream>

//****************************************************************************
// DECLARATION DES SOUS-PROGRAMMES
//****************************************************************************
/* Permet d'afficher sur le terminal la representation graphique de l'enregistrement element
   element l'element a afficher. */
void afficherCaseTableau(const ElementDeJeu& element);

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
void afficherCaseTableau(const ElementDeJeu& element)
{
    afficherTexteEnCouleur(element.representation, element.couleur);
}

void afficherZoneJeu(const Spellwar& grille)
{
    // Variables locales
    ElementDeJeu elem;

    // Code de la procedure
    cout << endl;
    for (unsigned int indiceLigne = 0; indiceLigne < TAILLE_COLONNES; indiceLigne++)
    {
        for (unsigned int indiceColonne = 0; indiceColonne < TAILLE_LIGNES; indiceColonne++)
        {
            elem = grille.zoneJeu[indiceLigne][indiceColonne];
            afficherCaseTableau(elem);
        }
        cout << endl;
    }
    cout << endl;
}