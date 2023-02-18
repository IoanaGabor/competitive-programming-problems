#include <bits/stdc++.h>
#define NMAX 500
#define ALPHA 26
#define VALMAX (1LL<<31)-1
 
using namespace std;
 
ifstream fi("redu.in");
ofstream fo("redu.out");
 
int n;
int mat[ALPHA+1][ALPHA+1];
long long dp[NMAX+2][NMAX+2];
char sir[NMAX+5];
 
int main()
{
    fi>>n;
    fi>>(sir+1);
    for(int i=0;i<ALPHA;i++){
        for(int j=0;j<ALPHA;j++){
            fi>>mat[i][j];
        }
    }
    for(int i=1;i<n;i++){
        dp[i][i+1]=mat[sir[i]-'a'][sir[i+1]-'a'];
    }
    for(int d=4;d<=n;d+=2){
        for(int i=1;i+d-1<=n;i++){
            int j=i+d-1;
            dp[i][j]=VALMAX;
            for(int k=i+1;k<=j;k+=2){
                dp[i][j]=min(dp[i+1][k-1]+1LL*mat[sir[i]-'a'][sir[k]-'a']+dp[k+1][j],dp[i][j]);
            }
        }
    }
    fo<<dp[1][n];
    fi.close();
    fo.close();
    return 0;
}