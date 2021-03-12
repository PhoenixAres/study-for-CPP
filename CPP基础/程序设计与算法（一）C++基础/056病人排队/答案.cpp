#include <bits/stdc++.h>
using namespace std;

struct Score
{
    string ID;
    int old;
    int x;
};

struct Rule
{
    bool operator()(const Score & a1,const Score & a2)
    {
        if (a1.old>=60 && a2.old>=60)
        {
            if (a1.old==a2.old) return a1.x < a2.x;
            else return a1.old > a2.old;
        }
        else if (a1.old >= 60 && a2.old < 60) return true;
        else if (a1.old < 60 && a2.old >= 60) return false;
        else return a1.x < a2.x;
    }
};

int main()
{
	int n;
	cin >> n;
	Score a[n];
	for (int i = 0;i < n;i++)
    {
        cin >> a[i].ID >> a[i].old;
        a[i].x=i;
    }
	sort(a,a+n,Rule());
	for (int i = 0;i < n;i++)
        cout << a[i].ID << endl;
	return 0;
}