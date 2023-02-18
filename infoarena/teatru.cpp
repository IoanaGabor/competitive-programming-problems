#include <iostream>
#include <fstream>
#define NMAX 55000

using namespace std;

ifstream f("teatru.in");
ofstream g("teatru.out");

int n,c,frecventa[30],in,sf,inr,sfr,nrc,minim,ultima[30];
char sir[NMAX+3];

int main(){
    f>>n>>c;
    for(int i=1;i<=n;i++){
        f>>sir[i];
        ultima[sir[i]-'A'+1]=i;
    }
    inr=sfr=0;
    in=1;
    for(int i=1;i<=n;i++){
        ultima[sir[i]-'A'+1]=i;
        if(frecventa[sir[i]-'A'+1]==0){
            nrc++;
        }
        frecventa[sir[i]-'A'+1]++;
        if(nrc>c){
            minim=NMAX+5;
            for(int j=in;j<=sf;j++){
                minim=min(minim,ultima[sir[j]-'A'+1]);
            }
            for(int j=in;j<=minim;j++){
                frecventa[sir[j]-'A'+1]--;
            }
            in=minim+1;
            nrc--;
        }
        sf++;
        if(sf-in>sfr-inr){
            sfr=sf;
            inr=in;
        }
    }
    g<<sfr-inr+1<<'\n';
    for(int i=inr;i<=sfr;i++){
        g<<sir[i];
    }
    f.close();
    g.close();
}
