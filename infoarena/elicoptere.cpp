
#include <bits/stdc++.h>
#define NMAX 100
#define MAXVAL 2000000
#define xx first
#define yy second

using namespace std;

ifstream fi("elicoptere.in");
ofstream fo("elicoptere.out");

struct triangle{
    pair<int,int> coords[3];
} tr[NMAX+5];

int v,n,k;
vector<int> G[NMAX+5];
int cnt1,cnt2,nrnod,le;
bool viz[NMAX+5];
pair<long double, pair<int,int>> edge[NMAX*NMAX/2+5];
int parent[NMAX+5],nrn[NMAX+5];

long double minim(long double a,long double b){
    if(a<b){
        return a;
    }
    return b;
}

long double modul(long double a){
    if(a<0){
        return -a;
    }
    return a;
}

long double dist(long double x1,long double y1,long double x2, long double y2, long double x3, long double y3){
    long double ret=MAXVAL;
    if(y2==y1){
        if((x1<=x3&&x3<=x2)||(x2<=x3&&x3<=x1)){
            ret=modul(y3-y2);
        }
    }else if(x2==x1){
        if((y1<=y3&&y3<=y2)||(y2<=y3&&y3<=y1)){
            ret=modul(x3-x2);
        }
    }else{
        long double x=(long double)((long double)((x2-x1)*(y3-y1))/(long double)(y2-y1))+x1;
        if((y1<=y3&&y3<=y2)||y2<=y3&&y3<=y1){
            ret=modul(x-x3);
        }
        long double y=(long double)((long double)((y2-y1)*(x3-x1))/(long double)(x2-x1))+y1;
        if((x1<=x3&&x3<=x2)||(x2<=x3&&x3<=x1)){
            ret=minim(ret,modul(y-y3));
        }
    }
    return ret;
}

long double triangle_dist(triangle a, triangle b){
    long double ret=MAXVAL,d;
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
            d=dist(b.coords[j].xx,b.coords[j].yy,b.coords[(j+1)%3].xx,b.coords[(j+1)%3].yy,a.coords[i].xx,a.coords[i].yy);
            ret=minim(ret,d);
            d=dist(a.coords[j].xx,a.coords[j].yy,a.coords[(j+1)%3].xx,a.coords[(j+1)%3].yy,b.coords[i].xx,b.coords[i].yy);
            ret=minim(ret,d);
        }
    }
    return ret;
}

void dfs(int nod){
    viz[nod]=true;
    nrnod++;
    for(int i=0;i<G[nod].size();i++){
        if(!viz[G[nod][i]]){
            dfs(G[nod][i]);
        }
    }
}

int update_parent(int nod){
    if(parent[nod]!=nod){
        parent[nod]=update_parent(parent[nod]);
    }
    return parent[nod];
}

void apm(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        nrn[i]=1;
    }
    sort(edge+1,edge+le+1);
    int p1,p2,n1,n2;
    long double ans=0;
    for(int i=1;i<=le;i++){
        n1=edge[i].second.first;
        n2=edge[i].second.second;
        p1=update_parent(n1);
        p2=update_parent(n2);
        if(p1!=p2){
            ans+=edge[i].first;
            if(nrn[p1]<nrn[p2]){
                parent[p1]=p2;
                nrn[p2]+=nrn[p1];
            }else{
                parent[p2]=p1;
                nrn[p1]+=nrn[p2];
            }
        }
    }
    fo<<fixed<<setprecision(5)<<ans<<'\n';
}

int main(){
    fi>>v>>n>>k;
    for(int i=1;i<=n;i++){
        fi>>tr[i].coords[0].xx>>tr[i].coords[0].yy;
        fi>>tr[i].coords[1].xx>>tr[i].coords[1].yy;
        fi>>tr[i].coords[2].xx>>tr[i].coords[2].yy;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            long double d=triangle_dist(tr[i],tr[j]);
            if(d<=(long double)k){
                G[i].push_back(j);
                G[j].push_back(i);
                edge[++le]=make_pair(d,make_pair(i,j));
            }
        }
    }
    if(v==1){
        for(int i=1;i<=n;i++){
            if(!viz[i]){
                nrnod=0;
                dfs(i);
                cnt1+=nrnod-1;
            }
        }
        fo<<cnt1<<'\n';
    }else if(v==2){
        for(int i=1;i<=n;i++){
            if(!viz[i]){
                nrnod=0;
                dfs(i);
                cnt2+=nrnod*(nrnod-1)/2;
            }
        }
        fo<<cnt2<<'\n';
    }else{
        apm();
    }
    fi.close();
    fo.close();
}
