
#include <iostream>
#include <fstream>
#define NMAX 15000

using namespace std;

ifstream f("datorii.in");
ofstream g("datorii.out");

int n,m,op,aib[NMAX+5],t,v,p,q,el;

void modifica(){
    while(t<=n){
        aib[t]-=v;
        t+=(t&(-t));
    }
}

int afla_suma(int x){
    int suma=0;
    while(x){
        suma+=aib[x];
        x=x&(x-1);
    }
    return suma;
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        f>>el;
        t=i;
        v=-el;
        modifica();
    }
    while(m--){
        f>>op;
        if(op==0){
            f>>t>>v;
            modifica();
        }else{
            f>>p>>q;
            g<<afla_suma(q)-afla_suma(p-1)<<'\n';
        }
    }
    f.close();
    g.close();
}
