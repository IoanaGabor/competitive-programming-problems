
#include <iostream>
#include <fstream>
#define NMAX 2000
#define MAXVAL 1000000

using namespace std;

ifstream f("movedel.in");
ofstream g("movedel.out");

int n,m,ciur[MAXVAL+5],prime[MAXVAL+5],lprime,viz[NMAX+5],poz;

bool calculeaza_ciur(){
    for(int i=2;i*i<=MAXVAL;i++){
        if(ciur[i]==0){
            for(int j=i*2;j<=MAXVAL;j+=i){
                ciur[j]=1;
            }
        }
    }
    for(int i=2;i<=MAXVAL;i++){
        if(ciur[i]==0){
            prime[++lprime]=i;
        }
    }
}

int main(){
    f>>n>>m;
    calculeaza_ciur();
    for(int i=1;i<=m;i++){
        poz=(poz+prime[i])%n;
        if(i!=m){
            viz[poz]++;
        }
    }
    for(int i=0;i<n;i++){
        if(viz[i]==0){
            poz=i;
        }
    }
    poz++;
    for(int i=1;i<=n;i++){
        if(i==poz){
            g<<'a';
        }else{
            g<<'b';
        }
    }
    g<<'\n';
    g<<'a';
    for(int i=2;i<=n;i++){
        g<<'c';
    }
    g<<'\n';
    f.close();
    g.close();
}
