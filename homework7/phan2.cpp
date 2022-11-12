#include <iostream>
using namespace std;

class Stack {
    int arrSo [50]={1,2,3,4,5};
    int iN;
    public:
        int operator[] (int x) 
        {
            return arrSo[x];
        }
        void push (int &x) 
        {
            Stack a;
            int b;
            cout <<"\nNhap vi tri: ";
            cin >>b;
            x = a[b];
        }
};

int main () {
    Stack a;
    cout << a[0];
    int x;
    a.push (x);
    cout <<x;
    system("pause");
    system("cls");
    return 0;
}