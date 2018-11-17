#ifndef MOSTENIRI_H_INCLUDED
#define MOSTENIRI_H_INCLUDED
#include "Clase.h"
using namespace std;

Matrice::Matrice()
{
    cout<<"Constructorul matricei. Va rog, introduceti dimensiunea:";
    cin>>noduri;
    a = new int*[noduri];
    for(int i=0;i<noduri;i++)
    {
        a[i] = new int[noduri];
    }
    for(int i=0;i<noduri;i++)
    {
        for(int j=0;j<noduri;j++)
            a[i][j] = 0;
    }
};

Matrice::Matrice(const Matrice& ob)
{
    int noduri = ob.noduri;
    for(int i = 0; i<noduri; i++)
    {
        a[i] = new int[ob.noduri];
        for(int j = 0; j<noduri; j++) a[i][j] = ob.a[i][j];
    }
};

Matrice::~Matrice()
{
    for(int i = 0; i<noduri; i++)
        delete[] a[i];
    delete[] a;
    cout<<"Destructor finalizat cu succes."<<endl;
}

istream& operator>>(istream& in, Matrice &M)
{
    int noduri;
    cout<<"Introduceti de la tastatura toate datele matricei:"<<endl;
    for(int i=0; i<noduri; i++)
    {
        for(int j=0; j<noduri; j++)
        {
            cout<<"V["<<i+1<<"]["<<j+1<<"]=";
            in>>M.a[i][j];
        }
    }
    cout<<endl;
    return in;
}

ostream& operator<<(ostream& out, Matrice &M)
{
    int noduri;
    for(int i=0; i<noduri; i++)
    {
        for(int j=0; j<noduri; j++)
        {
            out<<M.a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return out;
}

Matrice& Matrice::operator=(const Matrice& ob)
{
    if(this != &ob)
    {
        if(a)
        {
            for(int i = 0; i<noduri; i++)
            {
                if(a[i])delete[] a[i];
            }
            delete[] a;
        }
        noduri = ob.noduri;
        a = new int*[ob.noduri];
        for(int i = 0; i<ob.noduri; i++)
        {
            a[i] = new int[ob.noduri];
            for(int j = 0; j<ob.noduri; j++) a[i][j] = ob.a[i][j];
        }
    }
}

Vector::Vector()
{
    cout<<"Initializarea vectorului pentru nod. Va rog, introduceti dimensiunea:";
    cin>>dim;
    v = new int[dim];
    for(int i=0;i<dim;i++)
    {
        v[i] = 0;
    }
};

Vector::Vector(const Vector& ob)
{
    int dim = ob.dim;
    v = new int[ob.dim];
    for(int i = 0; i<dim; i++)
    {
        v[i] = ob.v[i];
    }
};

Vector::~Vector()
{
    delete[] v;
    cout<<"Destructor vector finalizat cu succes!";
}

Vector& Vector::operator=(const Vector& ob)
{
    if(this != &ob)
    {
        if(v)
        {
            delete[] v;
        }
        dim = ob.dim;
        v = new int[ob.dim];
        for(int i = 0; i<ob.dim; i++)
        {
            v[i] = ob.v[i];
        }
    }
};

istream& operator>>(istream& in, Vector &ob)
{
    cout<<"Introduceti de la tastatura toate datele vectorului pentru nod:"<<endl;
    for(int i=0; i<ob.dim; i++)
    {
        cout<<"V["<<i+1<<"]=";
        in>>ob.v[i];
    }
    cout<<endl;
    return in;
}

ostream& operator<<(ostream& out, Vector &ob)
{
    for(int i=0; i<ob.dim; i++)
    {
        out<<ob.v[i]<<" ";
    }
    cout<<endl;
    return out;
}

#endif // MOSTENIRI_H_INCLUDED
