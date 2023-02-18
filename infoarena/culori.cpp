
#include <bits/stdc++.h>
#define NMAX 511
#define MOD 9901

using namespace std;

ifstream fi("culori.in");
ofstream fo("culori.out");

int n,l,j;
int c[NMAX+5];
int dp[NMAX+5][NMAX+5];

int main(){
    fi>>n;
    l=2*n-1;
    for(int i=1;i<=2*n-1;i++){
        fi>>c[i];
        dp[i][i]=1;
    }
    for(int d=2;d<l;d+=2){
        for(int i=1;i+d<=l;i++){
            j=i+d;
            if(c[i]!=c[j]){
                dp[i][j]=0;
            }else{
                for(int p=i+2;p<=j;p+=2){
                    if(c[i]==c[p]){
                        dp[i][j]+=dp[i+1][p-1]*dp[p][j];
                        dp[i][j]%=MOD;
                    }
                }
            }
        }
    }
    fo<<dp[1][l];
    fi.close();
    fo.close();
}