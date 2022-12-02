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

#include <iostream>
#include "liste.h"
#include <string>

using namespace std;

void efface_ecran();

int main()
{
    Liste liste_noeud;
    Noeud personne;

    int choix;
    cout << "\n\t1. Ajouter au debut\n";
    cout << "\t2. Ajouter a la fin\n";
    cout << "\t3. Inserer apres un numero\n";
    cout << "\t4. Inserer devant chaque numero\n";
    cout << "\t5. Supprimer personne\n";
    cout << "\t6. Afficher moyenne d'argent\n";
    cout << "\t7. Afficher la liste\n";
    cout << "\t8. Supprimer la liste\n";
    cout << "\n\t0 pour quitter\n\n";
    cout << "\t\tFaire un choix : ";
    cin >> choix;
    cout << endl;

    while (choix != 0)
    {
        efface_ecran();
        switch (choix)
        {
        case 1:
        case 2:
            personne = liste_noeud.ajouter_personne();
            if (choix == 1) // Si choix == 1, ajouter au début
            {
                liste_noeud.ajouter_debut(personne);
                cin.ignore();
            }
            else // Si choix == 2, ajouter à la fin
            {
                liste_noeud.ajouter_fin(personne);
                cin.ignore();
            }
            break;
        case 3:
        case 4:
            if (liste_noeud.get_tete())
            {
                int nombre;
                bool nombre_trouve = false;

                cout << "Entrez le nombre a recherche : ";
                cin >> nombre;
                if (choix == 3)
                {
                    nombre_trouve = liste_noeud.inserer_apres_numero(nombre);
                }
                else
                {
                    nombre_trouve = liste_noeud.inserer_avant_chaque_numero(nombre);
                }
                if (!nombre_trouve)
                {
                    cout << "Le nombre ne se trouve pas dans la liste.\n";
                }
            }
            break;
        case 5:
            if (liste_noeud.get_tete())
            {
                cout << "Nom de la personne a supprimer de la liste : ";
                string nom;
                getline(cin, nom);
                cout << "afficher nom : " << nom << endl;

                if (liste_noeud.supprimer_personne(nom))
                    cout << "Le Noeud a ete supprime.\n";
                else
                    cout << "Le nom ne se trouve pas dans la liste.\n";
            }
            break;
        case 6:
            if (liste_noeud.get_tete())
            {
                cout << "La moyenne d'argent en banque de toutes les personnes de la liste est : "
                     << liste_noeud.moyenne_argent() << endl;
            }
            break;
        case 7:
            if (liste_noeud.get_tete())
            {
                liste_noeud.afficher();
            }
            break;
        case 8:
            if (liste_noeud.get_tete())
            {
                liste_noeud.supprimer_liste();
                cout << "La liste a ete supprime.\n";
            }
            break;
        }
        if (!liste_noeud.get_tete())
        {
            cout << "La liste est vide.\n";
        }
        efface_ecran();
        cout << "\n\t1. Ajouter au debut\n";
        cout << "\t2. Ajouter a la fin\n";
        cout << "\t3. Inserer apres un numero\n";
        cout << "\t4. Inserer devant chaque numero\n";
        cout << "\t5. Supprimer personne\n";
        cout << "\t6. Afficher moyenne d'argent\n";
        cout << "\t7. Afficher la liste\n";
        cout << "\t8. Supprimer la liste\n";
        cout << "\n\t0 pour quitter\n\n";
        cout << "\t\tFaire un choix : ";
        cin >> choix;
        cout << endl;
    }
    cout << "Fin\n";
}
void efface_ecran()
{
    cout << "\nAppuyez sur entree pour retourner au menu.\n";
    cin.ignore();
    system("cls");
}