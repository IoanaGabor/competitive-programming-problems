
#include <bits/stdc++.h>
#define NMAX 4000
#define MOD 1000000007

using namespace std;

ifstream fi("countperm.in");
ofstream fo("countperm.out");

int n,p[NMAX+5];
int dp[NMAX+5][NMAX+5];
int sol;
int aux;

int main(){
    fi>>n;
    for(int i=1;i<=n;i++){
        fi>>p[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            dp[i][p[j]]++;
        }
        for(int j=n-1;j>=1;j--){
            dp[i][j]+=dp[i][j+1];
        }
        /*for(int j=1;j<=n;j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';*/
    }
    for(int a=1;a<=n-3;a++){
        /*if(p[a+1]>p[a]&&p[a+2]<p[a]){
            aux=dp[a+3][p[a]+1]-dp[a+3][p[a+1]];
        }else{
            aux=0;
        }*/
        aux=0;
        sol=(sol+aux)%MOD;
        for(int j=a+2;j<=n-1;j++){
            if(p[j-1]>p[a]){
                aux=(aux+(dp[j+1][p[a]+1]-dp[j+1][p[j-1]])+MOD)%MOD;
            }
            if(p[j]>p[a]){
                aux=(aux-(dp[a+1][p[j]+1]-dp[j-1][p[j]+1])+MOD)%MOD;
            }
            if(p[j]<p[a]){
                sol=(sol+aux)%MOD;
            }
        }
    }
    fo<<sol<<'\n';
    fi.close();
    fo.close();
}
