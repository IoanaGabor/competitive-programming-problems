
#include <bits/stdc++.h>

using namespace std;

ifstream fi("rufe.in");
ofstream fo("rufe.out");

long long n,m,a,b,k;

long long numara(long long x,long long y,long long d){
    if(d>x+y){
        return 0;
    }
    long long mini=min(x,y),maxi=max(x,y),sum;
    if(d-1>=maxi){
        d=x+y-d+1;
        return d*(d+1)/2;
    }
    if(d-1<=mini){
        return x*y-(d-2)*(d-1)/2;
    }
    sum=mini*(mini+1)/2;
    d=d-mini-1;
    sum+=mini*(d-1);
    return x*y-sum;
}

long long nr(long long d){
    long long cnt;
    cnt=numara(n-a,m-b,d)+numara(a-1,m-b,d)+numara(n-a,b-1,d)+numara(a-1,b-1,d);
    if(d<=n-a){
        cnt+=(n-a-d+1);
    }
    if(d<=m-b){
        cnt+=(m-b-d+1);
    }
    if(d<=a-1){
        cnt+=(a-d);
    }
    if(d<=b-1){
        cnt+=(b-d);
    }
    return cnt;
}

long long cauta(){
    long long pas=(1LL<<62),ret=0;
    long long lim=max(max(n-a+m-b,m-b+a-1),max(n-a+b-1,a+b-2));
    while(pas){
        if(ret+pas<=lim&&nr(ret+pas)>=k){
            ret+=pas;
        }
        pas>>=1;
    }
    return ret;
}

int main(){
    fi>>n>>m>>a>>b>>k;
    fo<<cauta();
    fi.close();
    fo.close();
}