#include <bits/stdc++.h>

using namespace std;

int phi[100002];

int main()
{
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
    for (int i=2;i<=100000;i++)
    {
        phi[i]=i-1;
    }
    for (int i=2;i<=50000;i++)
    {
        for (int j=i*2;j<=100000;j+=i)
        {
            phi[j]-=phi[i];
        }
    }
    int t;
    scanf("%d", &t);
    for (int k=1;k<=t;++k)
    {
        int nr;
        scanf("%d", &nr);
        printf("%lld\n", 1LL*2*nr*phi[nr]);
    }
}
