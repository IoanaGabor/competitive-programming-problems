
#include <iostream>
#include <fstream>
#include <algorithm>
#define NMAX 200001

using namespace std;

ifstream f("aranjare2.in");
ofstream g("aranjare2.out");

int n;

int sticle[NMAX],poz_sticle[NMAX];

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        sticle[i]=(i-1)*2+1;
        sticle[n+i]=2*i;
        poz_sticle[(i-1)*2+1]=i;
        poz_sticle[2*i]=n+i;
    }
    for(int i=1;i<=2*n;i++){
        if(sticle[i]!=i){
            g<<i<<' '<<poz_sticle[i]<<'\n';
            swap(poz_sticle[i],poz_sticle[sticle[i]]);
            swap(sticle[i],sticle[poz_sticle[sticle[i]]]);
        }
    }
    f.close();
    g.close();
}
