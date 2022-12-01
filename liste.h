/***************************************************************************************************
 *                                                                                                 *
 *       Titre :                   Orienté objet - Travail pratique 3                              *
 *       Auteur :                  Nicholas Paquet                                                 *
 *       Date de création :        23 novembre 2022                                                *
 *       Dernière modification :   01 décembre 2022                                                *
 *       Date de remise :          02 décembre 2022                                                *
 *       But :                     Le but de ce travail pratique est d'appliquer la matière vu     *
 *                                 en classe pour les listes chainées par l'entremise de           *
 *                                 plusieurs manipulations sur les noeuds d'une liste.             *                                               *
 *                                                                                                 *
 ***************************************************************************************************/

// Dans mon header, je fais les prototypages qui seront nécessaires pour une classe Liste.

// Je déclare également une struct Noeud qui sera utilisé par cette classe.
struct Noeud
{
    int nombre;
    std::string nom;
    float argent;
    Noeud *next;
};
class Liste
{
    Noeud *tete;
    Noeud *queue;

public:
    Liste();
    Noeud *get_tete();
    Noeud ajouter_personne();
    void ajouter_debut(Noeud);
    void ajouter_fin(Noeud);
    bool inserer_apres_numero(int);
    bool inserer_avant_chaque_numero(int);
    bool supprimer_personne(std::string);
    float moyenne_argent();
    void afficher();
    void supprimer_liste();
};