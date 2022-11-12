#include <iostream>
using namespace std;

class Sophuc {
    float phanthuc, phanao;
    public:
        Sophuc operator+ (Sophuc a)
        {
            Sophuc kq;
            kq.phanthuc = phanthuc + a.phanthuc;
            kq.phanao = phanao + a.phanao;
            return kq;
        }
        friend istream& operator>> (istream &is, Sophuc &x)
        {
            cout <<"\nNhap phan thuc: ";
            is>>x.phanthuc;
            cout <<"\nNhap phan ao: ";
            is>>x.phanao;
            return is;
        }
};

int main () 
{
    system("pause");
    system("cls");
    return 0;
}