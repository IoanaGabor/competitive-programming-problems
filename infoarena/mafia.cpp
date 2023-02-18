
#include <bits/stdc++.h>
#define NMAX 100000

using namespace std;

ifstream fi("mafia.in");
ofstream fo("mafia.out");

int t,x,n,v[NMAX+5];
long double sum,p,a,b;
long long m;
long double rez;

int main(){
    fi>>t;
    while(t--){
        fi>>n>>m>>x;
        sum=0;
        for(int i=1;i<=n;i++){
            fi>>v[i];
            sum+=1LL*v[i];
        }
        if(sum-v[x]<m){
            rez=0;
        }else{
            a=sum-v[x]-m;
            b=sum-v[x];
            rez=1;
            for(int i=1;i<=v[x];i++){
                a++,b++;
                rez*=(long double)(a/b);
            }
        }
        rez=1-rez;
        fo<<fixed<<setprecision(10)<<rez<<'\n';
    }
    fi.close();
    fo.close();
}