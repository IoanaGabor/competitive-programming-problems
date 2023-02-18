#include <bits/stdc++.h>
#define NMAX 100000
#define MOD 1000000007
#define PMAX 7

using namespace std;

ifstream fi("arbsumpow.in");
ofstream fo("arbsumpow.out");

int n,p,x;
int v[NMAX+5];
vector<int> arb[NMAX+5];
long long sol;
long long dp[NMAX+5][PMAX+5];
long long comb[PMAX+1][PMAX+1];
long long aux[PMAX+5];

void dfs(int nod,int par){
    dp[nod][0]=1;
    for(int i=1;i<=p;i++){
        dp[nod][i]=(dp[nod][i-1]*v[nod])%MOD;
    }
    for(auto c:arb[nod]){
        dfs(c,nod);
        for(int pp=0;pp<=p;pp++){
            aux[pp]=dp[nod][pp];
            for(int j=0;j<=pp;j++){
                aux[pp]=(aux[pp]+comb[pp][j]*dp[nod][j]%MOD*dp[c][pp-j]%MOD)%MOD;
            }
        }    
        for(int pp=0;pp<=p;pp++){
            dp[nod][pp]=aux[pp];
        }
    }
        
}

int main(){
    fi>>n>>p;
    comb[0][0]=1;
    for(int i=1;i<=p;i++){
        comb[i][0]=1;
        for(int j=1;j<=i;j++){
            comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%MOD;
        }
    }

    for(int i=1;i<=n;i++){
        fi>>v[i];
    }
    for(int i=2;i<=n;i++){
        fi>>x;
        arb[x].push_back(i);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        sol=(sol+dp[i][p])%MOD;
    }
    fo<<sol<<'\n';
    fi.close();
    fo.close();
}