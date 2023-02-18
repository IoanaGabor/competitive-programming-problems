#include <bits/stdc++.h>
#define NMAX 31200

using namespace std;

ifstream fi("ninjago.in");
ofstream fo("ninjago.out");

int t,n,m,x,y,c,cnt1,comp,cnte;
long long cost_tot;
vector<pair<int,int>> G[NMAX+5];
queue<int> q;
bool inq[NMAX+5];
char cod[5];
pair<int,pair<int,int> > edges[NMAX+5];
int nre[NMAX+5],cost[NMAX+5];
int parent[NMAX+5],nrnod[NMAX+5];

int decod(int ind){
    int p=1,ret=0,ok=0;
    for(int i=0;i<4;i++){
        if(cod[i]=='E'){
            ok=1;
            nre[ind]++;
        }else{
            ret+=p*(cod[i]-'A'+1);
        }
        p*=5;
    }
    cost[ind]=ret;
    if(ok){
        return -ret;
    }
    return ret;
}

void bfs(int start){
    q.push(start);
    inq[start]=1;
    int nod;
    while(!q.empty()){
        nod=q.front();
        q.pop();
        cnt1++;
        for(int i=0;i<G[nod].size();i++){
            if(!inq[G[nod][i].first]&&G[nod][i].second>0){
                inq[G[nod][i].first]=1;
                q.push(G[nod][i].first);
            }
        }
    }
}

bool crit(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
    if(nre[a.first]==nre[b.first]){
        return cost[a.first]<cost[b.first];
    }
    return nre[a.first]<nre[b.first];
}

int get_parent(int nod){
    if(parent[nod]!=nod){
        parent[nod]=get_parent(parent[nod]);
    }
    return parent[nod];
}

void apm(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        nrnod[i]=1;
    }
    sort(edges+1,edges+m+1,crit);
    int p1,p2,nrm=0;
    for(int i=1;i<=m&&nrm<n-1;i++){
        p1=get_parent(edges[i].second.first);
        p2=get_parent(edges[i].second.second);
        if(p1!=p2){
            nrm++;
            cnte+=nre[edges[i].first];
            cost_tot+=cost[edges[i].first];
            if(nrnod[p1]<nrnod[p2]){
                nrnod[p2]+=nrnod[p1];
                parent[p1]=p2;
            }else{
                nrnod[p1]+=nrnod[p2];
                parent[p2]=p1;
            }
        }
    }
}

int main(){
    fi>>t>>n>>m;
    for(int i=1;i<=m;i++){
        fi>>x>>y>>cod;
        edges[i]=make_pair(i,make_pair(x,y));
        c=decod(i);
        G[x].push_back(make_pair(y,c));
        G[y].push_back(make_pair(x,c));
    }
    if(t==1){
        bfs(1);
        fo<<cnt1;
    }else{
        for(int i=1;i<=n;i++){
            if(!inq[i]){
                comp++;
                bfs(i);
            }
        }
        apm();
        if(t==2){
            fo<<comp-1<<'\n'<<cnte<<'\n';
        }else{
            fo<<cost_tot<<'\n';
        }
    }
    fi.close();
    fo.close();
}