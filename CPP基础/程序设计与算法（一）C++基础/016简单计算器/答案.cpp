#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,y;
    char c;
    cin >> x >> y >> c;
    switch (c)
    {
        case '+': cout << x+y << endl;break;
        case '-': cout << x-y << endl;break;
        case '*': cout << x*y << endl;break;
        case '/': if (y) cout << x/y << endl;
                  else  cout << "Divided by zero!" << endl;
                  break;
        default: cout << "Invalid operator!" << endl;
    }
    return 0;
}