/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

const int tailleX = 2; // = Nombre de composants différents nécessaires.
const int tailleY = 2; // = Nombre de produits à prendre en compte.

double RetourneTableau()
{
    double tab;
    tab = new double[tailleX][tailleY];
    for(int i = 0;i<tailleY;i++)
    {
        for(int j = 0;j<tailleX;j++)
        {
            tab[i][j] = 0; // = Qte de composant j pour le produit i.
        }   
    }
    return tab;
}


int TrouverColonnePivot(double tab,double Pivot)
{
    for(int i = 0;i<tailleY;i++)
    {
        for(int j = 0;j<tailleX;j++)
        {
            if(tab[i][j] = Pivot)
            {
                return j;
            }
        }
    }
}

//const int colonnePivot = TrouverColonnePivot(tab,Pivot);

int TrouverLignePivot(double tab,double Pivot)
{
    for(int i = 0;i<tailleY;i++)
    {
        for(int j = 0;j<tailleX;j++)
        {
            if(tab[i][j] = Pivot)
            {
                return j;
            }
        }
    }
}
 
//const int lignePivot = TrouverLignePivot(tab,Pivot);


/*BDD MySQL :
 *      -Utilisateur (Username, Password, Email, Grade)
 *      -Envoi (NbProduits, NbComposants, Resultat)
 *      -Produits(NomProduit, PrixProduit, QteChaqueComposant, QteProduitsCrées)
 *      -Composants (NomComposant, PrixComposant, QteComposantDispo, QteComposantRestants)
*/


















