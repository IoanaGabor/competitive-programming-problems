
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("geamuri.in");
ofstream g("geamuri.out");

int m,val,n,c,x1,x2,y1,y2,harta[1026][1026],contor[50001];

int main(){
    f>>c>>n;
    for(int i=1;i<=n;i++){
        f>>x1>>y1>>x2>>y2;
        harta[x1][y1]++;
        harta[x1][y2+1]--;
        harta[x2+1][y1]--;
        harta[x2+1][y2+1]++;
    }
    for(int i=1;i<=c;i++){
        for(int j=1;j<=c;j++){
            harta[i][j]+=harta[i-1][j]+harta[i][j-1]-harta[i-1][j-1];
            contor[harta[i][j]]++;
        }
    }
    f>>m;
    while(m--){
        f>>val;
        g<<contor[val]<<'\n';
    }
    f.close();
    g.close();
}
