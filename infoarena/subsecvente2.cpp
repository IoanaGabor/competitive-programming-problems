
#include <bits/stdc++.h>
#define NMAX 5
#define SMAX 50000

using namespace std;

ifstream fi("subsecvente2.in");
ofstream fo("subsecvente2.out");

int n,l,len;
char s[NMAX+1][SMAX+1];
long long nr;
unordered_map<long long, short int> mp;

bool ok(int ll){
    mp.clear();
    for(int i=1;i<=n;i++){
        nr=0;
        for(int j=0;j<ll;j++){
            nr=nr*2LL+s[i][j]-'a';
        }
        mp[nr]|=1<<(i-1);
        if(mp[nr]==(1<<n)-1){
            return 1;
        }
        for(int j=ll;s[i][j];j++){
            nr=nr-(1LL<<(ll-1))*(s[i][j-ll]-'a');
            nr=nr*2LL+s[i][j]-'a';
            mp[nr]|=1<<(i-1);
            if(mp[nr]==(1<<n)-1){
                return 1;
            }                   
        }
    }
    return 0;
}

int binary_search(){
    int pas=1,ret=0;
    while(pas*2<=l){
        pas<<=1;
    }
    while(pas){
        if(ret+pas<=l&&ok(ret+pas)){
            ret+=pas;
        }
        pas>>=1;
    }
    return ret;
}

int main(){
    fi>>n;
    l=60;
    for(int i=1;i<=n;i++){
        fi>>s[i];
        len=strlen(s[i]);
        l=min(l,len);
    }
    fo<<binary_search();
}