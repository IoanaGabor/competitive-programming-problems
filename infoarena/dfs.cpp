
#include <iostream>
#include <fstream>
#include <vector>
#define NMAX 100000

using namespace std;

ifstream f("dfs.in");
ofstream g("dfs.out");

vector <int> adj[NMAX+5];
int n,m,x,y,viz[NMAX+5],cnt;

void dfs(int nod){
    viz[nod]=1;
    int l=adj[nod].size();
    for(int i=0;i<l;i++){
        if(!viz[adj[nod][i]]){
            dfs(adj[nod][i]);
        }
    }
}

int main(){
    f>>n>>m;
    for(int i=1;i<=m;i++){
        f>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!viz[i]){
            cnt++;
            dfs(i);
        }
    }
    g<<cnt;
    f.close();
    g.close();
}
