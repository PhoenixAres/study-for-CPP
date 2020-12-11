#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    cin >> s;
    sort(s.begin(), s.end());
    cout << s << endl;
    while (next_permutation(s.begin(), s.end())) cout << s << endl;
    return 0;
}