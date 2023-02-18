
#include <iostream>
#include <fstream>
#include <algorithm>
#define NMAX 100000

using namespace std;

ifstream f("taietura.in");
ofstream g("taietura.out");

int n,p1;
long long sir[NMAX+5],rez[NMAX+5];
pair <long long,int> sume[NMAX+5];

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
        sume[i].first=sume[i-1].first+1LL*sir[i];
        sume[i].second=i;
    }
    sort(sume,sume+n+1);
    p1=0;
    for(int i=1;i<=n;i++){
        if(sume[i].first!=sume[p1].first){
            for(int j=p1;j<i;j++){
                rez[sume[j].second+1]+=(i-j-1);
                rez[sume[j].second+1]-=(j-p1);
            }
            p1=i;
        }
    }
    if(p1!=n){
        for(int j=p1;j<=n;j++){
            rez[sume[j].second+1]+=(n-j);
            rez[sume[j].second+1]-=(j-p1);
        }
    }
    for(int i=1;i<=n;i++){
        rez[i]+=rez[i-1];
        g<<rez[i]<<' ';
    }
    f.close();
    g.close();
}
