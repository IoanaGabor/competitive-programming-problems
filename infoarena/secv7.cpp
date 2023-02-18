
#include <iostream>
#include <fstream>
#define MAXIM (1LL<<31)-1

using namespace std;

ifstream f("secv7.in");
ofstream g("secv7.out");

int n,sir[30005],max_stanga[30005],max_dreapta[30005],maxim,poz_maxim,ii,jj,suma=MAXIM;

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
        max_stanga[i]=max(max_stanga[i-1],sir[i]);
        if(maxim<sir[i]){
            maxim=sir[i];
            poz_maxim=i;
        }
    }
    for(int i=n;i>=1;i--){
        max_dreapta[i]=max(max_dreapta[i+1],sir[i]);
    }
    for(int i=poz_maxim;i<n-1;i++){
        if(maxim+sir[i+1]+max_dreapta[i+2]<suma){
            suma=maxim+sir[i+1]+max_dreapta[i+2];
            ii=i;
            jj=i+1;
        }
    }
    for(int i=poz_maxim-1;i>=2;i--){
        if(maxim+sir[i]+max_stanga[i-1]<suma){
            suma=maxim+sir[i]+max_stanga[i-1];
            ii=i-1;
            jj=i;
        }
    }
    if(poz_maxim!=1&&poz_maxim!=n&&sir[1]+sir[n]+maxim<suma){
        suma=sir[1]+sir[n]+maxim;
        ii=1;
        jj=n-1;
    }
    g<<suma<<'\n'<<ii<<' '<<jj<<'\n';
    f.close();
    g.close();
}
