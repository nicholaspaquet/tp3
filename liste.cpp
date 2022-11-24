#include <iostream>
#include "liste.h"
#include <iomanip>
#include <string>

using namespace std;

Liste::Liste()
{
    tete = NULL;
}
Noeud Liste::ajouter_personne()
{
    Noeud personne;

    cout << "Ajout d'une personne dans la liste\n";
    cout << "Entrez son numero : ";
    cin >> personne.nombre;
    cin.ignore();
    cout << "Entrez son nom : ";
    getline(cin, personne.nom);
    cout << "Entrez son montant d'argent en banque : ";
    cin >> personne.argent;

    return personne;
}
void Liste::ajouter_debut(Noeud personne)
{
    Noeud *ajout;
    ajout = new Noeud;

    ajout->nombre = personne.nombre;
    ajout->nom = personne.nom;
    ajout->argent = personne.argent;

    // ajout->nombre = nombre;

    if (tete == NULL) // Si tete est NULL, il n'y a donc aucun noeuds
    {
        ajout->next = tete;
        tete = ajout;
        // Maintenant qu'il y a un noeud, forcément la tete et la queue sont identiques
        queue = tete;
    }
    else
    {
        // Après le premier noeud, on fait juste ajouter des noeuds au début.
        // La queue ne bougera pas.
        ajout->next = tete;
        tete = ajout;
    }
}
void Liste::ajouter_fin(Noeud personne)
{
    Noeud *ajout;
    ajout = new Noeud;

    ajout->nombre = personne.nombre;
    ajout->nom = personne.nom;
    ajout->argent = personne.argent;

    if (tete == NULL) // Si tete est NULL, il n'y a donc aucun noeud
    {
        ajout->next = tete;
        tete = ajout;
        // Maintenant qu'il y a un noeud, forcément la tete et la queue sont identiques
        queue = tete;
    }
    else
    {
        Noeud *tempo;
        tempo = ajout;
        ajout = queue;
        queue = tempo;
        ajout->next = queue;
    }
}
void Liste::inserer_apres_numero()
{
    Noeud *position_liste, personne;
    position_liste = tete;

    if (position_liste)
    {
        cout << "Nombre a trouver dans la liste : ";
        int nombre_recherche;
        cin >> nombre_recherche;
        while (position_liste != NULL && position_liste->nombre != nombre_recherche)
        {
            position_liste = position_liste->next;
        }
        if (position_liste == NULL)
        {
            cout << "Le nombre ne se trouve pas dans la liste.\n";
        }
        else
        {
            if (position_liste = queue)
            {
                personne = ajouter_personne();
                ajouter_fin(personne);
            }
            else
            {
                Noeud *apres;
                apres = new Noeud;

                personne = ajouter_personne();
                apres->nombre = personne.nombre;
                apres->nom = personne.nom;
                apres->argent = personne.argent;

                apres->next = position_liste->next;
                position_liste->next = apres;
            }
        }
    }
    else
    {
        cout << "La liste est vide.\n";
    }
}
void Liste::inserer_avant_chaque_numero()
{
    Noeud *position_liste, *noeud_precedent, personne;
    position_liste = tete;
    noeud_precedent = NULL;
    bool premier_nombre_trouve = false;

    if (position_liste == NULL)
    {
        cout << "La liste est vide.\n";
    }
    else
    {
        int nombre_recherche;
        cout << "Nombre a trouver dans la liste : ";
        cin >> nombre_recherche;

        while (position_liste != NULL)
        {
            int nombre_a_inserer;

            if (position_liste->nombre == nombre_recherche && premier_nombre_trouve == false)
            {
                personne = ajouter_personne();
                premier_nombre_trouve = true;
            }
            if (noeud_precedent != NULL && position_liste->nombre == nombre_recherche)
            {
                Noeud *avant;
                avant = new Noeud;

                avant->nombre = personne.nombre;
                avant->nom = personne.nom;
                avant->argent = personne.argent;

                avant->next = position_liste;
                noeud_precedent->next = avant;
            }
            else
            {
                if (noeud_precedent == NULL && position_liste->nombre == nombre_recherche)
                {
                    ajouter_debut(personne);
                }
            }
            noeud_precedent = position_liste;
            position_liste = position_liste->next;
        }
        if (position_liste == NULL && premier_nombre_trouve == false)
        {
            cout << "Le nombre ne se trouve pas dans la liste.\n";
        }
    }
}
void Liste::supprimer_personne()
{
    Noeud *position_liste;
    Noeud *noeud_precedent;
    position_liste = tete;
    noeud_precedent = NULL;

    if (position_liste == NULL)
    {
        cout << "\nLa liste est vide.\n";
    }
    else
    {
        cout << "Nom de la personne a supprimer de la liste : ";
        string nom_recherche;
        cin.ignore();
        getline(cin, nom_recherche);
        // int nombre_recherche;
        // cin >> nombre_recherche;

        while (position_liste != NULL && position_liste->nom != nom_recherche)
        {
            noeud_precedent = position_liste;
            position_liste = position_liste->next;
        }
        if (position_liste != NULL && noeud_precedent != NULL)
        {
            if (position_liste == queue)
            {
                queue = noeud_precedent;
            }
            noeud_precedent->next = position_liste->next;
            delete position_liste;
            cout << "Le noeud a ete supprime.\n";
        }
        else
        {
            if (noeud_precedent == NULL && position_liste->nom == nom_recherche)
            {
                tete = position_liste->next;
                delete position_liste;
            }
            else
            {
                cout << "Le nom ne se trouve pas dans la liste.\n";
            }
        }
    }
}
void Liste::moyenne_argent()
{
    Noeud *iterateur = tete;
    float somme = 0;
    int compteur = 0;

    if (iterateur)
    {
        while (iterateur != NULL)
        {
            compteur++;
            somme += iterateur->argent;
            iterateur = iterateur->next;
        }
        cout << "La moyenne d'argent en banque de toutes les personne de la liste est : "
             << somme / compteur << endl;
    }
    else
    {
        cout << "La liste est vide.\n";
    }
}
void Liste::afficher()
{
    Noeud *iterateur = tete;

    if (iterateur)
    {
        int i = 1;
        cout << endl;
        cout << left << setw(30) << "Numero" << setw(30) << "Nom"
             << "Argent" << endl;
        while (iterateur != NULL)
        {
            cout << left << setw(30) << iterateur->nombre << setw(30) << iterateur->nom
                 << iterateur->argent << endl;
            // cout << left << setw(20) << "Adresse" << setw(20) << iterateur << setw(20)
            //      << "Adresse next" << setw(20) << iterateur->next << setw(20)
            //      << iterateur->nombre << endl;
            iterateur = iterateur->next;
            i++;
        }
    }
    else
    {
        std::cout << "\nLa liste est vide.\n";
    }
}
void Liste::supprimer_liste()
{
    // Fonction permettant de supprimer une liste en les supprimant noeud par noeud
    Noeud *iterateur = tete;

    while (iterateur != NULL)
    {
        // On déplace la tête d'un noeud
        tete = iterateur->next;
        // On supprime le noeud pointé par l'itérateur
        delete iterateur;
        // L'itérateur devient la tête de nouveau et on répète
        iterateur = tete;
    }
}
void Liste::print_extremites()
{
    cout << "L'adresse de la tete est  : " << tete << endl;
    cout << "L'adresse de la queue est : " << queue << endl;
}