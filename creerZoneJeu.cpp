/*
 Programme : creerZoneJeu 
 But : 
 Auteurs : Rafael Masson - Arthur Baros
 Date de derniere modification : 16/01/2024
*/
#include "spellwar.h"

//****************************************************************************
// DECLARATION DES SOUS-PROGRAMMES
//****************************************************************************
/* Retourne l'element a affecter a la case courante
   indiceLigne l'indice de la ligne courante de la grille.
   indiceColonne l'indice de la colonne courante de la grille. */
ElementDeJeu remplirMursEspacesVide(unsigned int iLigne, unsigned int iColonne);

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
void creerZoneJeu(Spellwar &grille)
{
    // Variables locales
    ElementDeJeu element;

    // Code de la procedure
    for (unsigned int indiceLigne = 0; indiceLigne < TAILLE_COLONNES; indiceLigne++)
    {
        for (unsigned int indiceColonne = 0; indiceColonne < TAILLE_LIGNES; indiceColonne++)
        {
            element = remplirMursEspacesVide(indiceLigne,indiceColonne);
            grille.zoneJeu[indiceLigne][indiceColonne] = element;
        }
    }
}

ElementDeJeu remplirMursEspacesVide(unsigned int indiceLigne, unsigned int indiceColonne)
{   
    // Variables locales
    ElementDeJeu elem;

    // Code de la fonction
    if (indiceLigne == 0 || indiceLigne == (TAILLE_COLONNES - 1))
    {
        elem = {'#', blanc, false};
    }
    else if (indiceLigne != 0 && indiceLigne != (TAILLE_COLONNES-1) && indiceColonne == 0)
    {
        elem = {'|', cyan, false};
    }
    else
    {
        elem = {' ', blanc, false};
    }
    return (elem);
}