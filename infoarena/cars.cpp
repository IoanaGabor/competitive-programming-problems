
#include <iostream>
#include <fstream>
#include <iomanip>
#define eroare 0.0000001
using namespace std;

ifstream f("cars.in");
ofstream g("cars.out");

int n,m,a,b,k,l[101],r[101],L,rapide[20001],lente[20001];

double afla_t_masina_rapida(int poz){
    double rez=0;
    int pas,j;
    for(int i=1;i<=k;i++){
        if(poz<r[i]){
            if(poz<l[i]){
                rez+=(double)(l[i]-poz)/a;
                poz=l[i];
            }
            pas=1<<15;
            j=0;
            while(pas){
                if(j+pas<=m&&lente[j+pas]+b*rez<poz+eroare){
                    j+=pas;
                }
                pas>>=1;
            }
            j++;
            if(j<=m&&rez+(double)(r[i]-poz)/a<(double)(r[i]-lente[j])/b){
                rez=(double)(r[i]-lente[j])/b;
            }else{
                rez+=(double)(r[i]-poz)/a;
            }
            poz=r[i];
        }
    }
    rez+=(double)(L-poz)/a;
    return rez;
}

int main(){
    f>>n>>m>>k>>L>>a>>b;
    for(int i=1;i<=n;i++){
        f>>rapide[i];
    }
    for(int i=1;i<=m;i++){
        f>>lente[i];
    }
    for(int i=1;i<=k;i++){
        f>>l[i]>>r[i];
    }
    for(int i=1;i<=n;i++){
        g<<fixed<<setprecision(6)<<afla_t_masina_rapida(rapide[i])<<'\n';
    }
    for(int i=1;i<=m;i++){
        g<<fixed<<setprecision(6)<<(double)(L-lente[i])/b<<'\n';
    }
    f.close();
    g.close();
}
