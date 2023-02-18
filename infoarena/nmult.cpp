
#include <iostream>
#include <fstream>
#define MAXVAL 1000000
#define MOD 666013

using namespace std;

ifstream f("nmult.in");
ofstream g("nmult.out");

int n,k,w,dp[2][MAXVAL+5];

long long putere(long long baza,long long exp){
    long long rez=1;
    while(exp){
        if(exp%2==0){
            exp/=2;
            baza=1LL*(baza*baza)%MOD;
        }else{
            exp--;
            rez=1LL*(rez*baza)%MOD;
        }
    }
    return rez;
}

int combinari(int nn,int kk){
    if(nn<kk){
        return 0;
    }
    int ind1=min(kk,nn-kk),ind2=max(kk,nn-kk);
    long long p1=1,p2=1,cnt=0,ci;
    for(int i=2;i<=nn;i++){
        if(i>ind2){
            if(i%MOD==0){
                ci=i;
                while(ci%MOD==0){
                    ci=ci/MOD;
                    cnt++;
                }
                p1=1LL*(p1*ci)%MOD;
            }else{
                p1=1LL*(p1*i)%MOD;
            }
        }else if(i<=ind1){
            if(i%MOD==0){
                ci=i;
                while(ci%MOD==0){
                    ci=ci/MOD;
                    cnt--;
                }
                p2=1LL*(p2*ci)%MOD;
            }else{
                p2=1LL*(p2*i)%MOD;
            }
        }
    }
    if(cnt!=0){
        return 0;
    }
    p2=putere(p2,MOD-2);
    return (p1*p2)%MOD;
}

int main(){
    f>>n>>k>>w;
    int sol=0;
    while(n>0&&w>1){
        n=n-k+1;
        w--;
    }
    if(w==1){
        sol=combinari(n,k);
    }
    g<<sol;
    f.close();
    g.close();
}
