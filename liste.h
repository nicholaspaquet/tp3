struct Noeud
{
    int nombre;
    Noeud *next;
};
class Liste
{
    Noeud *tete;
    Noeud *queue;

public:
    Liste()
    {
        tete = NULL;
    }
    void afficher();
    void print_extremites();
    void ajouter_debut();
    void ajouter_apres();
    void ajouter_avant();
    void supprimer_noeud();
};