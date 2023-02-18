
#include <iostream>
#include <fstream>
#define NMAX 2000
#define MAXVAL 1<<30

using namespace std;

ifstream f("gaz.in");
ofstream g("gaz.out");

long long l,p,d,c,n,suma,dep,G[NMAX+5],rez[NMAX+5],sumatot;

long long maxim(long long a,long long b){
    if(a<b){
        return b;
    }
    return a;
}

int main(){
    f>>l>>p>>d>>c;
    f>>n;
    for(int i=1;i<=n;i++){
        f>>G[i];
        sumatot+=G[i];
    }
    for(int i=1;i<=n;i++){
        suma=G[i];
        dep=0;
        rez[i]=MAXVAL;
        for(int j=i-1;j>=0;j--){
            rez[i]=min(rez[i],rez[j]+dep*c+p);
            suma+=G[j];
            dep=maxim(0,suma-G[j]-l);
        }
    }
    g<<rez[n]+sumatot*d;
    f.close();
    g.close();
}
