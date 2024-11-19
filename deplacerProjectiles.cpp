/*
 Programme : deplacerProjectiles
 But : 
 Auteurs : Rafael Masson - Arthur Baros
 Date de derniere modification : 16/01/2024
*/
#include "spellwar.h"
#include <iostream>

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
void deplacerEclair(Spellwar& grille, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv)
{
    if (grille.zoneJeu[iLigne][iColonne + 1].representation == ' ')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne][iColonne + 1] = {'>', cyan, true};
    }
    else if (grille.zoneJeu[iLigne][iColonne + 1].representation == 'N')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne][iColonne + 1] = {'X', rouge, false};
        adversairesViv--;
    }
    else if (grille.zoneJeu[iLigne][iColonne + 1].representation == 'A')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne][iColonne + 1] = {'X', rouge, false};
        adversairesViv--;
    }
    else if (grille.zoneJeu[iLigne][iColonne + 1].representation == '<')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne][iColonne + 1] = {'X', rouge, false};
    }
    else if (grille.zoneJeu[iLigne][iColonne + 1].representation == '>')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        deplacerEclair(grille, iLigne, iColonne+1, adversairesViv);
        grille.zoneJeu[iLigne][iColonne + 1] = {'>', cyan, true};
    }
    else if (iColonne == TAILLE_LIGNES-1)
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
    }
}

void deplacerFlamme(Spellwar& grille, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv)
{
    if (grille.zoneJeu[iLigne][iColonne - 1].representation == ' ')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne][iColonne - 1] = {'<', rouge, true};
    }
    else if (grille.zoneJeu[iLigne][iColonne - 1].representation == 'N')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne][iColonne - 1] = {'X', rouge, false};
        adversairesViv--;
    }
    else if (grille.zoneJeu[iLigne][iColonne - 1].representation == 'J')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne][iColonne - 1] = {'X', rouge, false};
        grille.finJeu = mortJoueur;
    }
    else if (grille.zoneJeu[iLigne][iColonne - 1].representation == '|')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne][iColonne - 1] = {'X', rouge, false};
    }
    else if (grille.zoneJeu[iLigne][iColonne - 1].representation == '>')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne][iColonne - 1] = {'X', rouge, false};
    }
}