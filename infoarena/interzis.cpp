
#include <iostream>
#include <fstream>
#define MOD 101267
#define NMAX 15000
#define LMAX 1000

using namespace std;

ifstream f("interzis.in");
ofstream g("interzis.out");

int n,l,pi[LMAX+5],poz[LMAX+5],dp[2][LMAX+5],ind,rez;
char sir[LMAX+5];

void calc_pi(){
    int k=0;
    for(int i=2;i<=l;i++){
        while(k!=0&&sir[k+1]!=sir[i]){
            k=pi[k];
        }
        if(sir[k+1]==sir[i]){
            k++;
        }
        pi[i]=k;
    }
}

void calc_poz(int ll){
    int k=0;
    char ch;
    for(int i=1;i<=ll;i++){
        ch=sir[i];
        if(i==ll){
            ch='a'+'b'-ch;
        }
        while(k!=0&&sir[k+1]!=ch){
            k=pi[k];
        }
        if(sir[k+1]==ch){
            k++;
        }
    }
    poz[ll]=k;
}

int main(){
    f>>n>>l;
    f>>(sir+1);
    sir[l+1]='a';
    sir[l+2]=0;
    calc_pi();
    for(int i=1;i<=l+1;i++){
        calc_poz(i);
    }
    dp[1][0]=dp[1][1]=1;
    for(int i=1;i<n;i++){
        ind=i%2;
        for(int j=0;j<=l;j++){
            dp[1-ind][j]=0;
        }
        for(int j=0;j<l;j++){
            dp[1-ind][j+1]=(dp[1-ind][j+1]+dp[ind][j])%MOD;
            dp[1-ind][poz[j+1]]=(dp[1-ind][poz[j+1]]+dp[ind][j])%MOD;
        }
    }
    for(int j=0;j<l;j++){
        rez=(rez+dp[n%2][j])%MOD;
    }
    g<<rez;
    f.close();
    g.close();
}

