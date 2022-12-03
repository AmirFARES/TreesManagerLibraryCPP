#include <iostream>

using namespace std;

// Structures _____________________________________
typedef struct Arbre{
    int val;
    struct Arbre *fg;
    struct Arbre *fd;
}Arbre;

// Prototype _____________________________________
void ParcoursRGD(Arbre *a);
void ParcoursGRD(Arbre *a);
void ParcoursGDR(Arbre *a);
Arbre* Creer(Arbre *a,int x);
bool Egale(Arbre *a,Arbre *b);
bool Recherche(Arbre *a,int x);
int Niveau(Arbre *a);
int Hauteur(Arbre *a);
bool LocalementComp(Arbre *a);
bool Complet(Arbre *a);
int Taille(Arbre *a);
Arbre * RechercheADD(Arbre *a,int x);
Arbre * PereADD(Arbre *a,int x);
Arbre * Suppression(Arbre *a,int x);
Arbre * SuppFeuille(Arbre *a,Arbre *ptr);
Arbre * SuppInt(Arbre *a,Arbre *ptr);//suppression de neod de seul fils
Arbre * SuppIntFG(Arbre *a,Arbre *ptr);//suppression de neod de deux fils
Arbre * MinAdd(Arbre *a);
Arbre * MaxAdd(Arbre *a);
Arbre * Successeur(Arbre *ptr);
Arbre * Predecesseur(Arbre *ptr);
bool ABR(Arbre *a);

// Functions _____________________________________
void ParcoursRGD(Arbre *a)
{
    if(a!=NULL)
    {
        cout << a->val << " " ;
        ParcoursRGD(a->fg);
        ParcoursRGD(a->fd);
    }
}

void ParcoursGRD(Arbre *a)
{
    if(a!=NULL)
    {
        ParcoursGRD(a->fg);
        cout << a->val << " " ;
        ParcoursGRD(a->fd);
    }
}

void ParcoursGDR(Arbre *a)
{
    if(a!=NULL)
    {
        ParcoursGDR(a->fg);
        ParcoursGDR(a->fd);
        cout << a->val << " " ;
    }
}

int Niveau(Arbre *a)
{
    if(a==NULL)
    {
        return 0;
    }
    else
    {
        int g=1+Niveau(a->fg);
        int d=1+Niveau(a->fd);
        if(g>d)
        {
            return g;
        }
        else
        {
            return d;
        }
    }
}

int Hauteur(Arbre *a)
{
    return (Niveau(a)-1);
}

Arbre* Creer(Arbre *a,int x)
{
    Arbre *ptr=new Arbre,*k=a,*prec;
    ptr->val=x;
    ptr->fg=NULL;
    ptr->fd=NULL;
    if(a==NULL)
    {
        return ptr;
    }
    else
    {
        while(k!=NULL)
        {
            prec=k;
            if(x<k->val)
            {
                k=k->fg;
            }
            else
            {
                k=k->fd;
            }
        }
        if(x<prec->val)
        {
            prec->fg=ptr;
        }
        else
        {
            prec->fd=ptr;
        }
        return a;
    }
}

bool Egale(Arbre *a,Arbre *b)
{
    if((a==NULL)&&(b==NULL))
    {
        return true;
    }
    else
    {
        if(((a==NULL)&&(b!=NULL))||((a!=NULL)&&(b==NULL)))
        {
            return false;
        }
        else
        {
            return((a->val==b->val)&&(Egale(a->fg,b->fg))&&(Egale(a->fd,b->fd)));
        }
    }
}

bool Recherche(Arbre *a,int x)
{
    while(a!=NULL)
    {
        if(a->val==x)
        {
            return true;
        }
        else
        {
            if(x<a->val)
            {
                a=a->fg;
            }
            else
            {
                a=a->fd;
            }
        }
    }
}

