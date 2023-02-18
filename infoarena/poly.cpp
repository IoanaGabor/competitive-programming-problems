
#include <bits/stdc++.h>
#define NMAX 30000

using namespace std;

ifstream fi("poly.in");
ofstream fo("poly.out");

int n,l,sol;
int sir[NMAX+5];
int diviz[NMAX+5];
int last[1<<7+5];
int lung[1<<7+5];
int m[]={2,3,7,11,19,23,37};

int main(){
    fi>>n;
    for(int i=1;i<=n;i++){
        fi>>sir[i];
        for(int j=0;j<7;j++){
            if(sir[i]%m[j]==0){
                diviz[i]+=(1<<j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        l=0;
        for(int j=0;j<=(1<<7);j++){
            if(!(diviz[i]&j)&&last[j]>0){
                l=max(l,lung[j]);    
            }
        }
        lung[diviz[i]]=l+1;
        last[diviz[i]]=i;
        sol=max(sol,l+1);
    }
    fo<<sol<<'\n';
    fi.close();
    fo.close();
}