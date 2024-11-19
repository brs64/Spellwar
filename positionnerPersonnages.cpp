/*
 Programme : positionnerPersonnages
 But : 
 Auteurs : Rafael Masson - Arthur Baros
 Date de derniere modification : 16/01/2024
*/
#include "spellwar.h"

//****************************************************************************
// DECLARATION DES SOUS-PROGRAMMES
//****************************************************************************
/* Permet de positionner les arcaflammes et les necrogriffes
   nbArca le nombre d'arcaflamme a positionner
   nbNecro le nombre de necrogriffe a positionner
   grille la grille de jeu a modifier */
void positionnerArcaNecro(Spellwar& grille, unsigned int nbArca, unsigned int nbNecro);

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
void positionnerPersonnages(Spellwar& grille)
{
    // Variables
    unsigned int nbArcaflamme;
    unsigned int nbNecrogriffe;

    // Code procedure
    // Positionner le joueur
    grille.zoneJeu[TAILLE_COLONNES / 2][1] = {'J', cyan, false};

    // Positionner les adversaires
    // Nombre d'arcaflammes/necrogriffes a afficher
    nbArcaflamme = random(0,NOMBRES_ADVERSAIRES);
    nbNecrogriffe = NOMBRES_ADVERSAIRES - nbArcaflamme;

    // Positionner le(s) arcaflamme(s) et le(s) necrogriffe(s)
    positionnerArcaNecro(grille, nbArcaflamme, nbNecrogriffe);
}

void positionnerArcaNecro(Spellwar& grille, unsigned int nbArca, unsigned int nbNecro)
{
    // Variables
    unsigned int indiceLigne;

    // Code procédure
    for (unsigned int i = 0; i < nbArca; i++)
    {
        indiceLigne = random(1, (TAILLE_COLONNES-2));
        if (grille.zoneJeu[indiceLigne][TAILLE_LIGNES-1].representation == ' ')
        {
            grille.zoneJeu[indiceLigne][TAILLE_LIGNES-1] = {'A', rouge, false};
        }
        else
        {
            i--;
        }
    } 
    for (unsigned int j = 0; j < nbNecro; j++)
    {
        indiceLigne = random(1, (TAILLE_COLONNES-2));
        if (grille.zoneJeu[indiceLigne][TAILLE_LIGNES-1].representation == ' ')
        {
            grille.zoneJeu[indiceLigne][TAILLE_LIGNES-1] = {'N', violet, false};
        }
        else
        {
            j--;
        }
    }   
}