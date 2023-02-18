
#include <iostream>
#include <fstream>
#define NMAX 500
#define pi first
#define pj second

using namespace std;

ifstream f("traseu4.in");
ofstream g("traseu4.out");

int n,m,matrice[NMAX+5][NMAX+5],best[NMAX+5],rez;
pair <int,int> poz[NMAX*NMAX+5];

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>matrice[i][j];
            poz[matrice[i][j]].pi=i;
            poz[matrice[i][j]].pj=j;
        }
        best[i]=NMAX+5;
    }
    for(int i=1;i<=n*m;i++){
        for(int ii=1;ii<=poz[i].pi;ii++){
            if(best[ii]<=poz[i].pj){
                rez=max(rez,((poz[i].pj-best[ii])+(poz[i].pi-ii)+1));
            }
        }
        best[poz[i].pi]=min(best[poz[i].pi],poz[i].pj);
    }
    g<<rez;
}
