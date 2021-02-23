#include <bits/stdc++.h>
using namespace std;

struct Score
{
    string name;
    int grade;
};

struct Rule
{
    bool operator()(const Score & a1,const Score & a2)
    {
        if (a1.grade==a2.grade) return a1.name<a2.name;
        else return a1.grade>a2.grade;
    }
};

int main()
{
	int n;
	cin >> n;
	Score a[n];
	for (int i=0;i<n;i++) cin >> a[i].name >> a[i].grade;
	sort(a,a+n,Rule());
	for (int i=0;i<n;i++) cout << a[i].name << " " << a[i].grade << endl;
	return 0;
}