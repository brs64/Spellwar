/**
 * @file spellwar.h
 * @author Rafael Masson - Arthur Baros
 * @brief Fichier d'entête du module spellwar
 * @date 2023-12-02
 */
#ifndef SPELLWAR_H
#define SPELLWAR_H

#include "game-tools.h"

const unsigned int TAILLE_LIGNES = 20;  // Largeur de la zone de jeu (de base c'est 35)
const unsigned int TAILLE_COLONNES = 8; // Hauteur de la zone de jeu (de base c'est 8)
const unsigned int NOMBRES_ADVERSAIRES = 3; // Nombre initial d'adversaires (de base c'est 3)

enum SituationFinJeu
{
    abandon,
    mortJoueur,
    victoireJoueur
};

/**
 * @brief Enregistrement caracterisant les differents
 * elements de jeu utilises par le jeu spellwar
 *
 * @example Enregistrements possibles de ElementDeJeu
 * @example ElementDeJeu espaceVide = {' ', blanc, false};
 * @example ElementDeJeu murVertical = {'|', cyan, true};
 * @example ElementDeJeu murHorizontal = {'#', blanc, false};
 * @example ElementDeJeu joueur = {'J', cyan, false};
 * @example ElementDeJeu eclair = {'>', cyan, true};
 * @example ElementDeJeu arcaflamme = {'A', jaune, false};
 * @example ElementDeJeu flamme = {'<', jaune, true};
 * @example ElementDeJeu necrogriffe = {'N', violet, false};
 * 
 */
struct ElementDeJeu
{
    char representation;
    Couleur couleur;
    bool deplaceCeTour = false;
};

struct Spellwar
{
    ElementDeJeu zoneJeu[TAILLE_COLONNES][TAILLE_LIGNES];
    SituationFinJeu finJeu;
};

/**
 * @brief Permet de creer la zone de jeu dans une grille de jeu de spellwar
 *
 * @param [in] grille la grille de jeu a remplir avec les elements de spellwar
 */
void creerZoneJeu(Spellwar& grille);

/**
 * @brief Permet de positionner le joueur et les adversaires du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 */
void positionnerPersonnages(Spellwar& grille);

/**
 * @brief Permet d'afficher sur le terminal la grille de jeu de spellwar
 *
 * @param [in] grille la grille de jeu a afficher
 */
void afficherZoneJeu(const Spellwar& grille);

/**
 * @brief Permet de supprimer les marques de collision du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 */
void supprimerMarqueCollision(Spellwar &grille);

/**
 * @brief Permet d'executer l'action saisie pour le joueur du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] actionJ l'action du joueur
 * @param [in] iLigne l'indice de la ligne de l'element 
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'aversaires encore en vie
 */
void actionJoueur(Spellwar& grille, char actionJ, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv);

/**
 * @brief Permet de faire jouer un arcaflamme du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] iLigne l'indice de la ligne de l'element 
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'adversaires encore en vie
 */
void actionArcaflamme(Spellwar& grille, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv);

/**
 * @brief Permet de faire jouer un necrogriffe du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] actionJ l'action du joueur
 * @param [in] iLigne l'indice de la ligne de l'element 
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'adversaires encore en vie
 */
void actionNecrogriffe(Spellwar& grille, char actionJ, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv);

/**
 * @brief Permet de deplacer un eclair du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] iLigne l'indice de la ligne de l'element 
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'adversaires encore en vie
 */
void deplacerEclair(Spellwar& grille, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv);

/**
 * @brief Permet de deplacer une flamme du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] iLigne l'indice de la ligne de l'element 
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'adversaires encore en vie
 */
void deplacerFlamme(Spellwar& grille, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv);

/**
 * @brief Permet de mettre a faux deplaceCeTour pour tout les elements du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 */
void reinitialiserDeplacements(Spellwar& grille);

/**
 * @brief Permet d'afficher un message expliquant la raison de la fin de la partie du jeu spellwar
 *
 * @param [in] grille la grille de jeu qui contient la raison de la fin de la partie
 */
void finirLaPartie(const Spellwar& grille);

#endif // SPELLWAR_H