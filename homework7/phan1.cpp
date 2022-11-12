#include <iostream>
using namespace std;

class Time {
    int gio,phut,giay;
    public:
        Time operator+ (Time x) 
        {
            Time kq;
            kq.gio = gio + x.gio;
            kq.phut = phut + x.phut;
            kq.giay = giay + x.giay;
            return kq;
        }
        Time operator+ (int x) 
        {
            Time kq;
            kq.gio = gio;
            kq.phut = phut;
            kq.giay = giay + x;
            return kq;
        }
        Time operator- (Time x) 
        {
            Time kq;
            kq.gio = gio - x.gio;
            kq.phut = phut - x.phut;
            kq.giay = giay - x.giay;
            return kq;
        }
        Time operator- (int x) 
        {
            Time kq;
            kq.gio = gio;
            kq.phut = phut;
            kq.giay = giay - x;
            return kq;
        }
        bool operator> (Time x) 
        {
            if (gio > x.gio) 
            {
                return true;
            }
            else if (gio == x.gio) 
            {
                if (phut > x.phut)
                {
                    return true;
                }
                else if (phut == x.phut)
                {
                    if (giay > x.giay) 
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        Time& operator+= (Time x) 
        {
            *this = *this + x;
            return *this;
        }
        friend istream& operator>> (istream &is, Time &x)
        {
            cout <<"\nNhap gio: ";
            is>>x.gio;
            do 
            {
                cout <<"\nNhap phut: ";
                is>>x.phut;
                if (x.phut<0||x.phut>=60) 
                {
                    cout <<"\nGia tri khong hop le, hay nhap lai!";
                }
            } while (x.phut<0||x.phut>=60);
            do 
            {
                cout <<"\nNhap giay: ";
                is>>x.giay;
                if (x.giay<0||x.giay>=60) 
                {
                    cout <<"\nGia tri khong hop le, hay nhap lai!";
                }
            } while (x.giay<0||x.giay>=60);
            return is;
        }
        friend ostream& operator<< (ostream &os, Time x)
        {
            os<<x.gio<<":"<<x.phut<<":"<<x.giay;
            return os;
        }
        bool operator== (Time x)
        {
            if (gio == x.gio && phut == x.phut && giay == x.giay) 
            {
                return true;
            }
            return false;
        }
        bool operator!= (Time x)
        {
            if (gio == x.gio && phut == x.phut && giay == x.giay) 
            {
                return false;
            }
            return true;
        }
        bool operator>= (Time x)
        {
            if (*this > x || *this == x)
            {
                return true;
            }
            return false;
        }
        Time& operator++ ()
        {
            *this = *this + 1;
            return *this;
        }
        Time& operator-- ()
        {
            *this = *this - 1;
            return *this;
        }
        Time operator++ (int)
        {
            Time temp = *this;
            *this = *this + 1;
            return temp;
        }
};

int main () {
    Time a,b;
    cin >> a;
    cin >> b;
    a+b;
    a+1;
    a-b;
    if (a>b) {
        cout <<"\nTrue\n";
    } else {
        cout <<"\nFalse\n";
    }
    a+=b;
    cout <<a<<endl<<b;
    if (a==b) {
        cout <<"\nTrue";
    } else {
        cout <<"\nFalse";
    }
    if (a!=b) {
        cout <<"\nTrue";
    } else {
        cout <<"\nFalse";
    }
    if (a>=b) {
        cout <<"\nTrue";
    } else {
        cout <<"\nFalse";
    }
    a++;
    ++a;
    b++;
    ++b;
    --a;
    --b;
    system("pause");
    system("cls");
    return 0;
}