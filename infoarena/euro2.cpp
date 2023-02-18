
#include <iostream>
#include <fstream>
#include <algorithm>
#define NMAX 10000

using namespace std;

ifstream f("euro2.in");
ofstream g("euro2.out");

int n,lg1[NMAX+5],lg2[NMAX+5],laux,rez;
double sir[NMAX+5],aux[NMAX+5];

int cauta_poz(double val){
    int i=0,pas=1<<14;
    while(pas){
        if(i+pas<=laux&&aux[i+pas]<val){
            i+=pas;
        }
        pas>>=1;
    }
    i++;
    return i;
}

void cmlsc(int lg[]){
    aux[1]=sir[1];
    lg[1]=1;
    laux=1;
    int poz;
    for(int i=2;i<=n;i++){
        if(sir[i]>aux[laux]){
            aux[++laux]=sir[i];
            lg[i]=laux;
        }else{
            poz=cauta_poz(sir[i]);
            aux[poz]=sir[i];
            lg[i]=poz;
        }
    }
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    cmlsc(lg1);
    reverse(sir+1,sir+n+1);
    cmlsc(lg2);
    rez=0;
    for(int i=1;i<=n;i++){
        if(lg1[i]>=2&&lg2[n-i+1]>=2&&lg1[i]+lg2[n-i+1]-1>rez){
            rez=lg1[i]+lg2[n-i+1]-1;
        }
    }
    g<<rez;
    f.close();
    g.close();
}
