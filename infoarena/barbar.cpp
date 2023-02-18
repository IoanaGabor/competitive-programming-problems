///am uitat de cazul in care nu e solutie
#include <iostream>
#include <fstream>
#include <queue>
#define NMAX 1000
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("barbar.in");
ofstream g("barbar.out");

int n,m,distd[NMAX+5][NMAX+5],ajung[NMAX+5][NMAX+5],xi,yi,xo,yo,sus;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
char harta[NMAX+5][NMAX+5];
queue <pair<int,int> > q;

void lee_ca_sa_aflu_dist_dragoni(){
    pair<int,int> aux;
    int x,y;
    while(!q.empty()){
        aux=q.front();
        q.pop();
        for(int d=0;d<4;d++){
            x=aux.first+dx[d];
            y=aux.second+dy[d];
            if(harta[x][y]!=0&&harta[x][y]!='*'&&distd[x][y]>distd[aux.first][aux.second]+1){
                distd[x][y]=distd[aux.first][aux.second]+1;
                q.push(make_pair(x,y));
            }
        }
    }
}

bool verif(int val){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ajung[i][j]=0;
        }
    }
    while(!q.empty()){
        q.pop();
    }
    q.push(make_pair(xi,yi));
    ajung[xi][yi]=1;
    pair<int,int> aux;
    int x,y;
    while(!q.empty()){
        aux=q.front();
        q.pop();
        if(aux.first==xo&&aux.second==yo){
            return true;
        }
        for(int d=0;d<4;d++){
            x=aux.first+dx[d];
            y=aux.second+dy[d];
            if(harta[x][y]!=0&&harta[x][y]!='*'&&!ajung[x][y]&&distd[x][y]>=val){
                ajung[x][y]=1;
                q.push(make_pair(x,y));
            }
        }
    }
    return false;
}

int cauta(){
    int pas=(1<<20),ret=0;
    sus=min(sus,min(distd[xi][yi],distd[xo][yo]));
    while(pas){
        if(ret+pas<=sus&&verif(ret+pas)){
            ret+=pas;
        }
        pas>>=1;
    }
    return ret;
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>harta[i][j];
            distd[i][j]=MAXVAL;
            if(harta[i][j]=='D'){
                distd[i][j]=0;
                q.push(make_pair(i,j));
            }else if(harta[i][j]=='I'){
                xi=i;
                yi=j;
            }else if(harta[i][j]=='O'){
                xo=i;
                yo=j;
            }
        }
    }
    lee_ca_sa_aflu_dist_dragoni();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(distd[i][j]!=MAXVAL){
                sus=max(sus,distd[i][j]);
            }
        }
    }
    if(sus==0){
        sus=MAXVAL;
    }
    int sol=cauta();
    if(sol==0){
        g<<-1;
    }else{
        g<<sol;
    }
    f.close();
    g.close();
}
