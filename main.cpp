#include <cstdlib>

using namespace std;

bool VerifCoef(double Tableau, int tailleX, int tailleY) // Tableau modifié par les calculs (max/min)
{
int i = nb_parametres; // i=nb de paramètres, exemple : Houblon, malt, orge = 3 paramètres
int j = nb_produits; // j=nb de produits, exemple : blonde, brune = 2 produits

for(Tableau[tailleX][i];i<=j;i++)
	{if i<=0{bool=true; //si la valeur de la case est égale ou inférieure à 0
			continue;} //jusque-là tout va bien, alors on continue
	else{bool=false; //si la valeur est strictement supérieure à 0
			break;}} // PAF, on sort de la boucle
return bool;
}

int main() 
{

    const int taillex = requete(x); //requete donnees SQL Nombre lignes
    const int tailley = requette(y); //requete donnees SQL Nombre colonnes
    double tableau[tailley][taillex] = {{...}, ..., {...}}; //requete pour remplir tab  
    double pivot = DefinirPivot(tableau); //Trouver le pivot dans le tableau
    int NumeroLignePivot = TrouverLignePivot(tableau, pivot, taillex, tailley); // On trouve la ligne du Pivot
    double LignePivot = ExtractionLigne(tableau, NumeroLignePivot); // on extrait la ligne du pivot
    double ReductionPivot = ReductionLigne(LignePivot); // on reduit la ligne du pivot
    RemplacerLigne(tableau, ReductionPivot, taillex, tailley); // on remet la ligne reduite du pivot dans le tableau
    
    fonctionColonneHugo(); // on trouve un ratio pour reduire les lignes et on le fait
    /*
 	

                                   __
                               _.-~  )
                    _..--~~~~,'   ,-/     _
                 .-'. . . .'   ,-','    ,' )
               ,'. . . _   ,--~,-'__..-'  ,'
             ,'. . .  (@)' ---~~~~      ,'
            /. . . . '~~             ,-'
           /. . . . .             ,-'
          ; . . . .  - .        ,'
         : . . . .       _     /
        . . . . .          `-.:
       . . . ./  - .          )
      .  . . |  _____..---.._/ _____
~---~~~~----~~~~             ~~
 */
    
    bool test = false; //on cree une variable booleene de test
    do{
       test = VerifCoef(tableau, taillex, tailley); //on verifie les coeficient 
       //pour etre certain qu'aucune reduction suplementaire n'est possible
       (test == false) ? fonctionColonneHugo(); // si d'autres reductions sont possible on readapte les colonnes
     }while(test == false);
    
     EnvoieRsultatVersSqL(); // on envoie le resultat vers le SqL

   
   
    
    return 0;
}

