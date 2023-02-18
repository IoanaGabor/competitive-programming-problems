#include <iostream>
#include <fstream>
#include <algorithm>
#include <bitset>
#define NMAX 8
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f ("suma3.in");
ofstream g ("suma3.out");

int n,m,matrice[NMAX+1][NMAX+1],ls,rez[NMAX*NMAX/2+1],suma_minima=MAXVAL,el[NMAX*NMAX/2+1],suma,contor;
pair <int,int> s[NMAX*NMAX/2+1],vecini[NMAX+1][NMAX+1][9];
bitset <NMAX+1> viz[NMAX+1];
int dx[]={0,-1,-1,-1,0,0,1,1,1};
int dy[]={0,0,1,-1,1,-1,0,1,-1};;

bool criteriu(pair<int,int> a,pair<int,int> b){
    return matrice[a.first][a.second]>matrice[b.first][b.second];
}

void bkt(int x,int y){
    if(contor==ls){
        if(suma<suma_minima){
            suma_minima=suma;
            for(int i=1;i<=contor;i++){
                rez[i]=el[i];
            }
        }
        return;
    }
    if(suma>=suma_minima){
        return;
    }
    int suma_aux=suma,cnt_aux=contor+1,ii,jj;
    for(int i=1;i<=ls;i++){
        ii=s[i].first;
        jj=s[i].second;
        if(!viz[ii][jj]){
            suma_aux+=cnt_aux*matrice[ii][jj];
            cnt_aux++;
            if(suma_aux>=suma_minima){
                return;
            }
        }
    }
    int x2,y2;
    for(int i=1;i<=vecini[x][y][0].first;i++){
        x2=vecini[x][y][i].first;
        y2=vecini[x][y][i].second;
        if(!viz[x2][y2]){
            viz[x2][y2]=1;
            el[contor+1]=matrice[x2][y2];
            contor++;
            suma+=contor*matrice[x2][y2];
            bkt(x2,y2);
            suma-=contor*matrice[x2][y2];
            contor--;
            viz[x2][y2]=0;
        }
    }
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>matrice[i][j];
            if(matrice[i][j]){
                s[++ls].first=i;
                s[ls].second=j;
            }
        }
    }
    int ii,jj;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=8;k++){
                ii=i+dx[k];
                jj=j+dy[k];
                if(ii>=1&&ii<=n&&jj>=1&&jj<=m&&matrice[ii][jj]){
                    vecini[i][j][++vecini[i][j][0].first]=make_pair(ii,jj);
                }
            }
            sort(vecini[i][j]+1,vecini[i][j]+vecini[i][j][0].first+1,criteriu);
        }
    }
    sort(s+1,s+ls+1,criteriu);
    for(int i=1;i<=ls;i++){
        ii=s[i].first;
        jj=s[i].second;
        viz[ii][jj]=1;
        el[1]=matrice[ii][jj];
        contor=1;
        suma=matrice[ii][jj];
        bkt(ii,jj);
        viz[ii][jj]=0;
    }
    g<<suma_minima<<'\n';
    for(int i=1;i<=ls;i++){
        g<<rez[i]<<' ';
    }
    f.close();
    g.close();
}
