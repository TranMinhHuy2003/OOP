#include <iostream>
#define Max 50
using namespace std;

class Matrix {
    int mMatrix [Max][Max];
    int iN;
    int iM;
    public:
        Matrix operator+ (Matrix a)
        {
            Matrix kq;
            if (iN == a.iN && iM == a.iM) 
            {
                for (int i=0; i<iN; i++)
                {
                    for (int j=0; j<iM; j++)
                    {
                        kq.mMatrix[i][j] = mMatrix[i][j] + a.mMatrix[i][j];
                    }
                }
                return kq;
            } else {
                cout <<"\nKhong the cong 2 ma tran nay!";
            }
        }
        bool operator== (Matrix a)
        {
            if (iN != a.iN || iM != a.iM)
            {
                return false;
            }
            else 
            {
                for (int i=0; i<iN; i++)
                {
                    for (int j=0; j<iM; j++)
                    {
                        if (mMatrix[i][j] != a.mMatrix[i][j])
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        friend istream& operator>> (istream &is, Matrix &x)
        {
            do 
            {
                cout <<"\nNhap so dong: ";
                is >>x.iN;
                if (x.iN<=0 || x.iN>Max)
                {
                    cout <<"\nSo dong khong hop le, hay nhap lai!";
                }
            } while (x.iN<=0 || x.iN>Max);
            do 
            {
                cout <<"\nNhap so cot: ";
                is >>x.iM;
                if (x.iM<=0 || x.iM>Max)
                {
                    cout <<"\nSo cot khong hop le, hay nhap lai!";
                }
            } while (x.iM<=0 || x.iM>Max);
            for (int i=0; i<x.iN; i++)
            {
                for (int j=0; j<x.iM; j++)
                {
                    cout <<"\nNhap mMatrix["<<i<<"]["<<j<<"]: ";
                    is >>x.mMatrix[i][j];
                }
            }
            return is;
        }
        friend ostream& operator<< (ostream &os, Matrix x)
        {
            for (int i=0; i<x.iN; i++)
            {
                for (int j=0; j<x.iM; j++)
                {
                    os <<x.mMatrix[i][j]<<"\t";
                }
                cout <<endl;
            }
            return os;
        }
        int operator() (int x, int y)
        {
            return mMatrix[x][y];
        }
};

int main () {
    Matrix a,b;
    cin >>a>>b;
    cout <<a<<endl<<endl<<b;
    Matrix c;
    c = a + b;
    cout <<endl<<endl<<c;
    if (a==b) 
    {
        cout <<"\nTrue";
    }
    else 
    {
        cout <<"\nFalse";
    }
    cout <<endl;
    cout <<a(1,2)<<endl;
    cout <<b(3,0);
    system("pause");
    system("cls");
    return 0;
}