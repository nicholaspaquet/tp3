#include <iostream>
#include "liste.h"
#include <iomanip>

using namespace std;

void Liste::afficher()
{
    Noeud *iterateur_liste;
    iterateur_liste = tete;

    if (iterateur_liste)
    {
        int i = 1;
        cout << endl;
        // cout << left << setw(20) << "Adresse tete : " << setw(20) << tete << setw(20)
        //      << "Adresse next : " << setw(20) << tete->next << endl;
        while (iterateur_liste != NULL)
        {
            cout << left << setw(20) << "Adresse" << setw(20) << iterateur_liste << setw(20)
                 << "Adresse next" << setw(20) << iterateur_liste->next << setw(20)
                 << iterateur_liste->nombre << endl;
            // cout << "Adresse : " << iterateur_liste << ", Adresse next : " << iterateur_liste->next << endl;
            // cout << "Position liste : " << i << ", Valeur : " << iterateur_liste->nombre << endl;
            iterateur_liste = iterateur_liste->next;
            i++;
        }
        // cout << left << setw(20) << "Adresse queue : " << setw(20) << queue << setw(20)
        //      << "Adresse next : " << setw(20) << queue->next << endl;
    }
    else
    {
        std::cout << "\nLa liste est vide.\n";
    }
}
void Liste::print_extremites()
{
    cout << "L'adresse de la tete est  : " << tete << endl;
    cout << "L'adresse de la queue est : " << queue << endl;
}
void Liste::ajouter_debut()
{
    Noeud *ajout;
    ajout = new Noeud;

    cout << "Entrer un nombre a inserer dans la liste : ";
    cin >> ajout->nombre;

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
void Liste::ajouter_apres()
{
    Noeud *position_liste;
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
            Noeud *apres;
            apres = new Noeud;
            cout << "Entrer un nombre a inserer dans la liste : ";
            cin >> apres->nombre;
            apres->next = position_liste->next;
            position_liste->next = apres;
        }
    }
    else
    {
        cout << "La liste est vide.\n";
    }
}
void Liste::ajouter_avant()
{
    Noeud *position_liste;
    Noeud *noeud_precedent;
    position_liste = tete;
    noeud_precedent = NULL;

    if (position_liste)
    {
        int nombre_recherche;
        cout << "Nombre a trouver dans la liste : ";
        cin >> nombre_recherche;

        while (position_liste != NULL && position_liste->nombre != nombre_recherche)
        {
            noeud_precedent = position_liste;
            position_liste = position_liste->next;
        }
        if (position_liste != NULL && noeud_precedent != NULL)
        {
            Noeud *avant;
            avant = new Noeud;
            cout << "Entrer un nombre a inserer dans la liste : ";
            cin >> avant->nombre;
            avant->next = position_liste;
            noeud_precedent->next = avant;
        }
        else
        {
            if (position_liste != NULL && noeud_precedent == NULL)
            {
                ajouter_debut();
            }
            else
            {
                cout << "Le nombre ne se trouve pas dans la liste.\n";
            }
        }
    }
    else
    {
        cout << "La liste est vide.\n";
    }
}
void Liste::supprimer_noeud()
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
        cout << "Nombre a supprimer dans la liste : ";
        int nombre_recherche;
        cin >> nombre_recherche;

        while (position_liste != NULL && position_liste->nombre != nombre_recherche)
        {
            noeud_precedent = position_liste;
            position_liste = position_liste->next;
        }
        if (position_liste != NULL && noeud_precedent != NULL)
        {
            noeud_precedent->next = position_liste->next;
            delete position_liste;
            cout << "Le noeud a ete supprime.\n";
        }
        else
        {
            if (noeud_precedent == NULL && position_liste->nombre == nombre_recherche)
            {
                tete = position_liste->next;
                delete position_liste;
            }
            else
            {
                cout << "Le nombre ne se trouve pas dans la liste.\n";
            }
        }
    }
}