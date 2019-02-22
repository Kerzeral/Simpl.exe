#include <cstdlib>
#include <iostream>
//#include <mysql_connection.h>

//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/resultset.h>
//#include <cppconn/statement.h>

using namespace std;
const int typeOperation = 1;
const int nbProduits = 2;
const int nbComposants = 2;
const int tailleX = nbComposants+1; // = Nombre de composants différents nécessaires + 1 (Prix).
const int tailleY = nbProduits+nbComposants+1; // = Nombre de produits à prendre en compte + nombre de composants + 1 (stocks).

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

double* RemplirTableau(double *tab)
{
    int a = nbProduits;
    for(int i = 0;i<tailleX;i++)
    {
        for(int j = 0;j<tailleY;j++)
        {
            if(j<nbProduits && i!=tailleX-1)
            {
                cout<<"Entrez la quantite de composant "<<i+1<<" pour le produit "<<j+1<<endl;
                cin>>*(tab+i*tailleY+j); // = Qte de composant j pour le produit i.
            }
            else if(j>=nbProduits && i!=tailleX-1)
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
            else if(i==tailleX-1 && j<nbProduits)
            {
                cout<<"Entrez le prix du produit "<<j+1<<endl;
                cin>>*(tab+i*tailleY+j);
            }
            else if(j>nbProduits && i==tailleX-1)
            {
                *(tab+i*tailleY+j)=0;
            }       
        }  
        a++;
    }
    return tab;
}

int CoeffMax(double *tab) // Permet de trouver la colonne du pivot 
{
  int i, j;
  int ColonnePivot;
  double Coeff=0;
  
  for(i=0; i<tailleX; i++)
  {
      for(j=0;j<tailleY-1; j++)
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

int definirRatio (double *tab,double *ratio,int colonnePivot) //fonction qui calcule les ratios et qui retourne la ligne du pivot en fonction des ratios
{
    double min=999999;
    int LignePivot;
    for(int i=0; i<tailleX; i++)
    {
        for (int j=0;j<tailleY; j++)
        {
            if(j==tailleY-1 && i!=tailleX-1)
            {
                *(ratio+i)=*(tab+i*tailleY+j)/(*(tab+i*tailleY+colonnePivot));
                if(*(ratio+i)<min)
                {
                    min=*(ratio+i);
                    LignePivot=i;
                }
            }
        }   
    }
    return LignePivot;
}

double* ReductionLigne(double *tab, int lignePivot, int colonnePivot) //fonction qui divise toute la ligne pivot par le pivot
{    
    double pivot=*(tab+lignePivot*tailleY+colonnePivot);
    for(int j=0;j<tailleY;j++)
    {
      *(tab+lignePivot*tailleY+j)=*(tab+lignePivot*tailleY+j)/pivot;
    }
    return tab;
}

double* adapterLigne(double *tab, int lignePivot, int colonnePivot) //fonction qui adapte les lignes en fonction de la ligne pivot
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
    return tab;
}


bool VerifCoef(double *tab) //fonction qui verifie la signe des coeffs
{
    for(int j=0;j<tailleY;j++)
    {
        if (*(tab+(tailleX-1)*tailleY+j)>0)
        {
            return false;
        }
    }
    return true;
}


int main(int argc, char** argv) 
{
    double *tab = new double[tailleX*tailleY];
    double *ratio = new double[tailleX];
    tab = RemplirTableau(tab);
    Affiche(tab);
    int colonnePivot;
    int lignePivot;
    
    do
    {
        colonnePivot = CoeffMax(tab);
        //cout<<colonnePivot<<endl;
        lignePivot = definirRatio(tab, ratio, colonnePivot);
        //cout<<lignePivot<<endl;
        tab = ReductionLigne(tab,lignePivot,colonnePivot);
        //Affiche(tab);
        tab = adapterLigne(tab,lignePivot,colonnePivot);
        //Affiche(tab);
        //VerifCoef(tab);
    }
    while(VerifCoef(tab)==false);
    Affiche(tab);
    return 0;
}


/*BDD MySQL :
 *      -Utilisateur (Username, Password, Email, Grade)
 *      -Envoi (NbProduits, NbComposants, Resultat)
 *      -Produits(NomProduit, PrixProduit, QteChaqueComposant, QteProduitsCrées)
 *      -Composants (NomComposant, PrixComposant, QteComposantDispo, QteComposantRestants)
*/