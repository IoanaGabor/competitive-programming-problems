
#include <iostream>
#include <fstream>
#include <cstring>
#define NMAX 100

using namespace std;

ifstream f("randuri.in");
ofstream g("randuri.out");

char linii[NMAX+5][NMAX+5];
int n,lung[NMAX+5][NMAX+5],muzica[NMAX+5][NMAX+5],dp[NMAX+5][NMAX+5];

bool muzicalitate(char a[NMAX+5],char b[NMAX+5]){
    int na,nb;
    na=strlen(a);
    nb=strlen(b);
    for(int i=0;i<na;i++){
        for(int j=0;j<nb;j++){
            lung[i][j]=0;
        }
    }
    for(int i=0;i<na;i++){
        for(int j=0;j<nb;j++){
            if(a[i]==b[j]){
                lung[i+1][j+1]=lung[i][j]+1;
            }else{
                lung[i+1][j+1]=max(lung[i+1][j],lung[i][j+1]);
            }
        }
    }
    if(lung[na][nb]>6){
        return true;
    }
    return false;
}

int main(){
    while(f.getline(linii[++n],100));
    n--;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(muzicalitate(linii[i],linii[j])){
                muzica[i][j]=muzica[j][i]=1;
            }
        }
    }
    for(int i=1;i<=n-2;i++){
        if(muzica[i][i+2]){
            dp[i][i+2]=1;
        }
    }
    for(int l=4;l<=n;l++){
        for(int i=1;i+l-1<=n;i++){
            int j=i+l-1;
            for(int k=i+1;k<j;k++){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]);
                if(dp[i][k]==k-i-1&&dp[k][j]==j-k-1&&muzica[i][j]){
                    dp[i][j]=j-i-1;
                }
            }
        }
    }
    g<<dp[1][n];
}
