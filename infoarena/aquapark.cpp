#include <bits/stdc++.h>
#define NMAX 70000
#define MMAX 100000
#define MOD 666013

using namespace std;

ifstream fi("aquapark.in");
ofstream fo("aquapark.out");

int c;
int n,m,top;
pair<int,int> edge[MMAX+5];
int st[MMAX+5];
int inst[MMAX+5];
vector <int> madd[NMAX+5],mdelete[NMAX+5];
vector <int> G[2*MMAX+5];
int viz[MMAX+5];
int p;
queue <int> q;

bool intersect(int i,int j){
    pair<int,int> a,b;
    a=edge[i];
    b=edge[j];
    if(a.first>b.first){
        swap(a,b);
    }
    if(a.first<b.first&&b.first<a.second&&a.second<b.second){
        return true;
    }
    return false;
}

int cod(int nod,int et){
    return 2*nod+et;
}

void bfs(int sn){
    q.push(sn);
    int aux;
    viz[sn/2]=sn%2+1;
    while(!q.empty()){
        aux=q.front();
        q.pop();
        for(int i=0;i<G[aux].size();i++){
            if(!viz[G[aux][i]/2]){
                viz[G[aux][i]/2]=G[aux][i]%2+1;
                q.push(G[aux][i]);
            }
        }
    }
}

void read(){
    fi>>c>>n>>m;
    pair<int,int> aux;
    for(int i=1;i<=m;i++){
        fi>>edge[i].first>>edge[i].second;
        aux.first=min(edge[i].first,edge[i].second);
        aux.second=max(edge[i].first,edge[i].second);
        edge[i]=aux;
    }
}

void add_edges(){
    sort(edge+1,edge+m+1);
    for(int i=1;i<=m;i++){
        if(edge[i].first==edge[i-1].first&&edge[i].second==edge[i-1].second){
            viz[i-1]=1;
            viz[i]=2;
            madd[edge[i].first].pop_back();
            mdelete[edge[i].second].pop_back();
        }else{
            madd[edge[i].first].push_back(i);
            mdelete[edge[i].second].push_back(i);
        }
    }
    int x,y,ind,last;
    top=0;
    for(int i=1;i<=n;i++){
        for(int j=mdelete[i].size()-1;j>=0;j--){
            x=edge[mdelete[i][j]].first;
            y=edge[mdelete[i][j]].second;
            ind=mdelete[i][j];
            last=-1;
            while(top&&edge[st[top]].first>x){
                G[cod(st[top],0)].push_back(cod(ind,1));
                G[cod(st[top],1)].push_back(cod(ind,0));
                G[cod(ind,0)].push_back(cod(st[top],1));
                G[cod(ind,1)].push_back(cod(st[top],0));
                last=st[top];
                top--;
            }
            if(top&&st[top]==ind){
                top--;
            }
            if(last!=-1){
                st[++top]=last;
            }
        }
        for(int j=madd[i].size()-1;j>=0;j--){
            st[++top]=madd[i][j];
        }
    }
}

void solve1(){
    for(int i=1;i<=m;i++){
        if(!viz[i]){
            bfs(2*i);
        }
    }
    for(int i=1;i<=m;i++){
        fo<<edge[i].first<<' '<<edge[i].second<<' '<<viz[i]<<'\n';
    }
}

void solve2(){
    p=1;
    for(int i=1;i<=m;i++){
        if(!viz[i]){
            bfs(2*i);
            p=(p*2)%MOD;
        }
    }
    fo<<p<<'\n';
}

int main(){
    read();
    add_edges();
    if(c==1){
        solve1();
    }else{
        solve2();
    }
    fi.close();
    fo.close();
}
