
#include <bits/stdc++.h>
#define NMAX 500000
#define MOD 543217

using namespace std;

ifstream fi("urat.in");
ofstream fo("urat.out");

int n;
int fact[NMAX+5];
int sir[NMAX+5];

int main(){
    fi>>n;
    fact[0]=1;
    for(int i=1;i<=n/2;i++){
        fact[i]=(1LL*fact[i-1]*i)%MOD;
    }
    fo<<(1LL*n*n)/2-1<<'\n';
    sir[1]=n/2;
    sir[n]=n/2+1;
    for(int i=2;i<n;i++){
        if(i%2==0){
            sir[i]=n/2+1+i/2;
        }else{
            sir[i]=i/2;
        }
    }
    if(n%2==0){
        fo<<(2LL*fact[n/2-1]*fact[n/2-1])%MOD<<'\n';
    }else{
        fo<<(4LL*fact[n/2]*fact[n/2-1])%MOD<<'\n';
    }
    for(int i=1;i<=n;i++){
        fo<<sir[i]<<' ';
    }
    fi.close();
    fo.close();
}