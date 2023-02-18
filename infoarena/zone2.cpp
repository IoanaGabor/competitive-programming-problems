
#include <iostream>
#include <fstream>
#include <set>
#include <queue>
#define NMAX 300

using namespace std;

ifstream f("zone2.in");
ofstream g("zone2.out");

int n,m,k,et[NMAX+5][NMAX+5],nrzone,cnt,nrcel[NMAX*NMAX+5],nrvecini[NMAX*NMAX+5],elim[NMAX*NMAX+5],viz[NMAX*NMAX+5],rez=0;
pair<int,int> coord[NMAX*NMAX+5];
char matrice[NMAX+5][NMAX+5];
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};
set <int> vecini[NMAX*NMAX+5];
set<int>::iterator it;
queue<int> q;

bool inside(int x,int y){
    return (1<=x&&x<=n&&1<=y&&y<=m);
}

void filll(int x,int y,int val){
    if(et[x][y]==0){
        et[x][y]=val;
        cnt++;
        for(int d=0;d<4;d++){
            if(inside(x+dx[d],y+dy[d])){
                if(matrice[x][y]==matrice[x+dx[d]][y+dy[d]]){
                    filll(x+dx[d],y+dy[d],val);
                }
            }
        }
    }
}

void aflavecini(int x,int y){
    for(int d=0;d<4;d++){
        if(inside(x+dx[d],y+dy[d])&&et[x][y]!=et[x+dx[d]][y+dy[d]]){
            vecini[et[x][y]].insert(et[x+dx[d]][y+dy[d]]);
        }
    }
}

int main(){
    f>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>matrice[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!et[i][j]){
                cnt=0;
                filll(i,j,++nrzone);
                nrcel[nrzone]=cnt;
                coord[nrzone]=make_pair(i,j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            aflavecini(i,j);
        }
    }
    for(int i=1;i<=nrzone;i++){
        nrvecini[i]=vecini[i].size();
        if(nrvecini[i]<k){
            elim[i]=1;
            q.push(i);
        }
    }
    while(!q.empty()){
        int z=q.front();
        q.pop();
        for(it=vecini[z].begin();it!=vecini[z].end();it++){
            nrvecini[(*it)]--;
            if(nrvecini[(*it)]<k&&!elim[(*it)]){
                q.push((*it));
                elim[(*it)]=1;
            }
        }
    }
    for(int i=1;i<=nrzone;i++){
        if(!elim[i]&&!viz[i]){
            q.push(i);
            viz[i]=1;
            cnt=0;
            while(!q.empty()){
                int z=q.front();
                q.pop();
                cnt+=nrcel[z];
                for(it=vecini[z].begin();it!=vecini[z].end();it++){
                    if(!elim[(*it)]&&!viz[(*it)]){
                        viz[(*it)]=1;
                        q.push((*it));
                    }
                }
            }
            rez=max(rez,cnt);
        }
    }
    g<<rez;
    f.close();
    g.close();
}
