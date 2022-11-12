#include <iostream>
using namespace std;

class List {
    double* a;
    static unsigned int size;
    public:
        void KhoiTaoListRong();
        void ThemXVaoList (double x);
        void XoaPhanTuDauTienCoGiaTriX (double x);
        void XoaTatCaPhanTuCoGiaTriX (double x);
        void ThayDoiXBangY (int x, double y);
        void XuatList();
        void Menu();
};

unsigned int List::size=0;

int main () {
    List b;
    b.KhoiTaoListRong();
    b.Menu();
    system("pause");
    system("cls");
    return 0;
}

void List::KhoiTaoListRong() {
    a=new double [size];
}

void List::ThemXVaoList(double x) {
    double b[size];
    if (size>0) {
        for (int i=0; i<size; i++) {
            b[i]=a[i];
        }
        delete []a;
        size++;
        a=new double[size];
        for (int i=0; i<size; i++) {
            a[i]=b[i];
        }
        a[size-1]=x;
    } else {
        a[size]=x;
        size++;
    }
}

void List::XoaPhanTuDauTienCoGiaTriX(double x) {
    if (size>0) {
        if (size==1) {
            if (a[0]==x) {
                delete []a;
                size--;
            }
        } else {
            int i;
            int dem=0;
            for (i=0; i<size; i++) {
                if (a[i]==x) {
                    dem++;
                    break;
                }
            }
            if (dem!=0) {
                for (int j=i; j<size; j++) {
                    a[j]=a[j+1];
                }
                size--;
                return;
            }
            if (a[size-1]==x) {
                double b[--size];
                for (int j=0; j<size; j++) {
                    b[j]=a[j];
                }
                delete []a;
                a=new double[size];
                for (int k=0; k<size; k++) {
                    a[k]=b[k];
                }
            }
        }
    }
}

void List::XoaTatCaPhanTuCoGiaTriX(double x) {
    if (size>0) {
        if (size==1) {
            if (a[0]==x) {
                delete []a;
                size--;
            }
        } else {
            int i;
            int q[size];
            int f=0;
            for (i=0; i<size-1; i++) {
                if (a[i]==x) {
                    q[f]=i;
                    f++;
                }
            }
            for (int l=0; l<f; l++) {
                for (int j=q[l]; j<size; j++) {
                    a[j]=a[j+1];
                }
                size--;
            }
            if (a[size-1]==x) {
                double b[--size];
                for (int j=0; j<size; j++) {
                    b[j]=a[j];
                }
                delete []a;
                a=new double[size];
                for (int k=0; k<size; k++) {
                    a[k]=b[k];
                }
            }
        }
    }
}

void List::ThayDoiXBangY(int x, double y) {
    for (int i=0; i<size; i++) {
        if (i==x) {
            a[i]=y;
        }
    }
}

void List::Menu () {
    while (true) {
        int n;
        cin>>n;
        if (n==-1) {
            XuatList();
            break;
        } else if (n==0) {
            double x;
            cin>>x;
            ThemXVaoList(x);
        } else if (n==1) {
            double x;
            cin>>x;
            XoaPhanTuDauTienCoGiaTriX(x);
        } else if (n==2) {
            double x;
            cin >>x;
            XoaTatCaPhanTuCoGiaTriX(x);
        } else if (n==3) {
            int x;
            double y;
            cin>>x>>y;
            ThayDoiXBangY(x,y);
        }
    }
}

void List::XuatList() {
    cout <<"[";
    for (int i=0; i<size; i++) {
        if (i==size-1) {
            cout <<a[i];
        } else {
            cout <<a[i]<<",";
        }
    }
    cout <<"]";
}