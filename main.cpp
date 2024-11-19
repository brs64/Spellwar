//****************************************************************************
// EN-TETE
//****************************************************************************
/*
 Programme : Spellwar
 But du jeu :
 Regles du jeu :
 Date de dernière modification : 09 janvier 2023
 Auteur : R. Masson et A. Baros
 Remarques : Code conforme aux spécification internes donnees en cours
 Resultat du test :
*/

//****************************************************************************
// INCLUSION
//****************************************************************************
#include <iostream>
#include "game-tools.h"
#include "spellwar.h"
using namespace std;

//****************************************************************************
// DECLARATION DES SOUS-PROGRAMMES
//****************************************************************************

//****************************************************************************
// PROGRAMME PRINCIPAL
//****************************************************************************
int main(void)
{
    // VARIABLES
    Spellwar plateauJeu; // Grille du jeu
    bool partieFinie = false; // Vrai si une condition de fin de partie a ete atteinte 

    string actionsSaisieParJ; // Chaine de caractere contenant les actions saisies par le joueur
    char actionCourante;
    unsigned int adversairesEnVie;

    // Initialiser la partie
    // Initialiser les variables (NOM DES VARIABLES DANS LE COMMENTAIRE)
    adversairesEnVie = NOMBRES_ADVERSAIRES;

    // Initialiser le tableau
    creerZoneJeu(plateauJeu);

    // Positionner le joueur et les adversaires
    positionnerPersonnages(plateauJeu);

    // Jouer la partie
    // Saisir et jouer le(s) action(s)
    do
    {
        // Afficher la zone de jeu
        afficherZoneJeu(plateauJeu);

        // Afficher les actions disponibles pour le joueur
        afficherTexteEnCouleur("Actions possibles :", bleu, true);
        afficherTexteEnCouleur("a --> abandonner, m --> monter, d --> descendre, e --> eclair", bleu, true);

        // Saisir les actions
        cout << "Vos actions : ";
        cin >> actionsSaisieParJ;

        effacer();
        // Jouer les actions
        for (unsigned int indiceAction = 0; indiceAction < static_cast<unsigned int>(actionsSaisieParJ.size()); indiceAction++)
        {
            for (unsigned int indiceLigne = 0; indiceLigne < TAILLE_COLONNES; indiceLigne++)
            {
                for (unsigned int indiceColonne = 0; indiceColonne < TAILLE_LIGNES; indiceColonne++)
                {
                    actionCourante = actionsSaisieParJ[indiceAction];
                    if (plateauJeu.zoneJeu[indiceLigne][indiceColonne].representation == 'J' && plateauJeu.zoneJeu[indiceLigne][indiceColonne].deplaceCeTour == false)
                    {
                        actionJoueur(plateauJeu, actionCourante, indiceLigne, indiceColonne, adversairesEnVie);
                    }
                    else if (plateauJeu.zoneJeu[indiceLigne][indiceColonne].representation == 'A' && plateauJeu.zoneJeu[indiceLigne][indiceColonne].deplaceCeTour == false)
                    {
                        actionArcaflamme(plateauJeu, indiceLigne, indiceColonne, adversairesEnVie);
                    }
                    else if (plateauJeu.zoneJeu[indiceLigne][indiceColonne].representation == 'N' && plateauJeu.zoneJeu[indiceLigne][indiceColonne].deplaceCeTour == false)
                    {
                        actionNecrogriffe(plateauJeu, actionCourante, indiceLigne, indiceColonne, adversairesEnVie);
                    }
                    else if (plateauJeu.zoneJeu[indiceLigne][indiceColonne].representation == '>' && plateauJeu.zoneJeu[indiceLigne][indiceColonne].deplaceCeTour == false)
                    {
                        deplacerEclair(plateauJeu, indiceLigne, indiceColonne, adversairesEnVie);
                    }
                    else if (plateauJeu.zoneJeu[indiceLigne][indiceColonne].representation == '<' && plateauJeu.zoneJeu[indiceLigne][indiceColonne].deplaceCeTour == false)
                    {
                        deplacerFlamme(plateauJeu, indiceLigne, indiceColonne, adversairesEnVie);
                    }
                }
            }
            afficherZoneJeu(plateauJeu);       
            afficherTexteEnCouleur("Actions possibles :", bleu, true);
            afficherTexteEnCouleur("a --> abandonner, m --> monter, d --> descendre, e --> eclair", bleu, true);
            cout << "Vos actions : " << actionsSaisieParJ << endl << endl;
            // Supprimer les marques de collision
            supprimerMarqueCollision(plateauJeu);
            if (plateauJeu.finJeu == abandon)
            {
                partieFinie = true;
                break;
            }
            if (plateauJeu.finJeu == mortJoueur)
            {
                partieFinie = true;
                break;
            }
            if (adversairesEnVie == 0)
            {
                plateauJeu.finJeu = victoireJoueur;
                partieFinie = true;
                break;
            }
            pause(1);
            effacer();
            reinitialiserDeplacements(plateauJeu);
        }
    } while (!partieFinie);

    // Finir la partie
    finirLaPartie(plateauJeu);

    return 0;
}

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
