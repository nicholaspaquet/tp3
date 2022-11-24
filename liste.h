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
    Noeud ajouter_personne();
    void ajouter_debut(Noeud);
    void ajouter_fin(Noeud);
    void inserer_apres_numero();
    void inserer_avant_chaque_numero();
    void supprimer_personne();
    void moyenne_argent();
    void afficher();
    void supprimer_liste();

    void print_extremites();
};