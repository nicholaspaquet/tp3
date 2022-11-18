#include <iostream>
#include "liste.h"

using namespace std;

int main()
{
    Liste liste_noeud;

    int choix;
    cout << "\n\t1. Afficher liste chainee\n";
    cout << "\t2. Ajouter au debut\n";
    cout << "\t3. Ajouter apres\n";
    cout << "\t4. Ajouter avant\n";
    cout << "\t5. Supprimer noeud\n\n";
    cout << "\t0 pour quitter\n\n";
    cout << "\t\tFaire un choix : ";
    cin >> choix;

    while (choix != 0)
    {
        cout << endl;
        switch (choix)
        {
        case 1:
            liste_noeud.afficher();
            break;
        case 2:
            for (int i = 0; i < 4; i++)
                liste_noeud.ajouter_debut();
            break;
        case 3:
            liste_noeud.ajouter_apres();
            break;
        case 4:
            liste_noeud.ajouter_avant();
            break;
        case 5:
            liste_noeud.supprimer_noeud();
            break;
        case 6:
            liste_noeud.print_extremites();
            break;
        }
        cout << "\n\t1. Afficher liste chainee\n";
        cout << "\t2. Ajouter au debut\n";
        cout << "\t3. Ajouter apres\n";
        cout << "\t4. Ajouter avant\n";
        cout << "\t5. Supprimer noeud\n\n";
        cout << "\t0 pour quitter\n\n";
        cout << "\t\tFaire un choix : ";
        cin >> choix;
        cout << endl;
    }
    cout << "Fin\n";
}