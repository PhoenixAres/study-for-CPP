#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
int m, n;
    int *a;
public:
    Array2(int i, int j):m(i), n(j)
    {
        a = new int[m*n];
    }
    Array2()
    {
        a = NULL;
    }
    ~Array2()
    {
        if (a) delete [] a;
    }
    Array2 & operator = (const Array2 & p)
    {
        if (a) delete [] a;
        if (p.a)
        {
            m = p.m;
            n = p.n;
            a = new int[m*n];
            memcpy(a, p.a, sizeof(int)*m*n);
        }
        else a = NULL;
        return *this;
    }
    int * operator [] (int i)
    {
        return a+n*i;
    }
    int operator () (int i, int j)
    {
        return a[n*i+j];
    }
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}