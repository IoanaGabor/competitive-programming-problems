
#include <bits/stdc++.h>
#define DIMMAX 48000
#define NMAX 24000
#define MAXVAL (1ULL<<63)-1

using namespace std;

ifstream fi("base3.in");
ofstream fo("base3.out");

struct HeapNode{
    int ind;
    unsigned long long val;
    bool operator <(const HeapNode& other) const{
        return val>other.val;
    }
};

string unu,doi,trei;
unsigned long long dp[DIMMAX+5];
priority_queue<HeapNode> pq;
int ok=0;

int modul(int a){
    if(a<0){
        return -a;
    }
    return a;
}

void update_dp(string a){
    for(int i=0;i<a.size();i++){
        if(a[i]=='1'){
            if(modul(a.size()-2*i-1)<=DIMMAX){
                dp[modul(a.size()-2*i-1)]=min(1LL*a.size(),dp[modul(a.size()-2*i-1)]);
            }
        }
    }
}

void init_dp(){
    for(int i=0;i<=DIMMAX;i++){
        dp[i]=MAXVAL;
    }
}

bool old(HeapNode node){
    if(dp[node.ind]==node.val){
        return false;
    }
    return true;
}

void push_heap(HeapNode node){
    if(node.ind<=DIMMAX&&dp[node.ind]>node.val){
        dp[node.ind]=node.val;
        pq.push(node);
    }
}

void dijkstra(){
    for(int i=0;i<=DIMMAX;i++){
        if(dp[i]!=MAXVAL){
            pq.push({i,dp[i]});
        }
    }
    HeapNode node;
    int nmij,mij,iant,ni;
    while(!pq.empty()){
        node=pq.top();
        pq.pop();
        if(node.ind==0){
            return;
        }
        if(!old(node)){
            ni=modul(node.ind-unu.size());
            push_heap({ni,node.val+unu.size()});

            ni=modul(node.ind-doi.size());
            push_heap({ni,node.val+doi.size()});

            ni=modul(node.ind-trei.size());
            push_heap({ni,node.val+trei.size()});
        }
    }
}

int main(){
    fi>>unu>>doi>>trei;
    init_dp();
    update_dp(unu);
    update_dp(doi);
    update_dp(trei);
    dijkstra();
    if(dp[0]==MAXVAL){
        fo<<0<<'\n';
    }else{
        fo<<dp[0]<<'\n';
    }
    fi.close();
    fo.close();
}