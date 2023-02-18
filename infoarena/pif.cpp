
#include <iostream>
#include <fstream>
#define NMAX 1000000
#define MOD 1234567

using namespace std;

ifstream f("pif.in");
ofstream g("pif.out");

int n,k,zv,zt,v[NMAX+5],t[NMAX+5],sumav[NMAX+5],sumat[NMAX+5],nr1,nr2;
long long rez;
int main(){
    f>>n>>k>>zv>>zt;
    t[1]=1;
    sumat[1]=1;
    v[1]=0;
    rez+=k;
    nr1=nr2=k/2;
    nr1+=k%2;
    for(int i=2;i<=n+1;i++){
        if(zt<zv){
            t[i]=(sumat[max(i-zt,0)]-sumat[max(i-zt*(nr1+1),0)]+sumav[max(i-zv,0)]-sumav[max(i-zv*(nr1+1),0)]+2*MOD)%MOD;
            v[i]=(sumav[max(i-zv*(nr1+1),0)]-sumav[max(i-zv*(nr1+nr2+1),0)]+sumat[max(i-zt*(nr1+1),0)]-sumat[max(i-zt*(nr1+nr2+1),0)]+2*MOD)%MOD;
        }else{
            t[i]=(sumat[max(i-zt*(nr1+1),0)]-sumat[max(i-zt*(nr1+nr2+1),0)]+sumav[max(i-zv*(nr1+1),0)]-sumav[max(i-zv*(nr1+nr2+1),0)]+2*MOD)%MOD;
            v[i]=(sumav[max(i-zv,0)]-sumav[max(i-zv*(nr1+1),0)]+sumat[max(i-zt,0)]-sumat[max(i-zt*(nr1+1),0)]+2*MOD)%MOD;
        }
        sumat[i]=(t[i]+sumat[max(i-zt,0)])%MOD;
        sumav[i]=(v[i]+sumav[max(i-zv,0)])%MOD;
        rez=(rez+1LL*(k-1)*(t[i]+v[i]))%MOD;
    }
    g<<rez;
    f.close();
    g.close();
}
