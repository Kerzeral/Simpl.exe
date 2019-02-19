#include <cstdlib>
#include <iostream>
//#include "AdapterLigne.cpp"

using namespace std;

const int tailleX = 3; // = Nombre de composants différents nécessaires + 1 (Prix).
const int tailleY = 5; // = Nombre de produits à prendre en compte + 1 par e + 1 (stocks).

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
            if(j<(tailleY/2) && i!=tailleX-1)
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
            else if(i==tailleX-1 && j<(tailleY/2))
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


int CoeffMax(double *tab) // Permet de trouver la colonne du pivot 
{
  int i, j;
  int ColonnePivot;
  double Coeff=0;
  
  for(i=0; i<tailleX; i++)
  {
      for(j=0;i<tailleY; j++)
      {
          if(*(tab+i*tailleY+j) > Coeff)
          {
             Coeff=*(tab+i*tailleY+j); 
             ColonnePivot=j;
          }
      }
  }
   return ColonnePivot; 
}

/*int TrouverColonnePivot(double *tab,double Pivot)
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
}*/

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
    int ColonnePivot = CoeffMax(tab);
    delete tab;
    return 0;
}
