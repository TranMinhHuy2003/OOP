#include <iostream>
using namespace std;
class A {
   public:
	A ( )
	  {  cout<< "A:default"<<endl; }
	A (int a){
	   cout<<"A:parameter"<<endl;
	}
};
class C : public A 
{
   public: 
	C (int a) : A(a){
	     cout<<"C"<<endl;
	}
};

int main ()
{
    C test (1);
    system ("pause");
    system ("cls");
    return 0;
}