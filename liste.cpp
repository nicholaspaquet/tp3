// Nicholas Paquet
// Travail pratique 3
// Fichier source "liste.cpp"

#include <iostream>
#include "liste.h"
#include <iomanip>
#include <string>

using namespace std;

Liste::Liste()
{
    tete = NULL;
}

Noeud *Liste::get_tete()
{
    return tete;
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

    if (tete == NULL)
    {
        ajout->next = tete;
        tete = ajout;
        queue = tete;
    }
    else
    {
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

    if (tete == NULL)
    {
        ajouter_debut(personne);
    }
    else
    {
        queue->next = ajout;
        ajout = queue;
        queue = queue->next;
        queue->next = NULL;
    }
}

bool Liste::inserer_apres_numero(int nombre_recherche)
{
    Noeud *position_liste;
    position_liste = tete;

    while (position_liste != NULL && position_liste->nombre != nombre_recherche)
    {
        position_liste = position_liste->next;
    }
    if (position_liste == NULL)
    {
        return false;
    }
    else
    {
        Noeud personne = ajouter_personne();
        if (position_liste == queue)
        {
            ajouter_fin(personne);
        }
        else
        {
            Noeud *apres;
            apres = new Noeud;

            apres->nombre = personne.nombre;
            apres->nom = personne.nom;
            apres->argent = personne.argent;

            apres->next = position_liste->next;
            position_liste->next = apres;
        }
        return true;
    }
}

bool Liste::inserer_avant_chaque_numero(int nombre_recherche)
{
    Noeud *position_liste, *noeud_precedent, personne;
    position_liste = tete;
    noeud_precedent = NULL;
    bool premier_nombre_trouve = false;

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
    if (premier_nombre_trouve == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Liste::supprimer_personne(string nom_recherche)
{
    Noeud *position_liste;
    Noeud *noeud_precedent;
    position_liste = tete;
    noeud_precedent = NULL;

    cout << "nom recherche : " << nom_recherche << endl;
    while (position_liste != NULL && position_liste->nom != nom_recherche)
    {
        noeud_precedent = position_liste;
        position_liste = position_liste->next;
    }
    if (position_liste != NULL && position_liste->nom == nom_recherche)
    {
        if (position_liste == tete)
        {
            tete = position_liste->next;
        }
        else
        {
            if (position_liste == queue)
            {
                queue = noeud_precedent;
            }
            noeud_precedent->next = position_liste->next;
        }
        delete position_liste;
        return true;
    }
    else
    {
        return false;
    }
}

float Liste::moyenne_argent()
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
        return (somme / compteur);
    }
    return 0;
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
            iterateur = iterateur->next;
            i++;
        }
    }
}

void Liste::supprimer_liste()
{
    Noeud *iterateur = tete;

    while (iterateur != NULL)
    {
        tete = iterateur->next;
        delete iterateur;
        iterateur = tete;
    }
}