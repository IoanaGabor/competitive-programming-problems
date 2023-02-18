
#include <iostream>
#include <fstream>
#include <vector>
#define NMAX 1000

using namespace std;

ifstream f("fantasy.in");
ofstream g("fantasy.out");

int t,n,d,c,v,x,y,timp[3][NMAX+5],par[3][NMAX+5],ok;
vector <int> ADJ[NMAX+5];

void dfs(int start,int care,int parinte){
    par[care][start]=parinte;
    timp[care][start]=timp[care][parinte]+1;
    for(int i=0;i<ADJ[start].size();i++){
        if(ADJ[start][i]!=parinte){
            dfs(ADJ[start][i],care,start);
        }
    }
}

int main(){
    f>>t;
    while(t--){
        f>>n>>d>>c>>v;
        for(int i=1;i<=n-1;i++){
            f>>x>>y;
            ADJ[x].push_back(y);
            ADJ[y].push_back(x);
        }
        dfs(d,0,0);
        dfs(c,1,0);
        dfs(v,2,0);
        ok=0;
        for(int i=1;i<=n;i++){
            if(par[0][i]==par[1][i]&&timp[2][i]<timp[0][i]&&timp[1][i]<=timp[0][i]&&timp[2][i]<timp[1][i]){
                ok=1;
            }
            par[0][i]=par[1][i]=par[2][i]=timp[0][i]=timp[1][i]=timp[2][i]=0;
        }
        if(ok==1){
            g<<"DA"<<'\n';
        }else{
            g<<"NU"<<'\n';
        }
        for(int i=1;i<=n;i++){
            ADJ[i].clear();
        }
    }
    f.close();
    g.close();
}
