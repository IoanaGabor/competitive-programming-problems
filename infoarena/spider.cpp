
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("spider.in");
ofstream g("spider.out");

int n,m,matrice[1005][1005],maxim[1005][1005][5],rez;
int dx[]={0,-1,0,1,0};
int dy[]={0,0,1,0,-1};

bool nu_am_iesit(int x, int y){
    return ((x<=n)&&(1<=x)&&(y<=m)&&(1<=y));
}

bool nu_ma_intorc(int x, int y){
    if((x==1&&y==3)||(x==3&&y==1)||(x==2&&y==4)||(x==4&&y==2)){
        return false;
    }
    return true;
}

int calculeaza(int x,int y,int z){
    if(maxim[x][y][z]>0){
        return maxim[x][y][z];
    }
    int xx,yy,best=0;
    for(int k=1;k<=4;k++){
        if(nu_ma_intorc(z,k)){
            xx=x+dx[k];
            yy=y+dy[k];
            if(nu_am_iesit(xx,yy)&&matrice[xx][yy]<=matrice[x][y]&&matrice[xx][yy]>best){
                maxim[x][y][z]=1+calculeaza(xx,yy,k);
                best=matrice[xx][yy];
            }
        }
    }
    if(best==0){
        maxim[x][y][z]=1;
    }
    return maxim[x][y][z];
}

void afiseaza(int x,int y,int z){
    int xx,yy,zz,best=0,xbest,ybest;
    for(int k=1;k<=4;k++){
        if(nu_ma_intorc(z,k)){
            xx=x+dx[k];
            yy=y+dy[k];
            if(nu_am_iesit(xx,yy)&& matrice[xx][yy]<=matrice[x][y]&& matrice[xx][yy]>best){
                best=matrice[xx][yy];
                xbest=xx;
                ybest=yy;
                zz=k;
            }
        }
    }
    if(best==0){
        return;
    }
    g<<xbest<<' '<<ybest<<'\n';
    afiseaza(xbest,ybest,zz);
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>matrice[i][j];
        }
    }
    int best=0,ii,jj,ibest,jbest;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            best=0;
            for(int k=1;k<=4;k++){
                ii=i+dx[k];
                jj=j+dy[k];
                if(nu_am_iesit(ii,jj)&&matrice[ii][jj]<=matrice[i][j]&& matrice[ii][jj]>best){
                    best=matrice[ii][jj];
                    maxim[i][j][0]=1+calculeaza(ii,jj,k);
                }
            }
            if(best==0){
                maxim[i][j][0]=1;
            }
        }
    }
    rez=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(maxim[i][j][0]>rez){
                ibest=i;
                jbest=j;
                rez=maxim[i][j][0];
            }
        }
    }
    rez--;
    g<<rez<<'\n'<<ibest<<' '<<jbest<<'\n';
    afiseaza(ibest,jbest,0);
    f.close();
    g.close();
}
