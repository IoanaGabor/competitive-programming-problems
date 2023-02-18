
#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#define KMAX 10
#define NMAX 60
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("miting.in");
ofstream g("miting.out");

queue<pair<int,int> >q;
int cerinta,n,m,imin=KMAX+5,imax=0,jmin=KMAX+5,jmax=0,k,rez=MAXVAL,poz;
long long dp[KMAX+5][KMAX+5][NMAX+5][NMAX+5];
char sir[KMAX+5],matrice[NMAX+5][NMAX+5];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void bfs(int ii,int jj,int i,int j){
    q.push(make_pair(i,j));
    pair<int,int> aux;
    int x,y;
    while(!q.empty()){
        aux=q.front();
        q.pop();
        for(int d=0;d<4;d++){
            x=aux.first+dx[d];
            y=aux.second+dy[d];
            if(1<=x&&x<=n&&1<=y&&y<=m&&dp[ii][jj][x][y]>dp[ii][jj][aux.first][aux.second]+1&&matrice[x][y]!='#'){
                dp[ii][jj][x][y]=dp[ii][jj][aux.first][aux.second]+1;
                q.push(make_pair(x,y));
            }
        }
    }
}

int main(){
    f>>cerinta>>n>>m;
    f>>(sir+1);
    k=strlen(sir+1);
    for(int ii=0;ii<=k;ii++){
        for(int jj=0;jj<=k;jj++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    dp[ii][jj][i][j]=MAXVAL;
                }
            }
        }
    }
    f.get();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f.get(matrice[i][j]);
        }
        f.get();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if('A'<=matrice[i][j]&&matrice[i][j]<='Z'){
                imin=min(imin,i),imax=max(imax,i),jmin=min(jmin,j),jmax=max(jmax,j);
                poz=1;
                while(sir[poz]!=matrice[i][j]){
                    poz++;
                }
                dp[poz][poz][i][j]=0;
                bfs(poz,poz,i,j);
            }
        }
    }
    if(cerinta==1){
        g<<(imax-imin+1)*(jmax-jmin+1);
        f.close();
        g.close();
    }
    for(int l=2;l<=k;l++){
        for(int st=1,dr=l;dr<=k;st++,dr++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(matrice[i][j]!='#'){
                        for(int u=st;u<dr;u++){
                            dp[st][dr][i][j]=min(dp[st][dr][i][j],1LL*(dp[st][u][i][j]+dp[u+1][dr][i][j]));
                        }
                        bfs(st,dr,i,j);
                        if(l==k){
                            rez=min(1LL*rez,dp[st][dr][i][j]);
                        }
                    }
                }
            }
        }
    }
    g<<rez;
    f.close();
    g.close();
}
