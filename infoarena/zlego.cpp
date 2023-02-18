
#include <bits/stdc++.h>
#define NMAX 250000

using namespace std;

ifstream fi("zlego.in");
ofstream fo("zlego.out");

int t,n;
int sir[NMAX+5],cost[NMAX+5];
long long sol[NMAX+5];
int pi[NMAX+5];

void constr_pi(){
    int k=0;
    pi[1]=0;
    for(int i=2;i<=n;i++){
        while(k&&sir[k+1]!=sir[i]){
            k=pi[k];
        }
        if(sir[k+1]==sir[i]){
            k++;
        }
        pi[i]=k;
    }
}

int main(){
    fi>>t;
    while(t--){
        fi>>n;
        for(int i=1;i<=n;i++){
            fi>>sir[i];
            sol[i]=0;
        }
        for(int i=1;i<=n;i++){
            fi>>cost[i];
        }
        constr_pi();
        for(int i=1;i<=n;i++){
            sol[i]+=1LL*cost[i];
        }
        for(int i=n;i>=1;i--){
            sol[pi[i]]+=1LL*sol[i];
        }
        for(int i=1;i<=n;i++){
            fo<<sol[i]<<'\n';
        }
    }
    fi.close();
    fo.close();
}