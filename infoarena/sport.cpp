#include <iostream>
#include <fstream>
#include <algorithm>
#define NMAX 1000

using namespace std;

ifstream f("sport.in");
ofstream g("sport.out");

int n,sir1[NMAX+1],sir2[NMAX+1],poz,maxim=-1;

int main() {
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir1[i];
        sir2[i]=sir1[i];
    }
    sort(sir2+1,sir2+n+1);
    for(int i=1;i<=n;i++){
        poz=i;
        for(int j=1;j<=n;j++){
            if(sir1[j]==sir2[poz]&&poz<=n){
                poz++;
            }
        }
        maxim=max(maxim,poz-i);
    }
    g<<n-maxim;
    f.close();
    g.close();
}
