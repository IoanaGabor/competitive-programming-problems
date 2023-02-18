
#include <bits/stdc++.h>
#define NMAX 100000
#define MAXVAL (1<<30);

using namespace std;

ifstream fi("dreptunghi2.in");
ofstream fo("dreptunghi2.out");

int t,n;
pair<int,int> pcte[NMAX+5];
int d1,d2,d3,d4;
double aria;

int main(){
    fi>>t;
    while(t--){
        fi>>n;
        for(int i=1;i<=n;i++){
            fi>>pcte[i].first>>pcte[i].second;
        }
        d1=d3=MAXVAL;
        d2=d4=-MAXVAL;
        for(int i=1;i<=n;i++){
            d1=min(d1,pcte[i].first-pcte[i].second);
            d2=max(d2,pcte[i].first-pcte[i].second);
            d3=min(d3,pcte[i].first+pcte[i].second);
            d4=max(d4,pcte[i].first+pcte[i].second);
        }
        aria=(d2-d1)*(d4-d3)/2.0;
        fo<<fixed<<setprecision(3)<<aria<<'\n';
    }
    fi.close();
    fo.close();
}