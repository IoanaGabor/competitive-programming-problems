#include <iostream>
#include <fstream>
#define MOD 666013

using namespace std;

ifstream f("unuzero.in");
ofstream g("unuzero.out");

int n,p,q,zero[1000010],unu[1000010],suma[1000010];

int main()
{
    f>>n>>p>>q;
    zero[0]=1;
    suma[0]=1;
    for(int i=1;i<=n;i++){
        zero[i]=(zero[i-1]+unu[i-1])%MOD;
        suma[i]=(suma[i-1]+zero[i])%MOD;
        if(i-p>=0){
            unu[i]=suma[i-p];
            if(i-q-1>=0){
                unu[i]-=suma[i-q-1];
            }
        }
        if(unu[i]<0){
            unu[i]+=MOD;
        }
        unu[i]=unu[i]%MOD;
    }
    g<<(zero[n]+unu[n]-1)%MOD;
    f.close();
    g.close();
    return 0;
}
