#include <iostream>
#include "liste.h"

using namespace std;

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

    while (choix != 0)
    {
        cout << endl;
        int nombre;

        switch (choix)
        {
        case 1:
            for (int i = 0; i < 2; i++)
            {
                personne = liste_noeud.ajouter_personne();
                // cout << "Entrer un nombre a inserer au debut de la liste : ";
                // cin >> nombre;
                liste_noeud.ajouter_debut(personne);
            }
            break;
        case 2:
            personne = liste_noeud.ajouter_personne();
            liste_noeud.ajouter_fin(personne);
            break;
        case 3:
            liste_noeud.inserer_apres_numero();
            break;
        case 4:
            liste_noeud.inserer_avant_chaque_numero();
            break;
        case 5:
            liste_noeud.supprimer_personne();
            break;
        case 6:
            liste_noeud.moyenne_argent();
            break;
        case 7:
            liste_noeud.afficher();
            break;
        case 8:
            liste_noeud.supprimer_liste();
            break;
        case 9:
            liste_noeud.print_extremites();
            break;
        }
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