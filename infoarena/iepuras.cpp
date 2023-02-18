#include <iostream>
#include <fstream>
#define NMAX 205

using namespace std;

ifstream f("iepuras.in");
ofstream g("iepuras.out");

int n,m,h[NMAX][NMAX],d,x,y,ziduri,xx,yy,nrmorcovi,cnt_morcovi,nr_pasi,ingeras,nrb[NMAX][NMAX];
int dx[]={0,-1,0,1,0};
int dy[]={0,0,-1,0,1};

void citire(){
    f>>n>>m;
    f>>x>>y>>d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>h[i][j];
            if(h[i][j]==7){
                nrmorcovi++;
            }
        }
    }
    f>>ziduri;
    while(ziduri--){
        f>>xx>>yy;
        h[xx][yy]=-8;
    }
    ziduri=1;
}

bool sfarsit(){
    if(x<1||y<1||x>n||y>m){
        g<<"RATACIT"<<'\n';
        g<<x-dx[d]<<' '<<y-dy[d]<<'\n';
        g<<cnt_morcovi<<' '<<nr_pasi<<'\n';
        return true;
    }
    if(ingeras){
        g<<"INGERAS"<<'\n';
        g<<x<<' '<<y<<'\n';
        g<<cnt_morcovi<<' '<<nr_pasi<<'\n';
        return true;
    }
    if(nrmorcovi==cnt_morcovi){
        g<<"FERICIT"<<'\n';
        g<<x<<' '<<y<<'\n';
        g<<cnt_morcovi<<' '<<nr_pasi<<'\n';
        return true;
    }
    return false;
}

void decodifica(){
    if(h[x][y]<=4&&h[x][y]>=1){
        d=h[x][y];
        h[x][y]=0;
    }else if(h[x][y]==5){
        x=x-dx[d];
        y=y-dy[d];
        d=(d+2)%4;
        if(d==0){
            d=4;
        }
        nr_pasi--;
    }else if(h[x][y]==6){
        ingeras=1;
    }else if(h[x][y]==7){
        cnt_morcovi++;
        h[x][y]=0;
        if(cnt_morcovi==nrmorcovi){
            return;
        }
    }else if(h[x][y]*ziduri==8){
        x=x-dx[d];
        y=y-dy[d];
        d=(d+2)%4;
        if(d==0){
            d=4;
        }
        nr_pasi--;
    }else if(h[x][y]==9){
        ziduri*=(-1);
    }
    for(int i=1;i<=4;i++){
        if(h[x+dx[i]][y+dy[i]]==6){
            nrb[x+dx[i]][y+dy[i]]++;
            if(nrb[x+dx[i]][y+dy[i]]==2){
                ingeras=1;
            }
        }
    }
}

void rezolva(){
    while(!sfarsit()){
        x+=dx[d];
        y+=dy[d];
        nr_pasi++;
        decodifica();
    }
}

int main(){
    citire();
    rezolva();
    f.close();
    g.close();
}
