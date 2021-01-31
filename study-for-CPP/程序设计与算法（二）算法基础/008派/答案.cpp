#include <bits/stdc++.h>
using namespace std;

int a,n,f;
double l,r,mid,arr[10005];
int check(double x){
    int ans = 0;
    for(int i = 0;i < n;i++)
        ans += arr[i] / x;
    if(ans >= f + 1)//算上自己的那一份一共是f + 1个
        return 0;
    return 1;
}

int main(){
    scanf("%d%d",&n,&f);
    for(int i = 0;i < n;i++){
        scanf("%d",&a);
        //pi使用acos(-1.0)计算,否则容易产生误差或使用3.14159265354计算,否则精度达不到
        arr[i] = a * a * acos(-1.0);
    }
    sort(arr,arr + n);
    l = 1,r = arr[n - 1];
    while(r - l > 1e-7){//由于r和l都是double类型,无限接近使用 r - l < 1e-7表示
        mid = l + (r - l) / 2;
        if(check(mid) == 1)//超过了
            r = mid;
        else
            l = mid;
    }
    printf("%.3lf\n",r);
    return 0;
}