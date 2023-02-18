
#include <iostream>
#include <fstream>
#include <queue>
#define NMAX 105

using namespace std;

ifstream f("traseu3.in");
ofstream g("traseu3.out");

int cub[NMAX][NMAX][NMAX],n,t,x,y,z,xi,yi,zi,xf,yf,zf,xx,yy,zz;

struct ceva{
    int a,b,c;
};

queue <ceva> q;

int dx[]={-1,0,0,0,0,1};
int dy[]={0,-1,0,0,1,0};
int dz[]={0,0,-1,1,0,0};

ceva rez[1000005];

int main(){
    f>>n>>t>>xi>>yi>>zi>>xf>>yf>>zf;
    while(t--){
        f>>x>>y>>z;
        cub[x][y][z]=-1;
    }
    ceva aux;
    x=aux.a=xi;
    y=aux.b=yi;
    z=aux.c=zi;
    q.push(aux);
    cub[xi][yi][zi]=1;
    while(!q.empty()){
        aux=q.front();
        q.pop();
        x=aux.a;
        y=aux.b;
        z=aux.c;
        for(int i=0;i<=5;i++){
            xx=x+dx[i];
            yy=y+dy[i];
            zz=z+dz[i];
            if(xx>=1&& xx<=n&&yy>=1&&yy<=n&&zz>=1&&zz<=n&&(cub[xx][yy][zz]==0)){
                cub[xx][yy][zz]=cub[x][y][z]+1;
                aux.a=xx;
                aux.b=yy;
                aux.c=zz;
                q.push(aux);
            }
        }
    }
    g<<cub[xf][yf][zf]<<'\n';
    t=cub[xf][yf][zf];
    x=xf;
    y=yf;
    z=zf;
    for(int i=t;i>=1;i--){
        rez[i].a=x;
        rez[i].b=y;
        rez[i].c=z;
        for(int j=0;j<=5;j++){
            xx=x+dx[j];
            yy=y+dy[j];
            zz=z+dz[j];
            if(i>1&&xx>=1&& xx<=n&&yy>=1&&yy<=n&&zz>=1&&zz<=n&&cub[xx][yy][zz]==i-1){
                x=xx;
                y=yy;
                z=zz;
                break;
            }
        }
    }
    for(int i=1;i<=t;i++){
        g<<rez[i].a<<' '<<rez[i].b<<' '<<rez[i].c<<'\n';
    }
    f.close();
    g.close();
}
