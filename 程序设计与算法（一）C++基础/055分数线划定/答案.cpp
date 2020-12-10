#include <bits/stdc++.h>
using namespace std;

struct Score
{
    int num;
    int grade;
};

struct Rule
{
    bool operator()(const Score & a1,const Score & a2)
    {
        if (a1.grade==a2.grade) return a1.num<a2.num;
        else return a1.grade>a2.grade;
    }
};

int main()
{
	int n,m;
	cin >> n >> m;
	Score a[n];
	for (int i=0;i<n;i++) cin >> a[i].num >> a[i].grade;
	sort(a,a+n,Rule());
	int t=floor(m*1.5);
	int i;
	for (i=t;i<n && a[i].grade==a[t-1].grade;i++);
	cout << a[t-1].grade << " " << i << endl;
	for (int j=0;j<i;j++)
        cout << a[j].num << " " << a[j].grade << endl;
	return 0;
}