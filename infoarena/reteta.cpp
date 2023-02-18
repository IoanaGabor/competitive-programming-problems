#include <iostream>
#include <fstream>
#define NMAX 20
#define MMAX 15
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("reteta.in");
ofstream g("reteta.out");

int n,m,r[MMAX+5],pretm[NMAX+5],pretr[MMAX+5],x,tip[MMAX+5],nr,gen_submultimi,aux,ok,suma,rez=MAXVAL;

int main()
{
    f>>n>>m;
    for(int i=1;i<=m;i++){
        f>>tip[i]>>nr;
        for(int j=1;j<=nr;j++){
            f>>x;
            r[i]+=(1<<(x-1));
        }
    }
    for(int i=1;i<=n;i++){
        f>>pretm[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(r[i]&(1<<(j-1))){
                if(tip[i]==1){
                    pretr[i]+=2*pretm[j];
                }else{
                    pretr[i]+=pretm[j];
                }
            }
        }
    }
    for(gen_submultimi=0;gen_submultimi<(1<<m);gen_submultimi++){
        aux=0;
        ok=1;
        suma=0;
        for(int i=1;i<=m&&ok;i++){
            if(gen_submultimi&(1<<(i-1))){
                if(aux&r[i]){
                    ok=0;
                }else{
                    aux=aux|r[i];
                    suma+=pretr[i];
                }
            }
        }
        if(aux==((1<<n)-1)&&ok){
            if(suma<rez){
                rez=suma;
            }
        }
    }
    g<<rez/2;
    if(rez%2==1){
        g<<".5";
    }else{
        g<<".0";
    }
    f.close();
    g.close();
}
