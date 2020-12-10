#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a,b,c;
    cin >> a >> b >> c;
    if (fabs(b*b-4*a*c)<=1e-8)
    {
        if (fabs((-b)/(2*a))<=1e-8) printf("x1=x2=%.5f\n",b/(2*a));
        else printf("x1=x2=%.5f\n",(-b)/(2*a));
    }
    else if (b*b-4*a*c>1e-8)
    {
        printf("x1=%.5f;x2=%.5f\n",(-b + sqrt(b*b-4*a*c))/(2*a),(-b - sqrt(b*b-4*a*c))/(2*a));
    }
    else
    {
        if (fabs(-b / (2*a))<=1e-8) printf("x1=%.5f+%.5fi;x2=%.5f-%.5fi\n",b / (2*a),sqrt(4*a*c-b*b) / (2*a),b / (2*a),sqrt(4*a*c-b*b) / (2*a));
        else printf("x1=%.5f+%.5fi;x2=%.5f-%.5fi\n",-b / (2*a),sqrt(4*a*c-b*b) / (2*a),-b / (2*a),sqrt(4*a*c-b*b) / (2*a));
    }
    return 0;
}