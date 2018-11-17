#ifndef CLASE_H_INCLUDED
#define CLASE_H_INCLUDED

using namespace std;

//Matrice de adiacenta
class Matrice
{
    private:
            int **a;
            int noduri;
    public:
            Matrice();
            Matrice(const Matrice& ob);
            ~Matrice();
            friend istream& operator>>(istream&, Matrice &);
            friend ostream& operator<<(ostream&, Matrice &);
            Matrice& operator=(const Matrice&);
};

//Vector
class Vector
{
    private:
            int *v;
            int dim;
    public:
            Vector();
            Vector(const Vector& ob);
            ~Vector();
            friend istream& operator>>(istream&, Vector &);
            friend ostream& operator<<(ostream&, Vector &);
            Vector& operator=(const Vector&);
};
#endif // CLASE_H_INCLUDED
