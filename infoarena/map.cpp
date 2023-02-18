
#include <iostream>
#include <fstream>
#define NMAX 2000

using namespace std;

ifstream f("map.in");
ofstream g("map.out");

int n,m;
char matrice[NMAX+5][NMAX+5];
int frecventa[NMAX+5],pi[NMAX+5];

void calc_pi(int ind){
    int k=0;
    pi[1]=0;
    for(int i=2;i<=m;i++){
        while(k&&matrice[ind][k+1]!=matrice[ind][i]){
            k=pi[k];
        }
        if(matrice[ind][k+1]==matrice[ind][i]){
            k++;
        }
        pi[i]=k;
    }
    k=m;
    while(k>m/2){
        frecventa[k]++;
        k=pi[k];
    }
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        f>>(matrice[i]+1);
        calc_pi(i);
    }
    for(int i=m/2+1;i<=m;i++){
        if(frecventa[i]==n){
            g<<i<<'\n';
            break;
        }
    }
    f.close();
    g.close();
}
