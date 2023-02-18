
#include <bits/stdc++.h>
#define NMAX 65000

using namespace std;

ifstream fi("caraibe.in");
ofstream fo("caraibe.out");

struct ceva{
    int tins,nrp;
};

int n,l;
int sir[NMAX+5];
int aux[NMAX+5];
vector<ceva> q;
int stq,totpinq,ignor;

void read(){
    fi>>n;
    for(int i=1;i<=n-2;i++){
        fi>>sir[i];
    }
}

long long solve(){
    long long ret=10000000000;
    for(int i=n-2;i>=1;i--){
        ignor=n-i-1-sir[i];
        while(q.size()>stq&&ignor>=q[stq].nrp){
            ignor-=q[stq].nrp;
            totpinq-=q[stq].nrp;
            stq++;
        }
        if(q.size()>stq&&ignor<q[stq].nrp){
            q[stq].nrp-=ignor;
            totpinq-=ignor;
            ignor=0;
        }
        if(sir[i]-totpinq>0){
            q.push_back({i,sir[i]-totpinq});
            totpinq=sir[i];
        }
    }
    for(int i=stq;i<q.size();i++){
        ret-=q[i].tins*q[i].nrp;
    }
    return ret;
}

int main(){
    read();
    fo<<solve();
    fi.close();
    fo.close();
}