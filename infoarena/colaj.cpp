
#include <iostream>
#include <fstream>
#include <algorithm>
#define NMAX 100
#define MAXVAL 8005

using namespace std;

ifstream f("colaj.in");
ofstream g("colaj.out");

struct dreptunghi{
    int x1,y1,x2,y2;
    int pozx1,pozx2,pozy1,pozy2;
} dr[NMAX+5];
int n,m,p,matrice[2*NMAX+5][2*NMAX+5],newn,matm,matp,xmin=MAXVAL,xmax=-1,ymin=MAXVAL,ymax=-1,X[MAXVAL],lx,Y[MAXVAL],ly,cnt;

bool crit(dreptunghi a,dreptunghi b){
    if(a.x1==b.x1){
        return a.y1<b.y1;
    }
    return a.x1<b.x1;
}

void init(){
f>>n>>m>>p;
    for(int i=1;i<=n;i++){
        f>>dr[i].y1>>dr[i].x1>>dr[i].y2>>dr[i].x2;
        xmin=min(xmin,dr[i].x1);
        ymin=min(ymin,dr[i].y1);
        xmax=max(xmax,dr[i].x2);
        ymax=max(ymax,dr[i].y2);
    }
    sort(dr+1,dr+n+1,crit);
    newn=n;
    for(int i=1;i<=n;i++){
        if(dr[i].x1!=MAXVAL){
            for(int j=i+1;j<=n;j++){
                if(dr[j].x1!=MAXVAL&&dr[i].y1<=dr[j].y1&&dr[j].x2<=dr[i].x2&&dr[j].y2<=dr[i].y2){
                    dr[j].x1=MAXVAL;
                    newn--;
                }
            }
        }
    }
    sort(dr+1,dr+n+1,crit);
    n=newn;
    matm=matp=2*n;
    if(xmin!=0){
        matp++;
        X[0]=1;
    }
    for(int i=1;i<=n;i++){
        X[dr[i].x1]=1;
    }
    for(int i=1;i<=n;i++){
        X[dr[i].x2]=1;
    }
    if(xmax==p){
        matp--;
        X[xmax]=matp+1;
    }
    if(ymin!=0){
        matm++;
        Y[0]=1;
    }
    for(int i=1;i<=n;i++){
        Y[dr[i].y1]=1;
    }
    for(int i=1;i<=n;i++){
        Y[dr[i].y2]=1;
    }
    if(ymax==m){
        matm--;
        Y[ymax]=matm+1;
    }
    for(int i=0;i<=xmax;i++){
        if(X[i]==1){
            X[i]=++lx;
        }
    }
    for(int i=0;i<=ymax;i++){
        if(Y[i]==1){
            Y[i]=++ly;
        }
    }
    for(int i=1;i<=n;i++){
        dr[i].pozx1=X[dr[i].x1];
        dr[i].pozx2=X[dr[i].x2];
        dr[i].pozy1=Y[dr[i].y1];
        dr[i].pozy2=Y[dr[i].y2];
    }
    for(int i=1;i<=n;i++){
        for(int ii=dr[i].pozx1;ii<dr[i].pozx2;ii++){
            for(int jj=dr[i].pozy1;jj<dr[i].pozy2;jj++){
                matrice[ii][jj]=-1;
            }
        }
    }
    for(int i=0;i<=matp+1;i++){
        matrice[i][0]=matrice[i][matm+1]=-1;
    }
    for(int i=0;i<=matm+1;i++){
        matrice[0][i]=matrice[matp+1][i]=-1;
    }
}

void filll(int x,int y){
    matrice[x][y]=cnt;
    if(matrice[x-1][y]==0){
        filll(x-1,y);
    }
    if(matrice[x][y+1]==0){
        filll(x,y+1);
    }
    if(matrice[x+1][y]==0){
        filll(x+1,y);
    }
    if(matrice[x][y-1]==0){
        filll(x,y-1);
    }
}

int main(){
    init();
    for(int i=1;i<=matp;i++){
        for(int j=1;j<=matm;j++){
            if(matrice[i][j]==0){
                cnt++;
                filll(i,j);
            }
        }
    }
    g<<cnt<<'\n';
    f.close();
    g.close();
}
