#include <bits/stdc++.h>
#define NMAX 100

using namespace std;

ifstream fi("borcane.in");
ofstream fo("borcane.out");

int n;
pair<int,int> sir[NMAX+5];

bool crit(pair<int,int> a, pair<int,int> b){
    return a.first>b.first;
}

void solve(){
    sort(sir+1,sir+n+1,crit);
    for(int i=n;i>=3;i--){
        while(sir[i].first>0){
            fo<<sir[i].second<<' '<<sir[i-1].second<<' '<<sir[1].second<<'\n';
            sir[i].first--,sir[i-1].first--;
            sir[1].first+=2;
        }
    }
    if(sir[2].first==0){
        return;
    }
    while(sir[2].first-2>=0){
        fo<<sir[2].second<<' '<<sir[1].second<<' '<<sir[3].second<<'\n';    
        fo<<sir[2].second<<' '<<sir[1].second<<' '<<sir[4].second<<'\n';
        sir[2].first-=2;
        sir[1].first-=2;
        sir[3].first+=2,sir[4].first+=2;
    }
    while(sir[3].first>0){
        fo<<sir[3].second<<' '<<sir[4].second<<' '<<sir[1].second<<'\n';    
        sir[3].first--;
        sir[4].first--;
        sir[1].first+=2;
    }
    if(sir[2].first>0){
        fo<<sir[1].second<<' '<<sir[2].second<<' '<<sir[4].second<<'\n';    
        fo<<sir[1].second<<' '<<sir[4].second<<' '<<sir[2].second<<'\n';    
        fo<<sir[1].second<<' '<<sir[4].second<<' '<<sir[3].second<<'\n';    
        fo<<sir[3].second<<' '<<sir[2].second<<' '<<sir[1].second<<'\n';        
        fo<<sir[3].second<<' '<<sir[2].second<<' '<<sir[1].second<<'\n';        
    }
}

int main(){
    fi>>n;
    for(int i=1;i<=n;i++){
        fi>>sir[i].first;
        sir[i].second=i;
    }
    solve();
    fi.close();
    fo.close();
}