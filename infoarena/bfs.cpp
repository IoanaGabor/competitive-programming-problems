
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define NMAX 100000

using namespace std;

ifstream f("bfs.in");
ofstream g("bfs.out");

int n,m,s,x,y;
int rez[NMAX+5],l[NMAX+5];
vector <int> ad[NMAX+5];
queue <int> q;

void bfs(int start){
    for(int i=1;i<=n;i++){
        rez[i]=-1;
    }
    q.push(start);
    rez[start]=0;
    while(!q.empty()){
        x=q.front();
        q.pop();
        for(int i=0;i<l[x];i++){
            if(rez[ad[x][i]]==-1){
                rez[ad[x][i]]=rez[x]+1;
                q.push(ad[x][i]);
            }
        }
    }
}

int main(){
    f>>n>>m>>s;
    for(int i=1;i<=m;i++){
        f>>x>>y;
        ad[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        l[i]=ad[i].size();
    }
    bfs(s);
    for(int i=1;i<=n;i++){
        g<<rez[i]<<' ';
    }
    f.close();
    g.close();
}
