#include <iostream>
#include <fstream>
#include <cstring>
#define NMAX 1000000
#define KMAX 20
#define VALMAX (1LL<<31)-1

using namespace std;

ifstream f("palindrom3.in");
ofstream g("palindrom3.out");

int t[10],n,k,trs[10][10],aux,cnt,rez[NMAX+1],rest10[NMAX+1],rest_ant,rest,c1,c2;
char numar[NMAX+1];

struct ceva{
    int val;
    int cifra;
    int res;
};

ceva dp[NMAX/2+5][KMAX];

int cmmcifracomuna(int x,int y){
    for(int i=9;i>=0;i--){
        if(trs[x][i]!=-1&&trs[y][i]!=-1){
            return i;
        }
    }
}

int main(){
    for(int i=0;i<=9;i++){
        f>>t[i];
    }
    f>>numar;
    n=strlen(numar);
    for(int i=n-1;i>=0;i--){
        numar[i+1]=numar[i];
    }
    f>>k;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            trs[i][j]=-1;
        }
        aux=t[i];
        trs[i][i]=cnt=0;
        while(trs[i][aux]==-1){
            trs[i][aux]=++cnt;
            aux=t[aux];
        }
    }
    for(int i=1;i<=n/2;i++){
        rez[i]=rez[n-i+1]=cmmcifracomuna(numar[i]-'0',numar[n-i+1]-'0');
    }
    for(int i=1;i<=n;i++){
        g<<rez[i];
    }
    g<<'\n';
    rest10[0]=1%k;
    for(int i=1;i<=n;i++){
        rest10[i]=rest10[i-1]*10%k;
    }
    for(int i=1;i<=n/2+1;i++){
        for(int j=0;j<=k;j++){
            dp[i][j].val=VALMAX;
        }
    }
    dp[n/2+1][0].val=0;
    for(int i=n/2;i>=1;i--){
        c1=numar[i]-'0';
        c2=numar[n-i+1]-'0';
        for(int p=0;p<=9;p++){
            if((!(i==1&&p==0))&&(trs[c1][p]!=-1&&trs[c2][p]!=-1)){
                rest=(p*rest10[i-1]+p*rest10[n-i])%k;
                for(int re=0;re<k;re++){
                    if(dp[i+1][re].val!=VALMAX){
                        if(dp[i+1][re].val+trs[c1][p]+trs[c2][p]<=dp[i][(re+rest)%k].val){
                            dp[i][(re+rest)%k].val=dp[i+1][re].val+trs[c1][p]+trs[c2][p];
                            dp[i][(re+rest)%k].res=re;
                            dp[i][(re+rest)%k].cifra=p;
                        }
                    }
                }
            }
        }
    }
    rest=0;
    for(int i=1;i<=n/2;i++){
        rez[i]=dp[i][rest].cifra;
        rest=dp[i][rest].res;
    }
    for(int i=1;i<=n/2;i++){
        g<<rez[i];
    }
    for(int i=n/2;i>=1;i--){
        g<<rez[i];
    }
    f.close();
    g.close();
}
