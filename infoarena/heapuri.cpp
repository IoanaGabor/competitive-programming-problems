#include <bits/stdc++.h>
#define NMAX 200000

using namespace std;

ifstream fi("heapuri.in");
ofstream fo("heapuri.out");

int n,este[NMAX+5],nrel,op,x;
priority_queue <pair<int,int>> pq;

int solve(){
    while(!este[pq.top().second]){
        pq.pop();
    }
    return -pq.top().first;
}

int main(){
    fi>>n;
    while(n--){
        fi>>op;
        if(op<3){
            fi>>x;
        }
        if(op==1){
            este[++nrel]=1;
            pq.push({-x,nrel});
        }else if(op==2){
            este[x]=0;
        }else{
            fo<<solve()<<'\n';
        }
    }
    fi.close();
    fo.close();
}