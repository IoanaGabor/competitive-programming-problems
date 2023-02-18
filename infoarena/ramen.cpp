
#include <bits/stdc++.h>
#define NMAX 100000

using namespace std;

ifstream fi("ramen.in");
ofstream fo("ramen.out");

int n,d,p[NMAX+5],t[NMAX+5],inc[NMAX+5],ind[NMAX+5],k,aici,sol[NMAX+5];
struct crit{
    bool operator()(int i, int j){
        if(p[i]==p[j]){
            return t[i]>t[j];
        }
        return p[i]>p[j];
    }
};
priority_queue <int,vector<int>,crit> pq;

bool cmp(int i,int j){
    return inc[i]<inc[j];
}

int main(){
    fi>>n>>d;
    for(int i=1;i<=n;i++){
        fi>>t[i]>>p[i];
        inc[i]=max(0,t[i]-p[i]-d);
        ind[i]=i;
    }
    sort(ind+1,ind+n+1,cmp);
    k=1;
    for(int i=1;i<=n;i++){
        while(inc[ind[k]]<=t[i]&&k<=n){
            pq.push(ind[k]);
            k++;
        }
        aici=pq.top();
        pq.pop();
        sol[aici]=t[i]+d+p[aici];
        
    }
    for(int i=1;i<=n;i++){
        fo<<sol[i]<<'\n';
    }
}