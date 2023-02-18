
///atentie la cum afisez Da si Nu
///si am gresit la dinamica 
#include <bits/stdc++.h>
#define NMAX 100000

using namespace std;

ifstream fi("pang.in");
ofstream fo("pang.out");

int t,n,m,k,x,y;
vector<int> G[NMAX+5];
int sp[NMAX+5];
int cnt[NMAX+5];
int pred[NMAX+5];
int grad[NMAX+5];
queue<int> q;

void init(){
    for(int i=1;i<=n;i++){
        sp[i]=cnt[i]=pred[i]=grad[i]=0;
        G[i].clear();
    }
}

void sortare_topologica(){
    while(!q.empty()){
        x=q.front();
        q.pop();
        for(int i=0;i<G[x].size();i++){
            y=G[x][i];
            grad[y]--;
            if(cnt[y]<cnt[x]){
                pred[y]=x;
                cnt[y]=cnt[x];
            }
            if(grad[y]==0){
                cnt[y]+=sp[y];
                q.push(y);
            }
        }
    }
}

int ok(){
    for(int i=1;i<=n;i++){
        if(cnt[i]==k){
            return i;
        }
    }
    return 0;
}

void afis(int val){
    if(pred[val]){
        afis(pred[val]);
    }
    if(sp[val]){
        fo<<val<<' ';
    }
}

int main(){
    fi>>t;
    while(t--){
        fi>>n>>m>>k;
        init();
        for(int i=1;i<=m;i++){
            fi>>x>>y;
            G[x].push_back(y);
            grad[y]++;
        }
        for(int i=1;i<=k;i++){
            fi>>x;
            sp[x]=1;
        }
        for(int i=1;i<=n;i++){
            if(grad[i]==0){
                cnt[i]=sp[i];
                q.push(i);
            }
        }
        sortare_topologica();
        x=ok();
        if(x){
            fo<<"Da"<<'\n';
            afis(x);
            fo<<'\n';
        }else{
            fo<<"Nu"<<'\n';
        }
    }
    fi.close();
    fo.close();
}