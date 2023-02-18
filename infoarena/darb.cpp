#include <iostream>
#include <fstream>
#include <vector>
#define NMAX 100000

using namespace std;

ifstream f("darb.in");
ofstream g("darb.out");

int n,best[NMAX+5],nivel[NMAX+5],x,y;
vector <int> adj[NMAX+5];

void dfs(int nod,int t){
   int m1=0,m2=0;
   nivel[nod]=best[nod]=1;
   for(int i=0;i<adj[nod].size();i++){
      if(adj[nod][i]!=t){
         dfs(adj[nod][i],nod);
         nivel[nod]=max(nivel[nod],nivel[adj[nod][i]]+1);
         best[nod]=max(best[nod],best[adj[nod][i]]);
         if(nivel[adj[nod][i]]>m1){
            m2=m1;
            m1=nivel[adj[nod][i]];
         }else if(nivel[adj[nod][i]]>m2){
            m2=nivel[adj[nod][i]];
         }
      }
   }
   best[nod]=max(best[nod],m1+m2+1);
}

int main()
{
    f>>n;
    for(int i=1;i<=n-1;i++){
        f>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0);
    g<<best[1];
    f.close();
    g.close();
    return 0;
}
