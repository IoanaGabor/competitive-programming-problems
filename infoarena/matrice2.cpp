
#include <bits/stdc++.h>
#define NMAX 300
#define QMAX 20000

using namespace std;

ifstream fi("matrice2.in");
ofstream fo("matrice2.out");

struct cel{
    int val,x,y;
} edges[NMAX*NMAX+5];

struct query{
    int i1,j1,i2,j2,rez,ind;
} q[QMAX+5],aux1[QMAX+5],aux2[QMAX+5];

int n,l,nrq,laj,la1,la2;
int mat[NMAX+5][NMAX+5];
pair<int,int> et[NMAX+5][NMAX+5];
int sz[NMAX+5][NMAX+5];
int viz[NMAX+5][NMAX+5];
int dx[]={0,-1,0,1,0};
int dy[]={0,0,-1,0,1};
pair<int,int> aux_join[6];

bool crit1(cel a,cel b){
    return a.val>b.val;
}

bool crit2(query a,query b){
    return a.rez>b.rez;
}

bool crit3(query a,query b){
    return a.ind<b.ind;
}

void citire(){
    fi>>n>>nrq;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            fi>>mat[i][j];
            edges[++l]={mat[i][j],i,j};
        }
    }
    sort(edges+1,edges+l+1,crit1);
    for(int i=1;i<=nrq;i++){
        fi>>q[i].i1>>q[i].j1>>q[i].i2>>q[i].j2;
        q[i].rez=0;
        q[i].ind=i;
    }
}

pair<int,int> get_parent(int x,int y){
    if(make_pair(x,y)!=et[x][y]){
        et[x][y]=get_parent(et[x][y].first,et[x][y].second);
    }
    return et[x][y];
}

void reset_dsu(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            et[i][j]={i,j};
            sz[i][j]=1;
            viz[i][j]=0;
        }
    }
}

void add(int x,int y){
    viz[x][y]=1;
    int xx, yy;
    pair<int,int> par;
    laj=0;
    for(int d=0;d<5;d++){
        xx=x+dx[d];
        yy=y+dy[d];
        if(viz[xx][yy]){
            par=get_parent(xx,yy);
            aux_join[++laj]=par;
        }
    }
    sort(aux_join+1,aux_join+laj+1);
    int ind=1;
    for(int i=2;i<=laj;i++){
        if(sz[aux_join[ind].first][aux_join[ind].second]<sz[aux_join[i].first][aux_join[i].second]){
            ind=i;
        }
    }
    for(int i=1;i<=laj;i++){
        if(ind!=i&&aux_join[i]!=aux_join[i-1]){
            et[aux_join[i].first][aux_join[i].second]=aux_join[ind];
            sz[aux_join[ind].first][aux_join[ind].second]+=sz[aux_join[i].first][aux_join[i].second];
        }
    }
}

void cautare(){
    int pas=1<<19,poz;
    pair<int,int> par1,par2;
    while(pas){
        poz=1,la1=la2=0;
        reset_dsu();
        for(int i=1;i<=nrq;i++){
            while(poz<=l&&edges[poz].val>=q[i].rez+pas){
                add(edges[poz].x,edges[poz].y);
                poz++;
            }
            par1=get_parent(q[i].i1,q[i].j1);
            par2=get_parent(q[i].i2,q[i].j2);
            if(par1==par2){
                q[i].rez+=pas;
                aux1[++la1]=q[i];
            }else{
                aux2[++la2]=q[i];
            }
        }
        merge(aux1+1,aux1+la1+1,aux2+1,aux2+la2+1,q+1,crit2);
        pas>>=1;
    }
}

void afisare(){
    sort(q+1,q+nrq+1,crit3);
    for(int i=1;i<=nrq;i++){
        fo<<q[i].rez<<'\n';
    }
}

int main(){
    citire();
    cautare();
    afisare();
    fi.close();
    fo.close();
}