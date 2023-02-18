/// i forgot to reset G


#include <bits/stdc++.h>
#define NMAX 15000

using namespace std;

ifstream fi("easygraph.in");
ofstream fo("easygraph.out");

vector<int> G[NMAX+1];
int tests;
int n,m;
long long dp[NMAX+1];
int v[NMAX+1];
int degree[NMAX+1];
queue<int> q;

void read_test(){
    fi>>n>>m;
    for(int i=1;i<=n;i++){
        fi>>v[i];
        degree[i]=0;
        dp[i]=v[i];
        G[i].clear();
    }
    int x,y;
    for(int i=1;i<=m;i++){
        fi>>x>>y;
        G[y].push_back(x);
        degree[x]++;
    }
}

long long solve_test(){
    long long maximum = v[1];
    for(int i=1;i<=n;i++){
        if(degree[i]==0){
            q.push(i);
        }
    }
    int node;
    while(!q.empty()){
        node = q.front();
        q.pop();
        maximum = max(maximum, dp[node]);
        for(auto par: G[node]){
            if(dp[par]<dp[node]+v[par]){
                dp[par] = dp[node] + v[par];
            }
            degree[par]--;
            if(degree[par]==0){
                q.push(par);
            }
        }
    }
    return maximum;   
}

int main(){
    fi>>tests;
    while(tests--){
        read_test();
        fo<<solve_test()<<'\n';
    }
}