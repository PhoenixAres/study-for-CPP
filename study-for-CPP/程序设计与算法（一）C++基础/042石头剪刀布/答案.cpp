#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char a[10],b[10];
        cin >> a >> b;
        if (a[0]==b[0])
        {
            cout << "Tie" << endl;
            continue;
        }
        switch (a[0])
        {
            case 'R': if (b[0]=='S') cout << "Player1" << endl;
                      else cout << "Player2" << endl;
                      break;
            case 'S': if (b[0]=='P') cout << "Player1" << endl;
                      else cout << "Player2" << endl;
                      break;
            case 'P': if (b[0]=='R') cout << "Player1" << endl;
                      else cout << "Player2" << endl;
                      break;
        }
    }
    return 0;
}