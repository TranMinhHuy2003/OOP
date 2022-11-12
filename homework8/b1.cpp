#include <iostream>
using namespace std;

class Vector;
class MaTrix 
{
    int a[100][100];
    int iN;
    int iM;
    friend istream& operator>> (istream &is, MaTrix &x)
    {
        cout <<"\nNhap so dong: ";
        is>>x.iM;
        cout <<"\nNhap so cot: ";
        is>>x.iN;
        for (int i = 0; i < x.iM; i++)
        {
            for (int j = 0; j < x.iN; j++)
            {
                cout <<"\nNhap a["<<i<<"]["<<j<<"]: ";
                is>>x.a[i][j];
            }
        }
        return is;
    }
    friend ostream& operator<< (ostream &os, MaTrix x)
    {
        for (int i = 0; i < x.iM; i++)
        {
            for (int j = 0; j < x.iN; j++)
            {
                os <<x.a[i][j]<<" ";
            }
            os <<endl;
        }
        return os;
    }
    friend Vector operator* (MaTrix a, Vector b);
};

class Vector 
{
    int a[100];
    int iN;
    friend istream& operator>> (istream &is, Vector &x)
    {
        cout <<"\nNhap so luong phan tu: ";
        is>>x.iN;
        for (int i = 0; i < x.iN; i++)
        {
            cout <<"\nNhap a["<<i<<"]: ";
            is>>x.a[i];
        }
        return is;
    }
    friend ostream& operator<< (ostream &os, Vector x)
    {
        for (int i = 0; i < x.iN; i++)
        {
            os <<x.a[i]<<" ";
        }
        return os;
    }
    friend Vector operator* (MaTrix a, Vector b)
    {
        Vector kq;
        kq.iN = a.iM;
        for (int i = 0; i < a.iM; i++)
        {
            for (int j = 0; j < a.iN; j++)
            {
                kq.a[i] += a.a[i][j] * b.a[j];
            }
        }
        return kq;
    }
};

int main ()
{
    MaTrix a;
    Vector b;
    cin>>a>>b;
    Vector c = a * b;
    cout <<c;
    system ("pause");
    system ("cls");
    return 0;
}