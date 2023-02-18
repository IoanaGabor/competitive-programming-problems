
#include <bits/stdc++.h>
#define NMAX 16000
#define MMAX 100000

using namespace std;

ifstream fi("zoo.in");
ofstream fo("zoo.out");

struct pct{
    int x,y;
} p[NMAX+5];

int n,m,lx;
int xj,xs,yj,ys;
vector<int> arb[4*NMAX+5];
vector<int> cx;
vector<int> px[NMAX+5];
vector<int> acata;

bool cmp_x(pct a,pct b){
    if(a.x==b.x){
        return a.y<b.y;
    }
    return a.x<b.x;
}

bool cmp_y(pct a,pct b){
    if(a.y==b.y){
        return a.x<b.x;
    }
    return a.y<b.y;
}

void build(int nod,int st,int dr){
    if(st>dr){
        return;
    }
    if(st==dr){
        arb[nod]=px[st];
        return;
    }
    int mij=(st+dr)/2;
    build(nod*2,st,mij);
    build(nod*2+1,mij+1,dr);
    arb[nod].resize(arb[2*nod].size()+arb[2*nod+1].size());
    merge(arb[2*nod].begin(),arb[2*nod].end(),arb[2*nod+1].begin(),arb[2*nod+1].end(),arb[nod].begin());
}

int query(int nod,int st,int dr){
    int ret=0;
    if(xj<=st&&dr<=xs){
        ret=upper_bound(arb[nod].begin(),arb[nod].end(),ys)-lower_bound(arb[nod].begin(),arb[nod].end(),yj);
        return ret;
    }
    int mij=(st+dr)/2;
    if(xj<=mij){
        ret+=query(nod*2,st,mij);
    }
    if(mij<xs){
        ret+=query(nod*2+1,mij+1,dr);
    }
    return ret;
}

int main(){
    fi>>n;
    for(int i=1;i<=n;i++){
        fi>>p[i].x>>p[i].y;
    }
    sort(p+1,p+n+1,cmp_x);
    cx.push_back(p[1].x);
    px[1].push_back(p[1].y);
    acata.push_back(1);
    lx=1;
    for(int i=2;i<=n;i++){
        if(p[i].x!=p[i-1].x){
            lx++;
        }
        cx.push_back(p[i].x);
        px[lx].push_back(p[i].y);
        acata.push_back(lx);
    }
    build(1,1,lx);
    fi>>m;
    while(m--){
        fi>>xj>>yj>>xs>>ys;
        int aux1=upper_bound(cx.begin(),cx.end(),xs)-cx.begin();
        if(aux1==0){
            fo<<0<<'\n';
        }else{
            aux1--;
            xs=acata[aux1];
            int aux2=lower_bound(cx.begin(),cx.end(),xj)-cx.begin();
            xj=acata[aux2];
            if(xj>xs){
                fo<<0<<'\n';
            }else{
                fo<<query(1,1,lx)<<'\n';
            }
        }
    }
    fi.close();
    fo.close();
}