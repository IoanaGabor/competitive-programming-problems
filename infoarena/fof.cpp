
#include <bits/stdc++.h>
#define NMAX 1000

using namespace std;

ifstream fi("fof.in");
ofstream fo("fof.out");

int n,m,x,y;
vector<int> G[NMAX+5];
int vec[NMAX+5][NMAX+5];
int cnt[NMAX+5];
int sol[NMAX+5],ls;

bool crit(int a,int b){
    if(cnt[a]==cnt[b]){
        return a<b;
    }
    return cnt[a]>cnt[b];
}

int main(){
    fi>>n>>m;
    for(int i=1;i<=m;i++){
        fi>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        vec[x][y]=vec[y][x]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cnt[j]=0;
        }
        for(int j=0;j<G[i].size();j++){
            x=G[i][j];            
            for(int k=0;k<G[x].size();k++){
                y=G[x][k];
                if(!vec[i][y] && i!=y){
                    cnt[y]++;
                }
            }
        }
        ls=0;                
        for(int j=1;j<=n;j++){
            if(cnt[j]){
                sol[++ls]=j;
            }
        }
        sort(sol+1,sol+ls+1,crit);
        for(int j=1;j<=ls;j++){
            fo<<sol[j]<<' ';
        }
        fo<<'\n';
    }
    fi.close();
    fo.close();
}