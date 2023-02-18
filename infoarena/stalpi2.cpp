
#include <bits/stdc++.h>
#define NMAX 50
#define DMAX 10000
#define INF 400005

using namespace std;

ifstream fi("stalpi2.in");
ofstream fo("stalpi2.out");

int n,e;
int d[NMAX+5];
int dp[NMAX+5][DMAX+5];
int minim,maxim;
int pozm;
int dq[DMAX+5],st,dr;

bool ok(int dm){
    for(int i=1;i<=n;i++){
        for(int j=0;j<=pozm;j++){
            dp[i][j]=INF;
        }
    }
    dp[1][0]=0;
    for(int i=2;i<=n;i++){
        st=dr=0;
        for(int j=0;j<=pozm;j++){
            while(st!=dr&&dp[i-1][j]<=dp[i-1][dq[dr]]){
                dr--;
            }
            dq[++dr]=j;
            if(st!=dr&&dq[st+1]<j-dm){
                st++;
            }
            dp[i][j]=dp[i-1][dq[st+1]]+abs(d[i]-j);
            if(dp[i][j]>e){
                dp[i][j]=INF;
            }
        }
    }
    if(dp[n][pozm]<=e){
        return true;
    }
    return false;
}

int cauta(){
    int pas=1<<12;
    int rez=minim-1;
    while(pas){
        if(rez+pas<=maxim&&!ok(rez+pas)){
            rez+=pas;
        }
        pas>>=1;
    }
    rez++;
    return rez;
}

int main(){
    fi>>n>>e;
    for(int i=2;i<=n;i++){
        fi>>d[i];
        maxim+=(d[i]-d[i-1]);
    }
    pozm=d[n];
    minim=maxim/(n-1);
    fo<<cauta();
    fi.close();
    fo.close();
}