bool LocalementComp(Arbre *a)
{
    if(a!=NULL)
    {
        if(((a->fg==NULL)&&(a->fd!=NULL))||((a->fg!=NULL)&&(a->fd==NULL)))
        {
            return 0;
        }
        else
        {
            return((((a->fg==NULL)&&(a->fd==NULL))||((a->fg!=NULL)&&(a->fd!=NULL)))&&(LocalementComp(a->fg))&&(LocalementComp(a->fd)));
        }
    }
    else
    {
        return 1;
    }
}

bool Complet(Arbre *a)
{
    if(a!=NULL)
    {
        int g=Niveau(a->fg);
        int d=Niveau(a->fd);
        return ((g==d)&&(Complet(a->fg))&&(Complet(a->fd)));
    }
    else
    {
        return 1;
    }
}

int Taille(Arbre *a)
{
    if(a==NULL)
    {
        return 0;
    }
    else
    {
        return (1+Taille(a->fg)+Taille(a->fd));
    }
}

Arbre * RechercheADD(Arbre *a,int x)
{
    while(a!=NULL)
    {
        if(a->val==x)
        {
            return a;
        }
        else
        {
            if(x<a->val)
            {
                a=a->fg;
            }
            else
            {
                a=a->fd;
            }
        }
    }
}

Arbre * PereADD(Arbre *a,int x)
{
    Arbre *prec=NULL;
    while(a!=NULL)
    {
        if(a->val==x)
        {
            return prec;
        }
        else
        {
            prec=a;
            if(x<a->val)
            {
                a=a->fg;
            }
            else
            {
                a=a->fd;
            }
        }
    }
    return NULL;
}

/*Arbre *Suppression(Arbre *a,int x)
{
    Arbre *ptr=RechercheADD(a,x),*p=PereADD(a,x);
    if(ptr!=NULL)
    {
        if(a!=ptr)
        {
            if((ptr->fg==NULL)&&(ptr->fd==NULL))
            {
                if(p->fg==ptr)
                {
                    p->fg=NULL;
                }
                else
                {
                    p->fd=NULL;
                }
                delete(ptr);
            }
            else
            {
                if((ptr->fd==NULL)||(ptr->fg==NULL))
                {
                    if(p->fg==ptr)
                    {
                        if(ptr->fg!=NULL)
                        {
                            p->fg=ptr->fg;
                        }
                        else
                        {
                            p->fg=ptr->fd;
                        }
                    }
                    else
                    {
                        if(ptr->fg!=NULL)
                        {
                            p->fd=ptr->fg;
                        }
                        else
                        {
                            p->fd=ptr->fd;
                        }
                    }
                    delete(ptr);
                }
                else//////////////////////////////////////////////////////////////////
                {
                    Arbre *succ=Successeur(ptr);
                    Arbre * fid=ptr->fd;
                    if(succ==fid)
                    {
                        if(p->fd==ptr)
                        {
                            p->fd=succ;
                        }
                        else
                        {
                            p->fg=succ;
                        }
                        succ->fg=ptr->fg;
                    }
                    else
                    {
                        if(p->fd==ptr)
                        {
                            p->fd=succ;
                        }
                        else
                        {
                            p->fg=succ;
                        }
                        succ->fg=ptr->fg;
                        //
                        while(succ->fd!=NULL)
                        {
                            succ=succ->fd;
                        }
                        if(fid->val<succ->val)
                        {
                            succ->fg=fid;
                        }
                        else
                        {
                            succ->fd=fid;
                        }
                    }
                    delete(ptr);
                }
            }
        }
        else
        {
            Arbre *succ=Successeur(ptr);
            Arbre * fid=ptr->fd;
            Arbre * fig=ptr->fg;
            if(succ==fid)
            {
                a=succ;
                Arbre *sd=succ,*sg=succ;
                while(sg->fg!=NULL)
                {
                    sg=sg->fg;
                }
                sg->fg=fig;
            }
            else
            {
                a=succ;
                Arbre * ps=PereADD(a,succ->val);
                if(ps->fg==succ)
                {
                    ps->fg=NULL;
                }
                else
                {
                    ps->fd==NULL;
                }

                succ->fd=fid;
                a->fg=fig;
            }
            delete(ptr);
        }
    }
    return a;
}*/

