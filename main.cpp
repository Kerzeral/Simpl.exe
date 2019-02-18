#include <cstdlib>

using namespace std;

/*
 */
int main() 
{

    const int taillex = requete(x); //requete donnees SQL Nombre lignes
    const int tailley = requette(y); //requete donnees SQL Nombre colonnes
    double tableau[tailley][taillex] = {{...}, ..., {...}}; //requete pour remplir tab  
    double pivot = DefinirPivot(tableau); //Trouver le pivot dans le tableau
    int NumeroLignePivot = TrouverLigne(tableau, pivot, taillex, tailley); // On trouve la ligne du Pivot
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

