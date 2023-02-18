
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("rosiimici.in");
ofstream g("rosiimici.out");

int n,m,matrice[1001][1001],q,x,rez[1000001],maxim;

int main(){
    f>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>matrice[i][j];
            maxim=max(maxim,matrice[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        sort(matrice[i]+1,matrice[i]+m+1);
        for(int j=1;j<=m;j++){
            rez[matrice[i][j]]=max(i*j,rez[matrice[i][j]]);
        }
    }
    for(int i=1;i<=1000001;i++){
        rez[i]=max(rez[i],rez[i-1]);
    }
    while(q--){
        f>>x;
        g<<rez[x]<<'\n';
    }
    f.close();
    g.close();
}
