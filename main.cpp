#include <iostream>
#include "GestArbre.h"

using namespace std;

int main()
{
    int n,prgrm,x;
    Arbre *a=NULL;
    cout << "Donner le nombre des neods :";
    cin >> n;
    while(n<1)
    {
        cout << "Impossible de creer une arbre!" << endl;
        cout << "Donner le nombre des neods (superieur a 0) :";
        cin >> n;
    }
    for(int i=0;i<n;i++)
    {
        cout << "Donner le valeur de neod :";
        cin >> x;
        a=Creer(a,x);
    }
    cout << "_____________________________" << endl ;
    cout << "La liste des programmes : " << endl ;
    cout << "01. Parcours RGD." << endl ;
    cout << "02. Parcours GRD." << endl ;
    cout << "03. Parcours GDR." << endl ;
    cout << "04. Recherche d'un nombre." << endl ;
    cout << "05. L'auteur d'arbre." << endl ;
    cout << "06. Niveau d'arbre." << endl ;
    cout << "07. Egalite des deux arbres." << endl ;
    cout << "08. Localement complet ou non?" << endl ;
    cout << "09. Complet ou non?" << endl ;
    cout << "10. Taille d'arbre." << endl ;
    cout << "11. Suppression d'un neod." << endl ;
    cout << "12. ABR or no ?" << endl ;
    cout << "13. Exit." << endl ;
    cout << "_____________________________" << endl ;
    do
    {
        cout << "Donner un nombre de la liste des programmes :" ;
        cin >> prgrm;
        switch(prgrm)
        {
            case 1: ParcoursRGD(a);cout << endl;break;
            case 2: ParcoursGRD(a);cout << endl;break;
            case 3: ParcoursGDR(a);cout << endl;break;
            case 4: {
                        cout << "Donner un nombre pour recherche : ";
                        cin >> x;
                        if(Recherche(a,x))
                        {
                            cout << "le nombre " << x << " est existe dans l'arbre." << endl ;
                        }
                        else
                        {
                            cout << "le nombre " << x << " n'est existe pas dans l'arbre." << endl ;
                        }
                    }break;
            case 5: {
                        cout << "L'auteur d'arbre est : " << Hauteur(a) << endl ;
                    }break;
            case 6: {
                        cout << "Le Niveau d'arbre est : " << Niveau(a) << endl ;
                    }break;
            case 7: {
                        Arbre *b=NULL;
                        cout << "Donner les nombres des neods de la 2 eme arbre :";
                        cin >> n;
                        while(n<1)
                        {
                            cout << "Impossible de creer une arbre!" << endl;
                            cout << "Donner le nombre des neods (superieur a 0) :";
                            cin >> n;
                        }
                        for(int i=0;i<n;i++)
                        {
                            cout << "Donner le valeur de neod :";
                            cin >> x;
                            b=Creer(b,x);
                        }
                        if(Egale(a,b))
                        {
                            cout << "Les deux arbres sont egaux." << endl;
                        }
                        else
                        {
                            cout << "Les deux arbres ne sont pas egaux." << endl;
                        }
                    }break;
            case 8: {
                        if(LocalementComp(a))
                        {
                            cout << "L'arbre est localement complet." << endl;
                        }
                        else
                        {
                            cout << "L'arbre n'est pas localement complet." << endl;
                        }
                    }break;
            case 9: {
                        if(Complet(a))
                        {
                            cout << "L'arbre est complet." << endl;
                        }
                        else
                        {
                            cout << "L'arbre n'est pas complet." << endl;
                        }
                    }break;
            case 10:{
                        cout << "La taille d'arbre est : " << Taille(a) << endl;
                    }break;
            case 11:{
                        cout << "Donner la valeur pour suprimer : " ;
                        cin >> x;
                        a=Suppression(a,x);
                    }break;
            case 12:{
                        if(ABR(a))
                        {
                            cout << "est un ABR." << endl ;
                        }
                        else
                        {
                            cout << "n'est pas ABR." << endl ;
                        }
                    }break;
            case 13:{
                        cout << "__________________________________________________________________________" << endl;
                        cout << "                          En cours d'exite ........." << endl;
                        cout << "__________________________________________________________________________" << endl;
                    }break;
            default :   {
                            cout << "________________________________________________________" << endl;
                            cout << "Le nombre "<< prgrm << " n'existe pas dans la liste des programmes!" << endl ;
                            cout << "________________________________________________________" << endl;
                        }break;
        }
    }while((prgrm!=13));
    return 0;
}
