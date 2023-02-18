
#include <iostream>
#include <fstream>
#define NMAX 1000

using namespace std;

ifstream f("dreptunghiuri2.in");
ofstream g("dreptunghiuri2.out");

struct dreptunghi{
    int xmi,xma,ymi,yma;
} dr[(NMAX*NMAX/2)+5];
int n,m,matrice[NMAX+5][NMAX+5],m2[NMAX+5][NMAX+5],cnt,omax,nrmax;

void filll(int x,int y,int ind){
    dr[ind].xmi=min(x,dr[ind].xmi);
    dr[ind].xma=max(x,dr[ind].xma);
    dr[ind].ymi=min(y,dr[ind].ymi);
    dr[ind].yma=max(y,dr[ind].yma);
    matrice[x][y]=1;
    if(matrice[x][y+1]<0){
        filll(x,y+1,ind);
    }
    if(matrice[x+1][y]<0){
        filll(x+1,y,ind);
    }
    if(matrice[x-1][y]<0){
        filll(x-1,y,ind);
    }
    if(matrice[x][y-1]<0){
        filll(x,y-1,ind);
    }
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>matrice[i][j];
            matrice[i][j]=-matrice[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(matrice[i][j]<0){
                ++cnt;
                dr[cnt].xma=dr[cnt].xmi=i;
                dr[cnt].yma=dr[cnt].ymi=j;
                filll(i,j,cnt);
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        m2[dr[i].xmi][dr[i].ymi]++;
        m2[dr[i].xmi][dr[i].yma+1]--;
        m2[dr[i].xma+1][dr[i].ymi]--;
        m2[dr[i].xma+1][dr[i].yma+1]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            m2[i][j]+=m2[i-1][j]+m2[i][j-1]-m2[i-1][j-1];
        }
    }
    for(int i=1;i<=cnt;i++){
        if(m2[dr[i].xmi][dr[i].ymi]>omax){
            omax=m2[dr[i].xmi][dr[i].ymi];
            nrmax=1;
        }else if(m2[dr[i].xmi][dr[i].ymi]==omax){
            nrmax++;
        }
    }
    g<<cnt<<' '<<omax<<' '<<nrmax<<'\n';
    f.close();
    g.close();
}
