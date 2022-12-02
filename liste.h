// Nicholas Paquet
// Travail pratique 3
// Fichier header "liste.h"

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