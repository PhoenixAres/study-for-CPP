#include <iostream>
using namespace std;
class B { 
	private: 
		int nBVal; 
	public: 
		void Print() 
		{ cout << "nBVal="<< nBVal << endl; } 
		void Fun() 
		{cout << "B::Fun" << endl; } 
		B ( int n ) { nBVal = n;} 
};
class D:public B
{
    int nDVal;
public:
    D(int n):B(n*3), nDVal(n){}
    void Print()
    {
        B::Print();
        cout << "nDVal="<< nDVal << endl;
    }
    void Fun()
    {
        cout << "D::Fun" << endl;
    }
};

int main() { 
	B * pb; D * pd; 
	D d(4); d.Fun(); 
	pb = new B(2); pd = new D(8); 
	pb -> Fun(); pd->Fun(); 
	pb->Print (); pd->Print (); 
	pb = & d; pb->Fun(); 
	pb->Print(); 
	return 0;
}