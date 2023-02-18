
#include <bits/stdc++.h>
#define NMAX 63365
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream fi("suma4.in");
ofstream fo("suma4.out");

int n;
int c[NMAX+5],dist[NMAX+5],inq[NMAX+5],prec[NMAX+5],lev[NMAX+5];

struct crit{
    bool operator()(int x,int y){
        return dist[x]>dist[y];
    }
};
priority_queue <int,vector<int>,crit> q;

void walk(int x){
    int a=lev[x]*(lev[x]+1)*(2*lev[x]+1)/6;
    if(a==n){
        return;
    }
    int b=1LL*(lev[x]-1)*lev[x]*(2*lev[x]-1)/6;
    int i=(x-b+lev[x]-1)/lev[x];
    int j=x-b-(i-1)*lev[x];
    int v[4]={a+(i-1)*(lev[x]+1)+j,a+(i-1)*(lev[x]+1)+j+1,a+i*(lev[x]+1)+j,a+i*(lev[x]+1)+j+1};
    for(int i=0;i<4;i++){
        if(dist[v[i]]>dist[x]+c[v[i]]||(dist[v[i]]==dist[x]+c[v[i]]&&x<prec[v[i]])){
            dist[v[i]]=dist[x]+c[v[i]];
            prec[v[i]]=x;
            lev[v[i]]=lev[x]+1;
            if(!inq[v[i]]){
                inq[v[i]]=1;
                q.push(v[i]);
            }
        }
    }
}

void dijkstra(){
    q.push(1);
    inq[1]=1;
    lev[1]=1;
    int x;
    while(!q.empty()){
        x=q.top();
        q.pop();
        inq[x]=0;
        walk(x);
    }
}

void read(){
    fi>>n;
    for(int i=1;i<=n;i++){
        fi>>c[i];
        dist[i]=MAXVAL;
    }
    dist[1]=c[1];
}

void print_path(int x){
    if(prec[x]){
        print_path(prec[x]);
    }
    fo<<x<<' ';
}

void solve(){
    dijkstra();
    int m=lev[n];
    fo<<m<<' ';
    int min=MAXVAL,xmin;
    for(int i=n;i>=n-lev[n]*lev[n]+1;i--){
        if(min>=dist[i]){
            min=dist[i];
            xmin=i;
        }
    }
    fo<<min<<'\n';
    print_path(xmin);
}

int main(){
    read();
    solve();
    fi.close();
    fo.close();
}