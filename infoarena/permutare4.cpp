
#include <bits/stdc++.h>
#define NMAX 1000
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream fi("permutare4.in");
ofstream fo("permutare4.out");

int t,n,perm[3][NMAX+5],aux[2*NMAX+5],poz,a,b;
int dp[NMAX+5][NMAX+5];

int main(){
    for(int i=0;i<=NMAX;i++){
        dp[i][0]=1;
        for(int j=1;j<=i;j++){
            if(MAXVAL-dp[i-1][j]<dp[i][j-1]){
                dp[i][j]=MAXVAL;
            }else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
            //fo<<dp[i][j]<<' ';
        }
        //fo<<'\n';
    }
    while(fi>>t){
        if(t==1){
            fi>>n>>poz;
            a=n,b=n;
            perm[1][0]=perm[2][0]=0;
            for(int i=1;i<=2*n;i++){
                if(dp[a][b-1]>=poz){
                    perm[1][++perm[1][0]]=i;
                    b--;
                }else{
                    perm[2][++perm[2][0]]=i;
                    poz-=dp[a][b-1];
                    a--;
                }
            }
            for(int i=1;i<=2;i++){
                for(int j=1;j<=n;j++){
                    fo<<perm[i][j]<<' ';
                }
            }
            fo<<'\n';
        }else{
            fi>>n;
            for(int i=1;i<=2;i++){
                for(int j=1;j<=n;j++){
                    fi>>perm[i][j];
                    aux[perm[i][j]]=i-1;
                }
            }
            a=n,b=n-1;
            poz=1;
            for(int i=2;i<=2*n-1;i++){
                if(aux[i]){
                    if(a){
                        poz+=dp[a][b-1];
                        a--; 
                    }
                }else{
                    b--;
                }
            }
            fo<<poz<<'\n';
        }
    }
    fi.close();
    fo.close();
}