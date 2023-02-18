
#include <bits/stdc++.h>
#define NMAX 100

using namespace std;

ifstream fi("palin3.in");
ofstream fo("palin3.out");

int t,n;
char sir[NMAX+5];
int dp[NMAX+5][NMAX+5];

int main(){
    fi>>t;
    while(t--){
        fi>>(sir+1);
        n=strlen(sir+1);
        if(n%3!=0){
            fo<<"NU"<<'\n';
        }else{
            for(int i=1;i<=n;i++){
                for(int j=i;j<=n;j++){
                    dp[i][j]=0;
                }
            }
            for(int i=1;i<=n-2;i++){
                if(sir[i]==sir[i+2]){
                    dp[i][i+2]=1;
                }
            }
            for(int l=6;l<=n;l+=3){
                for(int i=1;i+l-1<=n;i++){
                    for(int k=i+3;k<=i+l-1;k+=3){
                        if(dp[i][k-1]&&dp[k][i+l-1]){
                            dp[i][i+l-1]=1;
                            break;
                        }
                    }
                    if(!dp[i][i+l-1]&&sir[i]==sir[i+l-1]){
                        for(int k=i+1;k<=i+l-2;k++){
                            if((i+1>k-1||(i+1<=k-1&&dp[i+1][k-1]))&&(k+1>i+l-2||(k+1<=i+l-2&&dp[k+1][i+l-2]))){
                                dp[i][i+l-1]=1;
                                break;
                            }
                        }   
                    }
                }
            }
            if(dp[1][n]){
                fo<<"DA"<<'\n';
            }else{
                fo<<"NU"<<'\n';
            }
        }
    }
    fi.close();
    fo.close();
}