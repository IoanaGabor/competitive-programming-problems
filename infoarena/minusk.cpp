
#include <iostream>
#include <fstream>
#define NMAX 1000000
#define MOD 2011

using namespace std;

ifstream f("minusk.in");
ofstream g("minusk.out");

int unu[NMAX+3],zero[NMAX+3],n,k,suma;

int main(){
    f>>n>>k;
    if(k==1){
        g<<1<<'\n';
    }else{
        unu[0]=zero[0]=unu[1]=zero[1]=1;
        suma=2;
        for(int i=2;i<=n;i++){
            unu[i]=(unu[i-1]+zero[i-1])%MOD;
            suma+=MOD;
            if(i>=k){
                suma-=unu[i-k];
            }
            suma%=MOD;
            zero[i]=suma;
            suma+=unu[i]+MOD;
            suma%=MOD;
        }
        g<<(unu[n]+zero[n])%MOD;
    }
    f.close();
    g.close();
}
