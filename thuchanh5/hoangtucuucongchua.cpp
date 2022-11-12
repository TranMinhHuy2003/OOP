#include <iostream>
using namespace std;

class gate
{
    protected:
        int loai;
    gate ()
    {

    }
    ~gate ()
    {

    }
    public:
        virtual void Nhap () = 0;
        virtual int TraVe () = 0;
        int GetLoai () 
        {
            return loai;
        }
};

class business_gate : public gate
{
    int dongia, sohang;
    public:
        business_gate ()
        {
            loai = 1;
        }
        ~business_gate ()
        {

        }
        void Nhap ()
        {
            cout <<"\nNhap don gia: ";
            cin >> dongia;
            cout <<"\nNhap so hang: ";
            cin >> sohang;
        }
        int TraVe ()
        {
            return dongia*sohang;
        }
};

class academic_gate : public gate
{
    int tritue;
    public:
        academic_gate ()
        {
            loai = 2;
        }
        ~academic_gate ()
        {

        }
        void Nhap ()
        {
            cout <<"\nNhap chi so tri tue: ";
            cin >> tritue;
        }
        int TraVe ()
        {
            return tritue;
        }
};

class power_gate : public gate
{
    int sucmanh;
    public:
        power_gate ()
        {
            loai = 3;
        }
        ~power_gate ()
        {

        }
        void Nhap ()
        {
            cout <<"\nNhap chi so suc manh: ";
            cin >>sucmanh;
        }
        int TraVe ()
        {
            return sucmanh;
        }
};

int main ()
{
    int n;
    cout <<"\nNhap so luong cong: ";
    cin >> n;
    gate** DScong = new gate* [n];
    for (int i = 0; i < n; i++)
    {
        int luachon;
        cout <<"\nNhap loai cong: ";
        cin >> luachon;
        if (luachon == 1)
        {
            DScong[i] = new business_gate;
        }
        if (luachon == 2)
        {
            DScong[i] = new academic_gate;
        }
        if (luachon == 3)
        {
            DScong[i] = new power_gate;
        }
        DScong[i]->Nhap();
    }
    int tien, sotritue, sosucmanh;
    cout <<"\nNhap tien: ";
    cin >>tien;
    cout <<"\nNhap chi so tri tue: ";
    cin >>sotritue;
    cout <<"\nNhap chi so suc manh: ";
    cin >>sosucmanh;
    int i = 0;
    while (tien > 0 && sotritue > 0 && sosucmanh > 0 && i < n)
    {
        if (DScong[i]->GetLoai() == 1)
        {
            tien -= DScong[i]->TraVe();
            if (tien <= 0)
            {
                cout <<"\nHoang tu da that bai o cong thu "<<i + 1;
                return 0;
            }    
        }
        else if (DScong[i]->GetLoai() == 2)
        {
            if (sotritue < DScong[i]->TraVe())
            {
                cout <<"\nHoang tu da that bai o cong thu "<<i + 1;
                return 0;
            }
        }
        else if (DScong[i]->GetLoai() == 3)
        {
            if (sosucmanh >= DScong[i]->TraVe())
            {
                sosucmanh -= DScong[i]->TraVe();
            }
            else
            {
                cout <<"\nHoang tu da that bai o cong thu "<<i + 1;
                return 0;
            }
        }
        i++;
    }
    cout <<"\n\tHoang tu da cuu duoc cong chua";
    cout << "\nTien: "<<tien <<endl<< "\nChi so tri tue: " <<sotritue<<endl<<"\nChi so suc manh: "<<sosucmanh;
    system ("pause");
    system ("cls");
    return 0;
}