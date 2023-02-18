
#include <iostream>
#include <fstream>
#define nmax 100005

using namespace std;

long long n,p,sir[nmax],ordine[nmax];

int main() {
    ifstream f("roata.in");
    ofstream g("roata.out");
    f>>n>>p;
    long long suma=0;
    for(int i=1;i<=p;i++){
        f>>sir[i];
        suma=suma+sir[i];
    }
    g<<suma<<'\n';
    for(int i=1;i<=n;i++){
        ordine[i]=i;
    }
    long long iminim=0;
    if(p>n){
        for(int i=n+1;i<=p;i++){
            iminim=1;
            for(int j=2;j<=n;j++){
                if(sir[j]<sir[iminim]){
                    iminim=j;
                }
            }
            g<<ordine[iminim]<<" ";
            if(sir[iminim]>1000000000){
                for(int j=1;j<=n;j++){
                    sir[j]=sir[j]-1000000000;
                }
            }

            sir[iminim]=sir[iminim]+sir[i];
            ordine[iminim]=i;
        }
    }else{
        n=p;
    }
    int ultimul;
    for(int i=1;i<=n;i++){
        iminim=1;
        for(int j=2;j<=n;j++){
            if(sir[j]<sir[iminim]){
                iminim=j;
            }
        }
        g<<ordine[iminim]<<" ";
        if(i==n){
            ultimul=iminim;
        }
        sir[iminim]=1000000000;
    }
    g<<'\n'<<ultimul<<'\n';
    f.close();
    g.close();
}
