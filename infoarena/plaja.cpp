
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("plaja.in");
ofstream g("plaja.out");

int a,b,m,n,u,umbrele[2004][2004],prosoape[2004][2004],x,y,x2,y2,rez1,rez2;

int suma(int i1,int j1,int i2,int j2,int a[][2004]){
    return a[i2][j2]-a[i2][j1-1]-a[i1-1][j2]+a[i1-1][j1-1];
}

int main(){
    f>>a>>b>>u;
    for(int i=1;i<=u;i++){
        f>>x>>y;
        umbrele[x][y]=1;
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            umbrele[i][j]=umbrele[i][j]+(umbrele[i-1][j]+umbrele[i][j-1]-umbrele[i-1][j-1]);
        }
    }
    f>>n;
    for(int i=1;i<=n;i++){
        f>>x>>y>>x2>>y2;
        if(suma(x,y,x2,y2,umbrele)==0){
            rez1++;
            prosoape[x][y]++;
            prosoape[x2+1][y2+1]++;
            prosoape[x][y2+1]--;
            prosoape[x2+1][y]--;
        }
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            prosoape[i][j]=prosoape[i][j]+prosoape[i-1][j]+prosoape[i][j-1]-prosoape[i-1][j-1];
        }
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            prosoape[i][j]=prosoape[i][j]+prosoape[i-1][j]+prosoape[i][j-1]-prosoape[i-1][j-1];
        }
    }
    f>>m;
    for(int i=1;i<=m;i++){
        f>>x>>y>>x2>>y2;
        if(suma(x,y,x2,y2,prosoape)==0&&suma(x,y,x2,y2,umbrele)==0){
            rez2++;
        }
    }
    g<<rez1<<' '<<rez2<<'\n';
    f.close();
    g.close();
}
