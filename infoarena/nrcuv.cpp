
#include <iostream>
#include <fstream>
#define NMAX 1000
#define MOD 104659

using namespace std;

ifstream f("nrcuv.in");
ofstream g("nrcuv.out");

int n,m,vecine[30][30],dp[NMAX+5][30],rez;
char ch1,ch2;

int main(){
    f>>n>>m;
    for(int i=1;i<=m;i++){
        f>>ch1>>ch2;
        vecine[ch1-'a'][ch2-'a']=1;
        vecine[ch2-'a'][ch1-'a']=1;
    }
    for(int i=0;i<='z'-'a';i++){
        dp[1][i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int ii=0;ii<='z'-'a';ii++){
            for(int jj=0;jj<='z'-'a';jj++){
                if(!vecine[ii][jj]){
                    dp[i][jj]=(dp[i][jj]+dp[i-1][ii])%MOD;
                }
            }
        }
    }
    for(int i=0;i<='z'-'a';i++){
        rez=(rez+dp[n][i])%MOD;
    }
    g<<rez;
    f.close();
    g.close();
}
