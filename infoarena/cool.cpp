
#include <iostream>
#include <fstream>
#include <algorithm>
#define nmax 5001

using namespace std;

ifstream f("cool.in");
ofstream g("cool.out");

int cerinta,n,k,sir[nmax],frecventa[1001];

int main() {
    f>>cerinta>>n>>k;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    if(cerinta==1){
        int maxim=-1,minim=10001,nr=0;
        for(int i=1;i<=k;i++){
            if(sir[i]<minim){
                minim=sir[i];
            }
            if(sir[i]>maxim){
                maxim=sir[i];
            }
            frecventa[sir[i]]++;
        }
        for(int i=1;i<=k;i++){
            if(frecventa[sir[i]]==1){
                nr++;
            }
        }
        if(nr==k&&maxim-minim+1==k){
            g<<maxim<<'\n';
        }else{
            g<<nr;
        }
    }else{
        int minim,maxim,j,contor=1,rez=1;
        for(int i=1;i<=n-1;i++){
            minim=maxim=sir[i];
            frecventa[sir[i]]++;
            for(j=i+1;j<=n && frecventa[sir[j]]==0;j++){
                frecventa[sir[j]]=1;
                if(sir[j]<minim){
                    minim=sir[j];
                }
                if(sir[j]>maxim){
                    maxim=sir[j];
                }
                if(maxim-minim==j-i){
                    if(rez<maxim-minim+1){
                        rez=maxim-minim+1;
                        contor=1;
                    }else if(rez==maxim-minim+1){
                        contor++;
                    }
                }
            }
            for(int l=minim;l<=maxim;l++){
                frecventa[l]=0;
            }
        }
        g<<rez<<'\n'<<contor<<'\n';
    }
    f.close();
    g.close();
}

