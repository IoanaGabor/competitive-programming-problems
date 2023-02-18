
#include <bits/stdc++.h>
#define NMAX 700
#define VALMAX 2000
#define MOD 30103

using namespace std;

ifstream fi("evantai.in");
ofstream fo("evantai.out");

int n;
int sir[NMAX+5];
int aib[NMAX+5][VALMAX+5];
int dp[NMAX+5][NMAX+5];

void update_aib(int x,int y,int val){
    for(int i=x;i<=n;i+=(i^((i-1)&i))){
        for(int j=y;j<=VALMAX;j+=(j^((j-1)&j))){
            aib[i][j]+=val;
        }
    }
}

int query_aib(int x,int y){
    int ret=0;
    for(int i=x;i>0;i-=(i^((i-1)&i))){
        for(int j=y;j>0;j-=(j^((j-1)&j))){
            ret=(ret+aib[i][j])%MOD;
        }
    }   
    return ret;
}

int solve(){
    int ret=0;
    for(int i=n;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            dp[i][j]=1+query_aib(j-1,sir[i]+sir[j]-1);
            ret=(ret+dp[i][j])%MOD;
        }
        for(int j=i+1;j<=n;j++){
            update_aib(j,sir[i]+sir[j],dp[i][j]);
        }
    }
    return ret;
}

int main(){
    fi>>n;
    for(int i=1;i<=n;i++){
        fi>>sir[i];
    }
    fo<<solve();
    fi.close();
    fo.close();
}