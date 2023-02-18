
#include <iostream>
#include <fstream>
#include <cstring>
#define NMAX 10000000

using namespace std;

ifstream f("radixsort.in");
ofstream g("radixsort.out");

int n,sir[NMAX+1],sir2[NMAX+1],contor[(1<<8)+10],a,b,c;

void radixsort(){
    for(int k=0;k<=3;k++){
        memset(contor,0,sizeof contor);
        for(int i=1;i<=n;i++){
            contor[((sir[i]>>(k*8))&255)+1]++;
        }
        for(int i=1;i<(1<<8);i++){
            contor[i]+=contor[i-1];
        }
        for(int i=1;i<=n;i++){
            sir2[++contor[(sir[i]>>(k*8))&255]]=sir[i];
        }
        for(int i=1;i<=n;i++){
            sir[i]=sir2[i];
        }
    }
}

int main(){
    f>>n>>a>>b>>c;
    sir[1]=b;
    for(int i=2;i<=n;i++){
        sir[i]=1LL*(1LL*a*sir[i-1]+1LL*b)%c;
    }
    radixsort();
    for(int i=1;i<=n;i+=10){
        g<<sir[i]<<' ';
    }
    f.close();
    g.close();
}
