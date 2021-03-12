#include <bits/stdc++.h>
using namespace std;

char s[30000];
char word[300][200];

int main()
{
    fgets(s,30000,stdin);
    char *p=s;
    int i=0;
    while (*p)
    {
        if (isalpha(*p))
        {
            char *q=p+1;
            while (*q!=' ' && *q!=',' && *q!='\n') q++;
            *q='\0';
            strcpy(word[i++],p);
            p=q+1;
        }
        else p++;
    }
    int a[i]={0};
    int maxid=0,minid=0;
    for (int j=0;j<i;j++)
        a[j]=strlen(word[j]);
    for (int j=1;j<i;j++)
    {
        if (a[j]>a[maxid]) maxid=j;
        if (a[j]<a[minid]) minid=j;
    }
    cout << word[maxid] << endl;
    cout << word[minid] << endl;

    return 0;
}