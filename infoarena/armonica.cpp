
#include <bits/stdc++.h>
#define NMAX 1000

using namespace std;

ifstream fi("armonica.in");
ofstream fo("armonica.out");

long long a,b,c;
vector<pair<long long,long long> > rez;
vector<pair<int,int>> fact;

void desc(int n){
    int cnt=0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            cnt=0;
            while(n%i==0){
                n/=i;
                cnt++;
            }
            fact.push_back(make_pair(i,2*cnt));
        }
    }
    if(n>1){
        fact.push_back(make_pair(n,2));
    }
}

void bkt(int ind,long long d){
    if(ind==fact.size()){
        if(b%2==0){
            a=b/2+d;
            c=b/2+1LL*b*b/4/d;
        }else{
            a=(b+d)/2;
            c=(b+1LL*b*b/d)/2;
        }
        rez.push_back(make_pair(a,c));
        return;
    }
    int e,f;
    long long p=1;
    f=fact[ind].first;
    e=fact[ind].second;
    for(int i=0;i<=e;i++){
        bkt(ind+1,d*p);
        p=1LL*p*f;
    }
}

int main(){
    fi>>b;
    if(b%2==0){
        desc(b/2);
    }else{
        desc(b);
    }
    bkt(0,1);
    fo<<rez.size()<<'\n';
    for(int i=0;i<rez.size();i++){
        fo<<rez[i].first<<' '<<rez[i].second<<'\n';
    }
    fi.close();
    fo.close();
}
