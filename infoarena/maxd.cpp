
#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

ifstream f("maxd.in");
ofstream g("maxd.out");

int nr_div(int n){
    int rez=1,putere=0;
    int i=2;
    while(n%i==0){
            putere++;
            n=n/i;
    }
    rez*=(putere+1);
    i++;
    while(n!=1&&i*i<=n){
        putere=0;
        while(n%i==0){
            putere++;
            n=n/i;
        }
        rez*=(putere+1);
        i+=2;
    }
    if(n!=1){
        rez*=2;
    }
    return rez;
}

int main(){
    int a,b,minim,nrdivmin=-1,contor=0,nrdiv;
    f>>a>>b;
    for(int nr=a;nr<=b;nr++){
        nrdiv=nr_div(nr);
        if(nrdiv>nrdivmin){
            nrdivmin=nrdiv;
            minim=nr;
            contor=1;
        }else if(nrdiv==nrdivmin){
            contor++;
        }
    }
    g<<minim<<' '<<nrdivmin<<' '<<contor;
    f.close();
    g.close();
}
