
#include <bits/stdc++.h>
#define MMAX 5000
#define DIMMAX 1000000

using namespace std;

ifstream fi("tester.in");
ofstream fo("tester.out");

int n,m;
pair<int,int> key[MMAX+5];
vector<int> G[MMAX+5];
int gi[MMAX+5],ge[MMAX+5];
int st[DIMMAX+5],ans[DIMMAX+5],ls,la;

void euler(int snode){
    st[ls++]=snode;
    int node,next_node;
    while(ls){
        node=st[ls-1];
        if(G[node].size()){
            next_node=G[node].back();
            G[node].pop_back();
            st[ls++]=next_node;
        }else{
            ans[la++]=node;
            ls--;
        }
    }
    for(int i=la-2;i>=1;i--){
        if(ans[i]==0){
            fo<<'R'<<' ';
        }else{
            if(key[ans[i+1]].second==key[ans[i]].first){
                fo<<key[ans[i]].second<<' ';
            }else{
                fo<<key[ans[i]].first<<' '<<key[ans[i]].second<<' ';
            }
        }
    }
}

int main(){
    fi>>n>>m;
    for(int i=1;i<=m;i++){
        fi>>key[i].first>>key[i].second;
    }
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            if(key[i].second==key[j].first){
                G[i].push_back(j);
                ge[i]++;
                gi[j]++;
            }
            if(key[j].second==key[i].first){
                G[j].push_back(i);
                ge[j]++;
                gi[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=ge[i];j<gi[i];j++){
            G[i].push_back(0);
        }
        for(int j=gi[i];j<ge[i];j++){
            G[0].push_back(i);
        }        
    }
    euler(0);
    fi.close();
    fo.close();
}
