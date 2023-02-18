
#include <iostream>
#include <fstream>
#define n_max 1000005
using namespace std;

ifstream f("cufar.in");
ofstream g("cufar.out");

bool ciur[n_max];
int n_divizori[n_max],intrebari[n_max];
long long suma;

void rezolva(){
    for(int i=2;i<=n_max;i++){
        if(ciur[i]==false){
            for(int j=i;j<=n_max;j=j+i){
                ciur[j]=true;
                n_divizori[j]++;
                if(n_divizori[j]==intrebari[j]){
                    cout<<i<<'\n';
                    suma=suma+i;
                }
            }
        }
    }
}

int main() {
    long long p,n;
    f>>p>>n;
    int cartonas,k;
    for(int i=1;i<=n;i++) {
        f>>cartonas>>k;
        intrebari[cartonas]=k;
    }
    rezolva();
    g<<suma<<'\n';
    f.close();
    g.close();
}
