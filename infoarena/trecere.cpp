
#include <iostream>
#include <fstream>
#define NMAX 120
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("trecere.in");
ofstream g("trecere.out");

int n,m,val,x[NMAX+1][NMAX+1],y[NMAX+1][NMAX+1],e=MAXVAL,cul,col,s;

int abs(int nr){
    if(nr<0){
        return -nr;
    }
    return nr;
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>val;
            x[val][++x[val][0]]=i;
            y[val][++y[val][0]]=j;
        }
    }
    for(int culoare=1;culoare<=m;culoare++){
        for(int coloana=1;coloana<=m;coloana++){
            s=0;
            for(int i=1;i<=n;i++){
                s+=abs(coloana-y[culoare][i])+abs(i-x[culoare][i]);
            }
            if(s<e){
                e=s;
                cul=culoare;
                col=coloana;
            }
        }
    }
    g<<e<<' '<<cul<<' '<<col<<'\n';
    f.close();
    g.close();
}
