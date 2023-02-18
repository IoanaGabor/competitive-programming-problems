
#include <iostream>
#include <fstream>
#define NMAX 13

using namespace std;

ifstream f("damesah.in");
ofstream g("damesah.out");

int coloana[NMAX+1],diag1[2*NMAX+1],diag2[2*NMAX+1],n,prima,rez[NMAX+1],contor;

void bkt(int k){
    if(k==n+1){
        if(prima==0){
            for(int i=1;i<=n;i++){
                g<<rez[i]<<' ';
            }
            g<<'\n';
            prima=1;
        }
        contor++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(coloana[i]==0&&diag1[k-i+n]==0&&diag2[k+i-1]==0){
            coloana[i]=1;
            diag1[k-i+n]=1;
            diag2[k+i-1]=1;
            rez[k]=i;
            bkt(k+1);
            coloana[i]=0;
            diag1[k-i+n]=0;
            diag2[k+i-1]=0;
        }
    }
}

int main(){
    f>>n;
    bkt(1);
    g<<contor;
    f.close();
    g.close();
}
