
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

ifstream f("planificare.in");
ofstream g("planificare.out");

int n,k,contor;

pair <int,int> intervale[100001];

multiset <int> sfarsit;
multiset <int>::iterator it;

bool criteriu(pair <int,int> a,pair <int,int> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}

int main(){
    f>>n>>k;
    for(int i=1;i<=n;i++){
        f>>intervale[i].first>>intervale[i].second;
    }
    sort(intervale+1,intervale+n+1,criteriu);
    for(int i=1;i<=k;i++){
        sfarsit.insert(0);
    }
    for(int i=1;i<=n;i++){
        it=sfarsit.upper_bound(intervale[i].first);
        if(it!=sfarsit.begin()){
            contor++;
            it--;
            sfarsit.erase(it);
            sfarsit.insert(intervale[i].second);
        }
    }
    g<<contor<<'\n';
    f.close();
    g.close();
}
