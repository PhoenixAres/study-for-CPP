#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ch=getchar();
    while (ch!=EOF)
    {
        if ((ch>='a' && ch<='y') || (ch>='A' && ch<='Y')) putchar(ch+1);
        else if (ch=='z') putchar('a');
        else if (ch=='Z') putchar('A');
        else putchar(ch);
        ch=getchar();
    }

    return 0;
}