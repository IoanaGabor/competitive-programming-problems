
#include <bits/stdc++.h>
#define NMAX 752
#define MAXVAL 1000000003

using namespace std;

ifstream fi("volum.in");
ofstream fo("volum.out");

int n,m;
int mat[NMAX+5][NMAX+5];
int apa[NMAX+5][NMAX+5];
int viz[NMAX+5][NMAX+5];
priority_queue<pair<int, pair<int,int> > > pq;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

long long solve(){
    pair<int,pair<int,int> > node;
    int val,x,y,xx,yy;
    long long ret=0;
    while(!pq.empty()){
        node=pq.top();
        pq.pop();
        val=-node.first;
        x=node.second.first;
        y=node.second.second;
        for(int d=0;d<4;d++){
            xx=x+dx[d];
            yy=y+dy[d];
            if(viz[xx][yy]==0&&mat[xx][yy]!=MAXVAL){
                if(mat[xx][yy]<=val){
                    apa[xx][yy]=val-mat[xx][yy];
                    viz[xx][yy]=1;
                    pq.push(make_pair(-val,make_pair(xx,yy)));
                }else{
                    viz[xx][yy]=1;
                    pq.push(make_pair(-mat[xx][yy],make_pair(xx,yy)));
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ret+=1LL*apa[i][j];
        }
    }
    return ret;
}

int main(){
    fi>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            fi>>mat[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        pq.push(make_pair(-mat[i][1],make_pair(i,1)));
        pq.push(make_pair(-mat[i][m],make_pair(i,m)));
        viz[i][1]=viz[i][m]=1;
    }
    for(int i=2;i<m;i++){
        pq.push(make_pair(-mat[1][i],make_pair(1,i)));
        pq.push(make_pair(-mat[n][i],make_pair(n,i)));
        viz[1][i]=viz[n][i]=1;
    }
    for(int i=0;i<=n+1;i++){
        mat[i][0]=mat[i][m+1]=MAXVAL;
    }
    for(int i=0;i<=m+1;i++){
        mat[0][i]=mat[n+1][i]=MAXVAL;
    }
    fo<<solve();
    fi.close();
    fo.close();
}