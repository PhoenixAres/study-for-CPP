#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int wn,qn,zn,ln;
    wn=qn=zn=ln=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if (x>=0 && x<=18) wn++;
        else if (x>=19 && x<=35) qn++;
        else if (x>=36 && x<=60) zn++;
        else ln++;
    }
    printf("%.2f%%\n",wn*1.0/n*100);
    printf("%.2f%%\n",qn*1.0/n*100);
    printf("%.2f%%\n",zn*1.0/n*100);
    printf("%.2f%%\n",ln*1.0/n*100);
    return 0;
}