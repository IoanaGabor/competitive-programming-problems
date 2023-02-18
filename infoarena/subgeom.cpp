
#include <iostream>
#include <fstream>
#include <vector>
#define NMAX 5000
#define VALMAX 100000

using namespace std;

ifstream f("subgeom.in");
ofstream g("subgeom.out");

long long t,n,sir[NMAX+5],vazut[VALMAX+5],maxim,p1,p2,rez,cnt;
vector <int> ind[VALMAX+5];

void cauta(long long val){
    p2=0;
    long long l=ind[val].size(),pas=1<<12,i=-1;
    while(pas){
        if(i+pas<l){
            if(ind[val][i+pas]<p1){
                i+=pas;
            }
        }
        pas>>=1;
    }
    i++;
    if(i<l){
        p2=ind[val][i];
    }
}

int main(){
    f>>t;
    while(t--){
        f>>n;
        maxim=0;
        for(int i=1;i<=n;i++){
            f>>sir[i];
            maxim=max(maxim,sir[i]);
            ind[sir[i]].push_back(i);
        }
        rez=1;
        for(int i=1;i<=n;i++){
            if(!vazut[sir[i]]){
                vazut[sir[i]]=1;
                for(int r=2;r*sir[i]*1LL<=1LL*maxim;r++){
                    p1=ind[sir[i]][0];
                    cnt=1;
                    for(long long j=1LL*sir[i]*r;j<=maxim;j=1LL*j*r){
                        cauta(j);
                        if(p2){
                            cnt++;
                            rez=max(rez,cnt);
                            p1=p2;
                        }else{
                            break;
                        }
                    }
                }
            }
        }
        g<<rez<<'\n';
        for(int i=1;i<=n;i++){
            ind[sir[i]].pop_back();
            vazut[sir[i]]=0;
        }
    }
    f.close();
    g.close();
}
