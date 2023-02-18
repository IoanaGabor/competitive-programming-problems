#include <bits/stdc++.h>
#define NMAX 100000

using namespace std;

ifstream fi("heavypath.in");
ofstream fo("heavypath.out");

int n,m,t,x,y;
vector<int> G[NMAX+5],P[NMAX+5];
int ARB[4*NMAX+4];
int val[NMAX+5];
int subarb[NMAX+5];
int niv[NMAX+5];
int par[NMAX+5];
int lant[NMAX+5],ldim[NMAX+5];
int lpar[NMAX+5],lniv[NMAX+5];
int lpoz[NMAX+5];
int nrlant;

void citire(){
    fi>>n>>m;
    for(int i=1;i<=n;i++){
        fi>>val[i];
    }
    for(int i=1;i<n;i++){
        fi>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }    
}

void df(int nod,int parent){
    int ln=-1;
    subarb[nod]=1;
    for(auto y: G[nod]){
        if(y!=parent){
            niv[y]=niv[nod]+1;
            df(y,nod);
            subarb[nod]+=subarb[y];
            if(ln==-1){
                ln=y;
            }else if(subarb[ln]<subarb[y]){
                ln=y;
            }
        }
    }
    if(G[nod].size()==1&&G[nod][0]==parent){
        lant[nod]=++nrlant;
        P[nrlant].push_back(nod);
        ldim[nrlant]=1;
        return;
    }
    lant[nod]=lant[ln];
    P[lant[nod]].push_back(nod);
    ldim[lant[nod]]++;
    for(auto y:G[nod]){
        if(y!=parent&&y!=ln){
            lpar[lant[y]]=nod;
            lniv[lant[y]]=niv[nod];
        }
    }
}

void build(int nod,int l,int r,int decalaj,int lant){
    if(l==r){
        ARB[nod+decalaj]=val[P[lant][l-1]];
        return;
    }
    int mij=(l+r)/2;
    build(2*nod,l,mij,decalaj,lant);
    build(2*nod+1,mij+1,r,decalaj,lant);
    ARB[nod+decalaj]=max(ARB[2*nod+decalaj],ARB[2*nod+1+decalaj]);
}

void make_paths(){
    niv[1]=1;
    df(1,0);
    for(int i=1;i<=nrlant;i++){
        reverse(P[i].begin(),P[i].end());
        lpoz[i]=lpoz[i-1]+4*ldim[i-1];
        build(1,1,ldim[i],lpoz[i],i);
    }
}

void update(int nod,int l,int r,int decalaj,int lant,int poz,int val){
    if(l==r){
        ARB[nod+decalaj]=val;
        return;
    }
    int mij=(l+r)/2;
    if(poz<=mij){
        update(2*nod,l,mij,decalaj,lant,poz,val);
    }else{
        update(2*nod+1,mij+1,r,decalaj,lant,poz,val);
    }
    ARB[nod+decalaj]=max(ARB[2*nod+decalaj],ARB[2*nod+1+decalaj]);
}

void query(int nod,int l,int r,int decalaj,int lant,int st,int dr,int &sol){
    if(st<=l&&r<=dr){
        sol=max(sol,ARB[nod+decalaj]);
        return;
    }
    int mij=(l+r)/2;
    if(st<=mij){
        query(2*nod,l,mij,decalaj,lant,st,dr,sol);
    }
    if(mij<dr){
        query(2*nod+1,mij+1,r,decalaj,lant,st,dr,sol);
    }
}

void solve(){
    int sol;
    while(m--){
        fi>>t>>x>>y;
        if(t==0){
            update(1,1,ldim[lant[x]],lpoz[lant[x]],lant[x],niv[x]-lniv[lant[x]],y);
        }else{
            sol=0;
            while(1){
                if(lant[x]==lant[y]){
                    if(niv[x]>niv[y]){
                        swap(x,y);
                    }
                    query(1,1,ldim[lant[x]],lpoz[lant[x]],lant[x],niv[x]-lniv[lant[x]],niv[y]-lniv[lant[y]],sol);
                    break;
                }else{
                    if(lniv[lant[x]]<lniv[lant[y]]){
                        swap(x,y);
                    }
                    query(1,1,ldim[lant[x]],lpoz[lant[x]],lant[x],1,niv[x]-lniv[lant[x]],sol);    
                    x=lpar[lant[x]];
                }
            }
            
            fo<<sol<<'\n';
        }
    }
}

int main(){
    citire();
    make_paths();
    solve();
    fi.close();
    fo.close();    
}
