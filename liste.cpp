/***************************************************************************************************
 *                                                                                                 *
 *       Titre :                   Orienté objet - Travail pratique 3                              *
 *       Auteur :                  Nicholas Paquet                                                 *
 *       Date de création :        23 novembre 2022                                                *
 *       Dernière modification :   01 décembre 2022                                                *
 *       Date de remise :          02 décembre 2022                                                *
 *       But :                     Le but de ce travail pratique est d'appliquer la matière vu     *
 *                                 en classe pour les listes chainées par l'entremise de           *
 *                                 plusieurs manipulations sur les noeuds d'une liste.             *
 *                                                                                                 *
 ***************************************************************************************************/

// Dans ce fichier source, je définis la classe Liste ainsi que toutes ses fonctions.

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
    // Fonction permettant d'ajouter une nouvelle personne dans la liste. Évite d'avoir à copier-
    // coller le code partout.
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
    // Fonction permettant d'ajouter un Noeud au début de la liste,
    Noeud *ajout;
    ajout = new Noeud;

    ajout->nombre = personne.nombre;
    ajout->nom = personne.nom;
    ajout->argent = personne.argent;

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
    // Cette fonction permet d'ajouter un Noeud à la fin de la liste. Si la liste est vide, un
    // Noeud sera ajouté au début, sinon, le Noeud ajouté sera le dernier élément de la liste
    // et deviendra la queue.
    Noeud *ajout;
    ajout = new Noeud;

    ajout->nombre = personne.nombre;
    ajout->nom = personne.nom;
    ajout->argent = personne.argent;

    if (tete == NULL) // Si tete est NULL, il n'y a donc aucun noeud
    {
        // S'il n'y a pas de tête, il faut commencer par ajouter un premier Noeud.
        // Je rajoute donc une nouvelle personne au début de la liste.
        ajouter_debut(personne);
    }
    else
    {
        queue->next = ajout; // Je place l'adresse d'ajout ici de façon temporaire
        ajout = queue;       // queue va prendre l'adresse d'ajout
        queue = queue->next; // L'adresse du Noeud ajouté sera maintenant la queue.
        queue->next = NULL;  // queue->next va toujours pointer sur NULL
    }
}

bool Liste::inserer_apres_numero(int nombre_recherche)
{
    // Cette fonction permet à l'utilisateur de rechercher par leur numéro, une personne dans la
    // liste. Si le nombre est trouvé, l'utilisateur peut rentrer les informations d'une nouvelle
    // personne et le Noeud sera ajouté après le numéro trouvé.
    Noeud *position_liste;
    position_liste = tete;

    // cout << "Nombre a trouver dans la liste : ";
    // int nombre_recherche;
    // cin >> nombre_recherche;
    // Boucle tant que la fin de la liste n'est pas atteinte et le numéro n'est pas trouvé
    while (position_liste != NULL && position_liste->nombre != nombre_recherche)
    {
        position_liste = position_liste->next;
    }
    if (position_liste == NULL)
    {
        // Le nombre ne se trouve pas dans la liste.
        return false;
    }
    else
    {
        Noeud personne = ajouter_personne();
        // Si le numéro trouvé est à la fin de la liste, j'appele la fonction ajouter_fin
        if (position_liste == queue)
        {
            ajouter_fin(personne);
        }
        // Sinon, un nouveau Noeud est créé et ajouter après le Noeud du numéro trouvé
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
    // Cette fonction permet également à l'utilisateur de recherché une personne par son nombre.
    // Si le numéro est trouvé, on rajoute un nouveau Noeud devant. Si le numéro revient plusieurs
    // fois, ce même nouveau Noeud est inséré devant à chaque fois.
    Noeud *position_liste, *noeud_precedent, personne;
    position_liste = tete;
    noeud_precedent = NULL;
    bool premier_nombre_trouve = false;

    // On boucle sur toute la liste, puisque un numéro peut revenir plusieurs fois, il faut
    // vérifier la liste jusqu'à la fin.
    while (position_liste != NULL)
    {
        int nombre_a_inserer;
        // Si le nombre est trouvé une première fois, on demande à l'utilisateur de rentrer
        // les informations pour une nouvelle personne.
        if (position_liste->nombre == nombre_recherche && premier_nombre_trouve == false)
        {
            personne = ajouter_personne();
            premier_nombre_trouve = true;
            // flag mis à vrai car on veut rentrer dans ce if une seule fois.
        }
        // Si le nombre est trouvé, on ajoute un nouveau Noeud devant ce nombre
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
            // Si le nombre trouvé est au début de la liste, j'appele la fonction
            // ajouter_debut()
            if (noeud_precedent == NULL && position_liste->nombre == nombre_recherche)
            {
                ajouter_debut(personne);
            }
        }
        noeud_precedent = position_liste;
        position_liste = position_liste->next;
    }
    // Si aucun nombre de trouvé, retourne faux, sinon, retourne vrai
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
    // Cette fonction permet de supprimer une personne de la liste, donc supprimer un Noeud.
    Noeud *position_liste;
    Noeud *noeud_precedent;
    position_liste = tete;
    noeud_precedent = NULL;

    // Boucle tant qu'on atteint pas la fin de la liste ou que le nom n'est pas trouvé
    cout << "nom recherche : " << nom_recherche << endl;
    while (position_liste != NULL && position_liste->nom != nom_recherche)
    {
        // On garde en mémoire le Noeud précédent, va servir si on a besoin de supprimer un Noeud
        noeud_precedent = position_liste;
        position_liste = position_liste->next;
    }
    // Si le nom a été trouvé, on peut supprimer son Noeud
    if (position_liste != NULL && position_liste->nom == nom_recherche)
    {
        if (position_liste == tete)
        {
            // On avance la tête d'une position dans la liste
            tete = position_liste->next;
        }
        else
        {
            if (position_liste == queue)
            {
                // On recule la queue d'une position dans la liste
                queue = noeud_precedent;
            }
            // On fait pointer noeud_precedent->next un Noeud plus loin dans la liste
            // Dans le fond, on saute le Noeud qui sera supprimé
            noeud_precedent->next = position_liste->next;
        }
        // Puis finalement on supprime le Noeud
        delete position_liste;
        // retourne vrai car le Noeud a été supprimé
        return true;
    }
    else
    {
        // Retourne faux car le nom n'a pas été trouvé, donc pas de suppression de Noeud
        return false;
    }
}

float Liste::moyenne_argent()
{
    // Fonction qui calcule la moyenne en argent de toutes les personnes de la liste.
    Noeud *iterateur = tete;
    float somme = 0;
    int compteur = 0;

    if (iterateur)
    {
        // Boucle sur toute la liste et additionne à la somme à chaque fois
        while (iterateur != NULL)
        {
            compteur++; // Le compteur servira pour faire la moyenne
            somme += iterateur->argent;
            iterateur = iterateur->next;
        }
        return (somme / compteur);
    }
    return 0;
}

void Liste::afficher()
{
    // Fonction qui affiche à l'écran tous les Noeuds de la liste.
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
    // Fonction permettant de supprimer une liste en la supprimant noeud par noeud
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