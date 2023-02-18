
#include <bits/stdc++.h>
#define NMAX 100000

using namespace std;

ifstream fi("incurcatura.in");
ofstream fo("incurcatura.out");

int p,n,x;
int k[NMAX+5];
vector<int> adiac[NMAX+5];
int fv[NMAX+5];
vector<int> muchii[NMAX+5];
int maxnod;
int nm;
int unu,doi;

int main(){
    fi>>p>>n;
    for(int i=1;i<=n;i++){
        fi>>k[i];
        for(int j=1;j<=k[i];j++){
            fi>>x;
            adiac[i].push_back(x);
        }
        sort(adiac[i].begin(),adiac[i].end());
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<k[i];j++){
            x=adiac[i][j];
            if(find(adiac[x].begin(),adiac[x].end(),i)==adiac[x].end()){
                fv[x]++;
                fv[i]++;
                muchii[x].push_back(i);
                muchii[i].push_back(x);
                nm++;
            }
        }
    }
    if(p==1){
        maxnod=1;
        for(int i=2;i<=n;i++){
            if(fv[maxnod]<fv[i]){
                maxnod=i;
            }
        }
        fo<<maxnod<<'\n';
    }else{
        if(nm==2){
            for(int i=1;i<=n;i++){
                if(fv[i]==2){
                    unu=muchii[i][0];
                    doi=muchii[i][1];
                    break;
                }
            }
        }else{
            maxnod=1;
            for(int i=2;i<=n;i++){
                if(fv[maxnod]<fv[i]){
                    maxnod=i;
                }
            }
            unu=maxnod;
            for(int i=0;i<fv[maxnod];i++){
                fv[muchii[maxnod][i]]--;
            }
            fv[maxnod]=0;
            maxnod=1;
            for(int i=2;i<=n;i++){
                if(fv[maxnod]<fv[i]){
                    maxnod=i;
                }
            }
            doi=maxnod;
        }
        fo<<min(unu,doi)<<' '<<max(unu,doi)<<'\n';
    }
}