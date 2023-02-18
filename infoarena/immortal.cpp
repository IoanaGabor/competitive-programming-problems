
#include <bits/stdc++.h>
#define IMMAX 15
#define NMAX 20

using namespace std;

ifstream f("immortal.in");
ofstream g("immortal.out");

int n, m, k, ok;
pair <int,int> im[IMMAX+5];
pair <pair<int,int>, pair<int,int> > sol[IMMAX+5];
int mat[NMAX+5][NMAX+5];
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
int dx2[]={0,2,0,-2};
int dy2[]={-2,0,2,0};

bool inside(int x, int y){
    return mat[x][y] >=0;
}

void bkt(int pas){
    if(pas == k-1){
        for(int i=1;i<=k-1;i++){
            g<<sol[i].first.first<<' '<<sol[i].first.second<<' '<<sol[i].second.first<<' '<<sol[i].second.second<<'\n';
        }
        ok=1;
        return;
    }
    for (int i=1;i<=k&&!ok;i++){
        if(im[i].first){
            for(int d=0;d<4&&!ok;d++){
                if(inside(im[i].first+dx[d],im[i].second+dy[d])&&mat[im[i].first+dx[d]][im[i].second+dy[d]]&&inside(im[i].first+dx2[d],im[i].second+dy2[d])&&mat[im[i].first+dx2[d]][im[i].second+dy2[d]]==0){
                    int val=mat[im[i].first+dx[d]][im[i].second+dy[d]];
                    pair<int,int> aux=im[val],aux2=im[i];
                    mat[im[val].first][im[val].second] = 0;
                    im[val].first=0;
                    mat[im[i].first][im[i].second]=0;
                    im[i].first=im[i].first+dx2[d];
                    im[i].second=im[i].second+dy2[d];                    
                    mat[im[i].first][im[i].second]=i;
                    sol[pas+1].first=aux2;
                    sol[pas+1].second.first=aux2.first+dx2[d];
                    sol[pas+1].second.second=aux2.second+dy2[d];
                    bkt(pas+1);
                    mat[aux.first][aux.second]=val;
                    im[val] = aux;
                    mat[im[i].first][im[i].second]=0;
                    im[i] = aux2;
                    mat[im[i].first][im[i].second]=i;
                }
            }
        }
    }
}

int main(){
    f>>n>>m>>k;
    for(int i=1;i<=k;i++){
        f>>im[i].first>>im[i].second;
        mat[im[i].first][im[i].second]=i;
    }
    for(int i=0;i<=n;i++){
        mat[i][0]=mat[i][m+1]=-1;
    }
    for(int i=0;i<=m;i++){
        mat[0][i]=mat[n+1][i]=-1;
    }
    bkt(0);
    f.close();
    g.close();
}
