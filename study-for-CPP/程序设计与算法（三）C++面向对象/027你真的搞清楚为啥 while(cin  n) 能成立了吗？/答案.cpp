#include <iostream>
using namespace std;
class MyCin
{
    bool flag;
public:
    MyCin(){flag = true;}
    MyCin & operator >> (int & i)
    {
        cin >> i;
        if (i == -1) flag = false;
        return *this;
    }
    operator bool ()
    {
        if (!flag) return false;
        return true;
    }
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    return 0;
}