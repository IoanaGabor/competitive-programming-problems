///nu am verificat daca cnt depaseste MAXVAL in functia check
#include <bits/stdc++.h>
#define NMAX 200000
#define MAXVAL (1ULL<<63)-1

using namespace std;

ifstream fi("tarabe.in");
ofstream fo("tarabe.out");

int n,k;
int a[NMAX+5],b[NMAX+5];

bool check(long long price){
    long long cnt=0;
    for(int i=1;i<=n;i++){
        if(price-a[i]>=0){
            if(cnt<MAXVAL-1LL*(price-a[i])/b[i]+1){
                cnt+=1LL*(price-a[i])/b[i]+1;
            }
        }
    }
    if(cnt<k){
        return true;
    }
    return false;
}

long long solve(){
    long long step=(1LL<<62);
    long long maxprice=0;
    while(step){
        if(check(maxprice+step)){
            maxprice+=1LL*step;
        }
        step>>=1;
    }
    maxprice++;
    long long cnt=0,kk;
    long long sum=0;
    for(int i=1;i<=n;i++){
        if(maxprice-a[i]>=0){
            kk=1LL*(maxprice-a[i])/b[i]+1;
            cnt+=kk;
            sum+=1LL*kk*a[i]+1LL*kk*(kk-1)/2*b[i];
        }
    }
    if(cnt>k){
        sum-=1LL*(cnt-k)*maxprice;
    }
    return sum;
}

int main(){
    fi>>n>>k;
    for(int i=1;i<=n;i++){
        fi>>b[i]>>a[i];
    }
    fo<<solve();
    fi.close();
    fo.close();
}