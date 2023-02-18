
#include <bits/stdc++.h>
#define NMAX 300000

using namespace std;

ifstream fi("arbvalmax.in");
ofstream fo("arbvalmax.out");

int n,m;
int parent[NMAX+5];
int val[NMAX+5];
vector<int> ARB[NMAX+5];
int maxfaralant[NMAX+5],maxsubarb[NMAX+5];
int maxsubarb2[NMAX+5],maxlant[NMAX+5];
int dr[NMAX+5],st,l;
int sus[NMAX+5];
int x,y;

void subarb(int nod){
    maxsubarb[nod]=val[nod];
    for(int i=0;i<ARB[nod].size();i++){
        subarb(ARB[nod][i]);
        maxsubarb[nod]=max(maxsubarb[nod],maxsubarb[ARB[nod][i]]);
        maxsubarb2[nod]=max(maxsubarb2[nod],maxsubarb[ARB[nod][i]]);
    }
}

void faralant(int nod){
    l=ARB[nod].size();
    dr[l]=0;
    for(int i=ARB[nod].size()-2;i>=0;i--){
        dr[i+1]=max(dr[i+2],maxsubarb[ARB[nod][i+1]]);
    }
    st=0;
    for(int i=0;i<ARB[nod].size();i++){
        sus[ARB[nod][i]]=max(sus[nod],max(st,dr[i+1]));
        maxfaralant[ARB[nod][i]]=max(maxsubarb2[ARB[nod][i]],sus[ARB[nod][i]]);
        st=max(st,maxsubarb[ARB[nod][i]]);
    }
    for(int i=0;i<ARB[nod].size();i++){
        faralant(ARB[nod][i]);
    }    
}

void lant(int nod){
    maxlant[nod]=max(maxlant[parent[nod]],val[nod]);
    for(int i=0;i<ARB[nod].size();i++){
        lant(ARB[nod][i]);
    }
}

int main(){
    fi>>n>>m;
    for(int i=2;i<=n;i++){
        fi>>parent[i];
        ARB[parent[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        fi>>val[i];
    }
    subarb(1);
    maxfaralant[1]=maxsubarb2[1];
    faralant(1);
    lant(1);
    for(int i=1;i<=m;i++){
        fi>>x>>y;
        fo<<max(maxfaralant[y],maxlant[parent[x]])<<'\n';
    }
    fi.close();
    fo.close();
}