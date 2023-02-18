
#include <bits/stdc++.h>
#define NMAX 200000

using namespace std;

ifstream fi("calafat.in");
ofstream fo("calafat.out");

int n,m;
int sir[NMAX+5];
int last[NMAX+5];
long long ARB[4*NMAX+5];
long long sol[NMAX+5];
vector<pair<int,int>> que[NMAX+5];
int a,b;

void update(int nod,int st,int dr,int x,int val){
    if(st==dr){
        ARB[nod]+=1LL*val;
        return;
    }
    int mij=(st+dr)/2;
    if(x<=mij){
        update(2*nod,st,mij,x,val);
    }else{
        update(2*nod+1,mij+1,dr,x,val);
    }
    ARB[nod]=ARB[2*nod]+ARB[2*nod+1];
}

void query(int nod,int st,int dr,int le,int ri,long long &ret){
    if(le<=st&&dr<=ri){
        ret+=1LL*ARB[nod];
        return;
    }
    int mij=(st+dr)/2;
    if(le<=mij){
        query(nod*2,st,mij,le,ri,ret);
    }
    if(mij<ri){
        query(nod*2+1,mij+1,dr,le,ri,ret);
    }
}

int main(){
    fi>>n>>m;
    for(int i=1;i<=n;i++){
        fi>>sir[i];
    }
    for(int i=1;i<=m;i++){
        fi>>a>>b;
        que[b].push_back(make_pair(a,i));
    }
    for(int i=1;i<=n;i++){
        if(last[sir[i]]!=0){
            update(1,1,n,last[sir[i]],i-last[sir[i]]);
        }
        last[sir[i]]=i;
        for(int j=0;j<que[i].size();j++){
            query(1,1,n,que[i][j].first,i,sol[que[i][j].second]);
        }
    }
    for(int i=1;i<=m;i++){
        fo<<sol[i]<<'\n';
    }
    fi.close();
    fo.close();
}