#include <bits/stdc++.h>
#define NMAX 10000

using namespace std;

ifstream fi("biperm.in");
ofstream fo("biperm.out");

int n,p[3][NMAX+5],rez[3][NMAX+5],cntnod,cntinv,cnttotinv,cntbip=1,ind;
bool viz[NMAX+5];
vector<int> G[2*NMAX+5];
pair<int,int> poz[NMAX+5][2];

int get_nod(int i,int j){
    return i*2+j;
}

int get_ind(int nod){
    return nod/2;
}

void init(){
    fi>>n;
    for(int j=1;j<=2;j++){
        for(int i=1;i<=n;i++){
            fi>>p[j][i];
            if(poz[p[j][i]][1].first){
                poz[p[j][i]][2].first=i;
                poz[p[j][i]][2].second=j;
            }else{
                poz[p[j][i]][1].first=i;
                poz[p[j][i]][1].second=j;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(poz[i][1].second==poz[i][2].second){
            G[get_nod(poz[i][1].first,0)].push_back(get_nod(poz[i][2].first,1));
            G[get_nod(poz[i][1].first,1)].push_back(get_nod(poz[i][2].first,0));
            G[get_nod(poz[i][2].first,0)].push_back(get_nod(poz[i][1].first,1));
            G[get_nod(poz[i][2].first,1)].push_back(get_nod(poz[i][1].first,0));
        }else{
            G[get_nod(poz[i][1].first,0)].push_back(get_nod(poz[i][2].first,0));
            G[get_nod(poz[i][1].first,1)].push_back(get_nod(poz[i][2].first,1));
            G[get_nod(poz[i][2].first,0)].push_back(get_nod(poz[i][1].first,0));
            G[get_nod(poz[i][2].first,1)].push_back(get_nod(poz[i][1].first,1));
        }
    }
}

void dfs(int nod){
    ind=get_ind(nod);
    viz[ind]=1;
    cntnod++;
    if(nod%2==1){
        cntinv++;
        rez[1][ind]=p[2][ind];
        rez[2][ind]=p[1][ind];
    }else{
        rez[1][ind]=p[1][ind];
        rez[2][ind]=p[2][ind];
    }
    for(int i=0;i<G[nod].size();i++){
        if(!viz[get_ind(G[nod][i])]){
            dfs(G[nod][i]);
        }
    }
}

int main(){
    init();
    for(int i=1;i<=n;i++){
        if(!viz[i]){
            cntnod=cntinv=0;
            dfs(get_nod(i,0));
            cnttotinv+=min(cntinv,cntnod-cntinv);
            if(p[1][i]!=p[2][i]){
                cntbip*=2;
            }
        }
    }
    fo<<cntbip<<' '<<cnttotinv<<'\n';
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
            fo<<rez[i][j]<<' ';
        }
        fo<<'\n';
    }
    fi.close();
    fo.close();
}
