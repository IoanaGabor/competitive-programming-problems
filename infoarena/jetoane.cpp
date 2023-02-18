#include <iostream>
#include <fstream>
#define NMAX 28000
#define VALMAX 50000

using namespace std;

ifstream f("jetoane.in");
ofstream g("jetoane.out");

int n,m,sir1[NMAX+1],sir2[NMAX+1],fr[VALMAX+1],minim=VALMAX+1,maxim=-1,cnt1,cnt2;

int main() {
    f>>n>>m;
    for(int i=1;i<=n;i++){
        f>>sir1[i];
        fr[sir1[i]]++;
    }
    for(int i=1;i<=m;i++){
        f>>sir2[i];
        if(fr[sir2[i]]){
            minim=min(minim,sir2[i]);
            maxim=max(maxim,sir2[i]);
        }
    }
    for(int i=1;i<=n;i++){
        if(sir1[i]<minim||sir1[i]>maxim){
            cnt1++;
        }
    }
    for(int i=1;i<=m;i++){
        if(sir2[i]<minim||sir2[i]>maxim){
            cnt2++;
        }
    }
    g<<minim<<' '<<maxim<<' ';
    if(cnt1==cnt2){
        g<<0;
    }else if(cnt1<cnt2){
        g<<2;
    }else{
        g<<1;
    }
    f.close();
    g.close();
}
