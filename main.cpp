#include <cstdlib>
#include <iostream>
//#include "AdapterLigne.cpp"

using namespace std;

const int tailleX = 4; // = Nombre de composants différents nécessaires.
const int tailleY = 6; // = Nombre de produits à prendre en compte + les e + les stocks.

void Affiche(double *tab)
{
    for(int i=0;i<tailleX;i++)
    {
    for(int j=0;j<tailleY;j++)
    {
     cout<<*(tab+i*tailleY+j)<<" ";
    }
    cout<<endl;
    }
    cout<<endl;
}

void RemplirTableau(double *tab)
{
    int a = (tailleY/2)-1;
    for(int i = 0;i<tailleX;i++)
    {
        for(int j = 0;j<tailleY;j++)
        {
            if(j<(tailleY/2)-1 && i!=tailleX-1)
            {
                cout<<"Entrez la quantite de composant "<<i+1<<" pour le produit "<<j+1<<endl;
                cin>>*(tab+i*tailleY+j); // = Qte de composant j pour le produit i.
            }
            else if(j>=(tailleY/2)-1 && i!=tailleX-1)
            {
                if(j==tailleY-1)
                {
                    cout<<"Entrez le stock de composant "<<i+1<<endl;
                    cin>>*(tab+i*tailleY+j);
                }
                else if(j==a)
                {
                    *(tab+i*tailleY+j)=1;
                }
                else
                {
                    *(tab+i*tailleY+j)=0;
                }
            }
            else if(i==tailleX-1 && j<(tailleY/2)-1)
            {
                cout<<"Entrez le prix du produit "<<j+1<<endl;
                cin>>*(tab+i*tailleY+j);
            }
            else if(j>(tailleY/2)-1 && i==tailleX-1)
            {
                *(tab+i*tailleY+j)=0;
            }       
        }  
        a++;
    }
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



int main(int argc, char** argv) 
{
    double *tab = new double[tailleX*tailleY];
    RemplirTableau(tab);
    Affiche(tab);
    
    return 0;
}
