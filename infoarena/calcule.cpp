
#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#define NMAX 100000
#define MOD 20011

using namespace std;

ifstream f("calcule.in");
ofstream g("calcule.out");

int n,x,rest[NMAX+5],cnt,k,rez;
multiset <int> capete;
multiset <int> :: iterator it;

int main(){
    f>>n>>k;
    for(int i=1;i<=n;i++){
        f>>x;
        if(capete.empty()){
            capete.insert(x);
            cnt++;
        }else{
            if((*capete.begin())>=x){
                capete.insert(x);
                cnt++;
            }else{
                it=capete.lower_bound(x);
                it--;
                capete.erase(it);
                capete.insert(x);
            }
        }
        rest[i]=(rest[i-1]+x)%k;
    }
    g<<cnt<<'\n';
    sort(rest,rest+n+1);
    cnt=1;
    for(int i=1;i<=n;i++){
        if(rest[i]==rest[i-1]){
            cnt++;
        }else{
            rez=(rez+(1LL*(cnt-1)*cnt/2)%MOD)%MOD;
            cnt=1;
        }
    }
    rez=(rez+(1LL*(cnt-1)*cnt/2)%MOD)%MOD;
    g<<rez;
}

