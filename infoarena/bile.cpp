
#include <bits/stdc++.h>
#define NMAX 250

using namespace std;

ifstream fi("bile.in");
ofstream fo("bile.out");

int n,m;
pair<int,int> bile[NMAX*NMAX+5];
int mat[NMAX+5][NMAX+5];
pair<int,int> parent[NMAX+5][NMAX+5];
int size[NMAX+5][NMAX+5];
int rez[NMAX*NMAX+5];
int best;
int dx[]={0,1,0,-1,0};
int dy[]={1,0,-1,0,0};
pair<int,int> aux[6];
int la;

pair<int,int> get_parent(pair<int,int> el){
    if(parent[el.first][el.second]!=el){
        parent[el.first][el.second]=get_parent(parent[el.first][el.second]);
    }
    return parent[el.first][el.second];
}

void join(int x,int y){
    int xx,yy;
    pair<int,int> p;
    la=0;
    mat[x][y]=1;
    size[x][y]=1;
    for(int d=0;d<5;d++){
        xx=x+dx[d];
        yy=y+dy[d];
        if(mat[xx][yy]){
            p=get_parent(make_pair(xx,yy));
            aux[++la]=p;
        }
    }
    sort(aux+1,aux+la+1);
    int ind=1;
    for(int i=2;i<=la;i++){
        if(aux[i]!=aux[i-1]){
            if(size[aux[ind].first][aux[ind].second]<size[aux[i].first][aux[i].second]){
                ind=i;
            }
        }
    }
    for(int i=1;i<=la;i++){
        if(aux[i]!=aux[i-1]&&aux[i]!=aux[ind]){
            parent[aux[i].first][aux[i].second]=aux[ind];
            size[aux[ind].first][aux[ind].second]+=size[aux[i].first][aux[i].second];
        }
    }
    best=max(best,size[aux[ind].first][aux[ind].second]);
}

int main(){
    fi>>n;
    for(int i=1;i<=n*n;i++){
        fi>>bile[i].first>>bile[i].second;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            parent[i][j]=make_pair(i,j);
            size[i][j]=0;
        }
    }
    m=n*n;
    for(int i=m;i>=1;i--){
        rez[i]=best;
        join(bile[i].first,bile[i].second);
    }
    for(int i=1;i<=m;i++){
        fo<<rez[i]<<'\n';
    }
    fi.close();
    fo.close();
}