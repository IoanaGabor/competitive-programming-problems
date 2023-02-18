
#include <bits/stdc++.h>
#define NMAX 100000
#define VALMAX (1LL<<30)

using namespace std;

ifstream fi("spiridusi.in");
ofstream fo("spiridusi.out");

int n,c,x,y;
int sp[NMAX+5],p[NMAX+5];
int sumsp[NMAX+5][25],mini[NMAX+5][25];
int stivsp[NMAX+5],stivp[NMAX+5],stivn[NMAX+5];
int p2[NMAX+5];
int levn[NMAX+5];
vector<int> arb[NMAX+5];
int par[NMAX+5][25];
int sol=-VALMAX;
int aux;

void dfs1(int nod,int parent,int val){
    par[nod][0]=parent;
    sumsp[nod][0]=sp[parent];
    mini[nod][0]=val+p[parent];
    for(int i=0;i<arb[nod].size();i++){
        if(arb[nod][i]!=parent){
            dfs1(arb[nod][i],nod,val+p[parent]);
        }
    }
}

int cauta(int nod){
    int ssumsp=sp[nod],pas=20;
    while(pas>=0){
        if(par[nod][pas]&&ssumsp+sumsp[nod][pas]<=c){
            ssumsp+=sumsp[nod][pas];
            nod=par[nod][pas];
        }
        pas--;
    }
    return nod;
}

void dfs2(int nod,int parent,int lev){
    stivn[lev]=nod;
    stivp[lev]=stivp[lev-1]+p[nod];
    levn[nod]=lev;
    for(int i=1;par[nod][i-1]&&par[par[nod][i-1]][i-1];i++){
        par[nod][i]=par[par[nod][i-1]][i-1];
        sumsp[nod][i]=sumsp[nod][i-1]+sumsp[par[nod][i-1]][i-1];
        mini[nod][i]=min(mini[nod][i-1],mini[par[nod][i-1]][i-1]);
    }
    if(sp[nod]<=c){
        y=cauta(nod);
        x=levn[y];
        aux=p2[lev-x+1];
        //cout<<nod<<' '<<y<<' '<<x<<' '<<lev<<' '<<aux<<' '<<min(mini[nod][aux],mini[stivn[x+(1<<aux)-1]][aux])<<' '<<stivp[lev]-min(mini[nod][aux],mini[stivn[x+(1<<aux)-1]][aux])<<' '<<stivp[lev]<<'\n';
        sol=max(sol,stivp[lev]-min(mini[nod][aux],mini[stivn[x+(1<<aux)-1]][aux]));
    }
    for(int i=0;i<arb[nod].size();i++){
        if(arb[nod][i]!=parent){
            dfs2(arb[nod][i],nod,lev+1);
        }
    }
}

int main(){
    fi>>n>>c;
    p2[0]=-1;
    for(int i=1;i<=n;i++){
        fi>>sp[i];
        p2[i]=p2[i/2]+1;
    }
    for(int i=1;i<=n;i++){
        fi>>p[i];
    }
    for(int i=1;i<n;i++){
        fi>>x>>y;
        arb[x].push_back(y);
        arb[y].push_back(x);
    }
    dfs1(1,0,0);
    dfs2(1,0,1);
    fo<<sol<<'\n';
    fi.close();
    fo.close();
}