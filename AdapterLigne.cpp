/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

using namespace std;

const int tailleX = 3; // = Nombre de composants différents nécessaires.
const int tailleY = 2; // = Nombre de produits à prendre en compte.

double RetourneTableau()
{
    double *tab = new double[tailleX*tailleY];
    for(int i = 0;i<tailleX;i++)
    {
        for(int j = 0;j<tailleY;j++)
        {
            cin>>*(tab+i*tailleY+j); // = Qte de composant j pour le produit i.
        }   
    }
    return (*tab);
}


int TrouverColonnePivot(double *tab,double Pivot)
{
    for(int i = 0;i<tailleX;i++)
    {
        for(int j = 0;j<tailleY;j++)
        {
            if(*(tab+i*tailleY+j) = Pivot)
            {
                return j;
            }
        }
    }
}

//const int colonnePivot = TrouverColonnePivot(tab,Pivot);

int TrouverLignePivot(double *tab,double Pivot)
{
    for(int i = 0;i<tailleX;i++)
    {
        for(int j = 0;j<tailleY;j++)
        {
            if(*(tab+i*tailleY+j)= Pivot)
            {
                return j;
            }
        }
    }
}
 
//const int lignePivot = TrouverLignePivot(tab,Pivot);


void adapterLigne(double *tab, int colonnePivot, int lignePivot)
{
    for(int i = 0;i<tailleX;i++)
    {
        if(i!=lignePivot)
        {
            double x = *(tab+i*tailleY+colonnePivot);
            for(int j = 0;j<tailleY;j++)
            {
                *(tab+i*tailleY+j)=*(tab+i*tailleY+j)-(x**(tab+lignePivot*tailleY+j));
            }
        }
    }
}


/*BDD MySQL :
 *      -Utilisateur (Username, Password, Email, Grade)
 *      -Envoi (NbProduits, NbComposants, Resultat)
 *      -Produits(NomProduit, PrixProduit, QteChaqueComposant, QteProduitsCrées)
 *      -Composants (NomComposant, PrixComposant, QteComposantDispo, QteComposantRestants)
*/











