
#include <iostream>
#include <fstream>
#include <map>
#define NMAX 1000
#define LNUMAR 2600

using namespace std;

ifstream f("perm3.in");
ofstream g("perm3.out");

int n,x,p[NMAX+5],aux[LNUMAR+5],AIB[NMAX+5];
int fact[NMAX+5][LNUMAR+5],rez[LNUMAR+5];
map<int,int> m;

void atribuire(int a[LNUMAR+5],int b[LNUMAR+5]){
    for(int i=1;i<=b[0];i++){
        a[i]=b[i];
    }
    a[0]=b[0];
}

void afisare(int numar[LNUMAR+5]){
    for(int i=numar[0];i>=1;i--){
        g<<numar[i];
    }
    g<<'\n';
}

void inmultire(int rezultat[LNUMAR+5],int numar[LNUMAR+5],int nr){
    atribuire(rezultat,numar);
    int t=0;
    for(int i=1;i<=rezultat[0];i++){
        rezultat[i]=rezultat[i]*nr+t;
        t=rezultat[i]/10;
        rezultat[i]%=10;
    }
    while(t){
        rezultat[++rezultat[0]]=t%10;
        t/=10;
    }
}

void aduna_la_rez(int rezultat[LNUMAR+5],int numar[LNUMAR+5],int nr){
    inmultire(aux,numar,nr);
    if(rezultat[0]<aux[0]){
        for(int i=rezultat[0]+1;i<=aux[0];i++){
            rezultat[i]=0;
        }
        rezultat[0]=aux[0];
    }else{
        for(int i=aux[0]+1;i<=rezultat[0];i++){
            aux[i]=0;
        }
        aux[0]=rezultat[0];
    }
    int t=0;
    for(int i=1;i<=rezultat[0];i++){
        rezultat[i]=rezultat[i]+aux[i]+t;
        t=rezultat[i]/10;
        rezultat[i]%=10;
    }
    while(t){
        rezultat[++rezultat[0]]=t%10;
        t/=10;
    }
}

void aduna1(){
    int t=0;
    rez[1]++;
    t=rez[1]/10;
    rez[1]%=10;
    for(int i=2;i<=rez[0];i++){
        rez[i]=rez[i]+t;
        t=rez[i]/10;
        rez[i]%=10;
    }
    while(t){
        rez[++rez[0]]=t%10;
        t/=10;
    }
}

void adauga(int x){
    while(x<=n){
        AIB[x]++;
        x+=(x^(x&(x-1)));
    }
}

int nrvalmaimici(int x){
    int suma=0;
    while(x>0){
        suma+=AIB[x];
        x-=(x^(x&(x-1)));
    }
    return suma;
}

int main(){
    f>>n;
    fact[0][0]=fact[0][1]=1;
    for(int i=1;i<=n;i++){
        f>>x;
        m[x]=i;
        inmultire(fact[i],fact[i-1],i);
    }
    for(int i=1;i<=n;i++){
        f>>p[i];
        p[i]=m[p[i]];
    }
    rez[0]=1;
    rez[1]=0;
    for(int i=1;i<=n;i++){
        aduna_la_rez(rez,fact[n-i],p[i]-1-nrvalmaimici(p[i]));
        adauga(p[i]);
    }
    aduna1();
    afisare(rez);
    f.close();
    g.close();
}
