#include <bits/stdc++.h>
#define NMAX 100000
#define TMAX 10

using namespace std;

ifstream fi("arbxyz.in");
ofstream fo("arbxyz.out");

int t,n,x,y,z;
int v,w;
vector<int> arb[NMAX+5];
int dim[NMAX+5];
int isx[NMAX+5],isy[NMAX+5],isz[NMAX+5];
int ans;

void dfs(int nod,int par){
    if(ans){
        return;
    }
    dim[nod]=1;
    for(auto& chd:arb[nod]){
        if(chd!=par){
            dfs(chd,nod);
            dim[nod]+=dim[chd];
            if(isx[nod]&&(isy[chd]||isz[chd])){
                ans=1;
            }
            if(isy[nod]&&(isx[chd]||isz[chd])){
                ans=1;
            }
            if(isz[nod]&&(isy[chd]||isx[chd])){
                ans=1;
            }
            isx[nod]=isx[nod]|isx[chd];
            isy[nod]=isy[nod]|isy[chd];
            isz[nod]=isz[nod]|isz[chd];
        }
    }
    if(dim[nod]==x+y&&(isx[nod]||isy[nod])){
        ans=1;
    }
    if(dim[nod]==x+z&&(isx[nod]||isz[nod])){
        ans=1;
    }
    if(dim[nod]==z+y&&(isz[nod]||isy[nod])){
        ans=1;
    }
    isx[nod]=isx[nod]|(dim[nod]==x);
    isy[nod]=isy[nod]|(dim[nod]==y);
    isz[nod]=isz[nod]|(dim[nod]==z);
}

void reset(){
    for(int i=1;i<=n;i++){
        arb[i].clear();
        dim[i]=0;
        isx[i]=isy[i]=isz[i]=0;
    }
    ans=0;
}

int main(){
    fi>>t;
    while(t--){
        fi>>n>>x>>y>>z;
        for(int i=1;i<n;i++){
            fi>>v>>w;
            arb[v].push_back(w);
            arb[w].push_back(v);
        }
        dfs(1,0);
        fo<<ans<<'\n';
        reset();
    }
    
    fi.close();
    fo.close();
}