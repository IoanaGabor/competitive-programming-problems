
#include <iostream>
#include <fstream>
#include <queue>
#define MAXVAL (1<<29)-1
#define NMAX 500
#define pi first
#define pj second

using namespace std;

ifstream f("panda.in");
ofstream g("panda.out");

int cerinta,n,m,t,l,c,k,s,x,y,coduri[NMAX+5][NMAX+5],mancare[NMAX+5][NMAX+5],nrpasi[NMAX+5][NMAX+5];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
queue <pair<int,int> > q;
pair <int,int> aux,auxx;

bool nuies(int i,int j){
    return (1<=i&&i<=n&&1<=j&&j<=m);
}

int main(){
    f>>cerinta>>n>>m>>t>>l>>c>>k>>s;
    for(int i=1;i<=t;i++){
        f>>x>>y;
        mancare[x][y]=1;
    }
    y=(1<<s)-1;
    k=k&y;
    s=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>coduri[i][j];
            coduri[i][j]=coduri[i][j]&y;
            x=(coduri[i][j]^k);
            coduri[i][j]=(x==y);
            s+=coduri[i][j];
        }
    }
    if(cerinta==1){
        g<<s-1;
        f.close();
        g.close();
        return 0;
    }
    q.push(make_pair(l,c));
    nrpasi[l][c]=1;
    while(!q.empty()){
        aux=q.front();
        q.pop();
        for(int d=0;d<4;d++){
            auxx.pi=aux.pi+dx[d];
            auxx.pj=aux.pj+dy[d];
            if(nuies(auxx.pi,auxx.pj)&&nrpasi[auxx.pi][auxx.pj]==0&&coduri[auxx.pi][auxx.pj]==1){
                nrpasi[auxx.pi][auxx.pj]=nrpasi[aux.pi][aux.pj]+1;
                q.push(auxx);
            }
        }
    }
    x=MAXVAL;
    y=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mancare[i][j]==1&&coduri[i][j]==1&&nrpasi[i][j]!=0){
                if(nrpasi[i][j]<x){
                    x=nrpasi[i][j];
                    y=1;
                }else if(nrpasi[i][j]==x){
                    y++;
                }
            }
        }
    }
    g<<x-1<<' '<<y;
    f.close();
    g.close();
}
