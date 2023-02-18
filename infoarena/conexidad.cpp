
#include <bits/stdc++.h>
#define NMAX 100

using namespace std;

ifstream fi("conexidad.in");
ofstream fo("conexidad.out");

int n,m,x,y,nc;
vector <int> G[NMAX+5];
queue<int> q;
int et[NMAX+5],cnt[NMAX+5];
int extra[NMAX+5],max_extra;
pair<int,int> rez[NMAX+5];
void bfs(int sn){
    q.push(sn);
    int nod;
    while(!q.empty()){
        nod=q.front();
        q.pop();
        if(!et[nod]){
            et[nod]=sn;
            cnt[sn]++;
            for(int i=0;i<G[nod].size();i++){
                if(!et[G[nod][i]]){
                    q.push(G[nod][i]);
                }
            }
        }
    }
}

int parent(int nod){
    if(et[nod]!=nod){
        et[nod]=parent(et[nod]);
    }
    return et[nod];
}

void solve(){
    int p1,p2,newm,mi,mj,cntu;
    for(int k=1;k<nc;k++){
        newm=n;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                p1=parent(i);
                p2=parent(j);
                if(p1!=p2){
                    if(max(extra[i],extra[j])<newm){
                        mi=i;
                        mj=j;
                        newm=max(extra[i],extra[j]);
                        cntu=cnt[p1]+cnt[p2];
                    }else if(max(extra[i],extra[j])==newm&&cntu<cnt[p1]+cnt[p2]){
                        mi=i;
                        mj=j;
                        cntu=cnt[p1]+cnt[p2];
                    }
                }
            }
        }
        extra[mi]++;
        extra[mj]++;
        rez[k]=make_pair(mi,mj);
        max_extra=max(max_extra,max(extra[mi],extra[mj]));
        p1=parent(mi);
        p2=parent(mj);
        if(cnt[p1]<cnt[p2]){
            et[p1]=p2;
            cnt[p2]+=cnt[p1];
        }else{
            et[p2]=p1;
            cnt[p1]+=cnt[p2];
        }
    }
}

int main(){
    fi>>n>>m;
    for(int i=1;i<=m;i++){
        fi>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!et[i]){
            ++nc;
            bfs(i);
        }
    }
    solve();
    fo<<max_extra<<'\n';
    fo<<nc-1<<'\n';
    for(int i=1;i<nc;i++){
        fo<<rez[i].first<<' '<<rez[i].second<<'\n';
    }
    fi.close();
    fo.close();
}
