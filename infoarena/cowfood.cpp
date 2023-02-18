
#include <bits/stdc++.h>
#define NMAX 20
#define KMAX 30
#define VALMAX 10030
#define MOD 3210121

using namespace std;

ifstream f("cowfood.in");
ofstream g("cowfood.out");

int k,s,n;
int am[NMAX+5][KMAX+5],aux[KMAX+5],sub[NMAX+5];
long long fact[VALMAX+5],invfact[VALMAX+5],cmb[VALMAX+5],sumacmb[VALMAX+5],tot,nr;

long long putere(long long x,int e){
    long long ret=1;
    while(e){
        if(e%2==0){
            x=(1LL*x*x)%MOD;
            e/=2;
        }else{
            ret=(1LL*ret*x)%MOD;
            e--;
        }
    }
    return ret;
}

void bkt(int kk,int nrel){
    if(kk==nrel+1){
        int suma=0;
        for(int i=1;i<=k;i++){
            suma+=aux[i];
        }
        if(s>=suma){
            if(nrel%2==0){
                tot=(tot+sumacmb[s-suma])%MOD;
            }else{
                tot=(tot-sumacmb[s-suma]+MOD)%MOD;
            }
        }
    }else{
        int copie[KMAX+5];
        for(int i=sub[kk-1]+1;i<=n-nrel+kk;i++){
            for(int j=1;j<=k;j++){
                copie[j]=aux[j];
                aux[j]=max(aux[j],am[i][j]);
            }
            sub[kk]=i;
            bkt(kk+1,nrel);
            sub[kk]=0;
            for(int j=1;j<=k;j++){
                aux[j]=copie[j];
            }
        }
    }
}

int main(){
    fact[0]=invfact[0]=1;
    for(int i=1;i<=VALMAX;i++){
        fact[i]=(1LL*fact[i-1]*i)%MOD;
        invfact[i]=putere(fact[i],MOD-2);
    }
    f>>k>>s>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            f>>am[i][j];
        }
    }
    for(int i=0;i<=VALMAX-k+1;i++){
        cmb[i]=(((1LL*fact[i+k-1]*invfact[k-1])%MOD*invfact[i])%MOD)%MOD;
        if(i){
            sumacmb[i]=(cmb[i]+sumacmb[i-1])%MOD;
        }else{
            sumacmb[i]=cmb[i];
        }
    }
    tot=(sumacmb[s]-sumacmb[1]-(k*(s-1))%MOD+2*MOD)%MOD;
    for(int i=1;i<=n;i++){
        bkt(1,i);
    }
    g<<tot;
}