Arbre * MinAdd(Arbre *a)
{
    if(a==NULL)
    {
        return NULL;
    }
    else
    {
        while(a->fg!=NULL)
        {
            a=a->fg;
        }
        return a;
    }
}

Arbre * MaxAdd(Arbre * a)
{
    if(a==NULL)
    {
        return NULL;
    }
    else
    {
        while(a->fd!=NULL)
        {
            a=a->fd;
        }
        return a;
    }
}

Arbre * Successeur(Arbre *ptr)
{
    if(ptr->fd==NULL)
    {
        cout << "N'est pas successeur." << endl;
    }
    return (MinAdd(ptr->fd));
}

Arbre * Predecesseur(Arbre *ptr)
{
    if(ptr->fg)
    {
        cout << "N'est pas predecesseur." << endl;
    }
    return (MaxAdd(ptr->fg));
}

Arbre * SuppFeuille(Arbre *a,Arbre *ptr)
{
    if(ptr==a)
    {
        delete ptr;
        return NULL;
    }
    else
    {
        Arbre *p=PereADD(a,ptr->val);
        if(p->fg==ptr)
        {
            p->fg=NULL;
        }
        else
        {
            p->fd=NULL;
        }
        delete (ptr);
        return (a);
    }
}

Arbre * SuppInt(Arbre *a,Arbre *ptr)
{
    if(a==ptr)
    {
        Arbre *tmp;
        if(ptr->fg!=NULL)
        {
            tmp=ptr->fg;
        }
        else
        {
            tmp=ptr->fd;
        }
        delete ptr;
        return tmp;
    }
    else
    {
        Arbre * p=PereADD(a,ptr->val);
        if(p->fg==ptr)
        {
            if(ptr->fg!=NULL)
            {
                p->fg=ptr->fg;
            }
            else
            {
                p->fg=ptr->fd;
            }
        }
        else
        {
            if(ptr->fg!=NULL)
            {
                p->fd=ptr->fg;
            }
            else
            {
                p->fd=ptr->fd;
            }
        }
        delete(ptr);
        return a;
    }
}

Arbre * SuppIntFG(Arbre *a,Arbre *ptr)
{
    if(a==ptr)
    {
        Arbre *succ=Successeur(ptr);
        succ->fg=ptr->fg;
        ptr->fg=NULL;
        Arbre *succpere=PereADD(a,succ->val);
        if(succpere->fg==succ)
        {
            succpere->fg=NULL;
        }
        else
        {
            succpere->fd=NULL;
        }
        Arbre *tmp=succ;
        while(tmp->fd!=NULL)
        {
            tmp=tmp->fd;
        }
        tmp->fd=ptr->fd;
        delete ptr;
        return succ;
    }
    else
    {
        Arbre *succ=Successeur(ptr);
        succ->fg=ptr->fg;
        ptr->fg=NULL;
        Arbre *succpere=PereADD(a,succ->val);
        if(succpere->fg==succ)
        {
            succpere->fg=NULL;
        }
        else
        {
            succpere->fd=NULL;
        }
        Arbre *tmp=succ;
        while(tmp->fd!=NULL)
        {
            tmp=tmp->fd;
        }
        tmp->fd=ptr->fd;
        Arbre *p=PereADD(a,ptr->val);
        if(p->fg==ptr)
        {
            p->fg=succ;
        }
        else
        {
            p->fd=succ;
        }
        delete ptr;
        return a;
    }
}

Arbre * Suppression(Arbre *a,int x)
{
    Arbre *ptr=RechercheADD(a,x);
    if(ptr==NULL)
    {
        cout << x << "n'existe pas dans l'arbre." << endl;
    }
    else
    {
        if((ptr->fg==NULL)&&(ptr->fd==NULL))
        {
            a=SuppFeuille(a,ptr);
        }
        else
        {
            if((ptr->fg==NULL)||(ptr->fd==NULL))
            {
                a=SuppInt(a,ptr);
            }
            else
            {
                a=SuppIntFG(a,ptr);
            }
        }
    }
    return a;
}
