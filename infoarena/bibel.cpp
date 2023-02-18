
#include <bits/stdc++.h>
#define NMAX 17
#define VALMAX (1ULL<<63)-1


using namespace std;

ifstream fi("bibel.in");
ofstream fo("bibel.out");

int c,x,y,la,lv;
pair<int,int> ac[NMAX+1], ve[NMAX+1];
long long dp[(1<<NMAX)+1][NMAX+1];
long long inc[NMAX+1],fin[NMAX+1];
long long sol;

long long dist(pair<int,int> a, pair<int,int> b){
    return 1LL*(a.first-b.first)*(a.first-b.first)+1LL*(a.second-b.second)*(a.second-b.second);
}

void solve(){
    for(int i=1;i<=la;i++){
        inc[i]=VALMAX;
    }
    for(int i=1;i<=lv;i++){
        for(int j=1;j<=la;j++){
            inc[j]=min(inc[j],fin[i]+dist(ac[j],ve[i]));
        }
    }
    for(int st=1;st<(1<<la);st++){
        for(int j=1;j<=la;j++){
            dp[st][j]=VALMAX;
        }
    }
    for(int i=1;i<=la;i++){
        dp[(1<<(i-1))][i]=inc[i];
    }
    for(int st=1;st<(1<<la);st++){
        for(int i=1;i<=la;i++){
            if((1<<(i-1))&st){
                for(int j=1;j<=la;j++){
                    if(((1<<(j-1))&st)==0){
                        dp[st+(1<<(j-1))][j]=min(dp[st+(1<<(j-1))][j],dp[st][i]+dist(ac[i],ac[j]));
                    }
                }
            }
        }
    }
    sol=VALMAX;
    for(int i=1;i<=la;i++){
        fin[i]=dp[(1<<la)-1][i];
        sol=min(sol,fin[i]);
    }
    for(int i=1;i<=la;i++){
        ve[i]=ac[i];
    }
    lv=la;
    la=0;
    fo<<sol<<'\n';
}

int main(){
    ve[++lv]={0,0};
    while(fi>>c){
        if(c==1){
            solve();
        }else{
            fi>>x>>y;
            ac[++la]={x,y};
        }
    }
    fi.close();
    fo.close();
}
