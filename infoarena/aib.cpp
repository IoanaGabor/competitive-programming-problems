
///am uitat sa modific sirul initial
#include <iostream>
#include <fstream>
#define NMAX 100000

using namespace std;

ifstream f("aib.in");
ofstream g("aib.out");

int n,q,AIB[NMAX+5],sir[NMAX+5],a,b,cerinta;

void adauga(int val,int poz){
    while(poz<=n){
        AIB[poz]+=val;
        poz+=(poz^((poz-1)&poz));
    }
}

int suma(int poz){
    int suma=0;
    while(poz>0){
        suma+=AIB[poz];
        poz-=(poz^((poz-1)&poz));
    }
    return suma;
}

int cauta(int val){
    int pas=(1<<16);
    int rez=0,suma=0;
    while(pas){
        if(rez+pas<=n&&suma+AIB[rez+pas]<val){
            rez+=pas;
            suma+=AIB[rez];
        }
        pas>>=1;
    }
    rez++;
    suma+=sir[rez];
    if(suma==val&&rez<=n){
        return rez;
    }else{
        return -1;
    }
}

int main(){
    f>>n>>q;
    for(int i=1;i<=n;i++){
        f>>sir[i];
        adauga(sir[i],i);
    }
    while(q--){
        f>>cerinta>>a;
        if(cerinta!=2){
            f>>b;
        }
        if(cerinta==0){
            adauga(b,a);
            sir[a]+=b;
        }else if(cerinta==1){
            g<<suma(b)-suma(a-1)<<'\n';
        }else{
            g<<cauta(a)<<'\n';
        }
    }
    f.close();
    g.close();
}
