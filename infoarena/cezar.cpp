#include <bits/stdc++.h>
#define NMAX 10000

using namespace std;

ifstream f("cezar.in");
ofstream g("cezar.out");

int n,k,x,y,tot,rez;
vector <int> G[NMAX+5];
int grad[NMAX+5], val[NMAX+5],inq[NMAX+5];
struct crit{
    bool operator()(int a,int b){
        return val[a]>val[b];
    }
};
priority_queue <int,vector<int>,crit> q;

int main(){
    f>>n>>k;
    for(int i=1;i<n;i++){
        f>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        grad[x]++;
        grad[y]++;
    }
    for(int i=1;i<=n;i++){
        if(grad[i]==1){
            q.push(i);
            inq[i]=1;
        }
        val[i]=1;
    }
    for(int i=1;i<=n-k-1;i++){
        x=q.top();
        q.pop();
        inq[x]=-1;
        for(int j=0;j<G[x].size();j++){
            if(inq[G[x][j]]==0){
                val[G[x][j]]+=val[x];
                grad[G[x][j]]--;
                if(grad[G[x][j]]==1){
                    q.push(G[x][j]);
                    inq[G[x][j]]=1;
                }
            }
        }

    }
    for(int i=1;i<=n;i++){
        if(inq[i]==-1){
            rez+=val[i];
        }
    }
    g<<rez<<'\n';
    f.close();
    g.close();
    return 0;
}



































