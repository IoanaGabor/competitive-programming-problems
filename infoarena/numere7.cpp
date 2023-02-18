
#include <bits/stdc++.h>
#define XMAX 20

using namespace std;

ifstream fi("numere7.in");
ofstream fo("numere7.out");

int cf;
char X[XMAX+5];
long long fact[XMAX+5],d,n;
int perm[XMAX+5];
int fr[11];

long long calc(int poz,int c){
    long long ret=1;
    ret=fact[cf-poz];
    for(int i=1;i<=9;i++){
        if(c==i){
            ret/=(fact[fr[i]-1]);
        }else{
            ret/=(fact[fr[i]]);
        }
    }
    return ret;
}

int main(){
    fi>>n;
    fi>>(X+1);
    cf=strlen(X+1);
    sort(X+1,X+cf+1);
    fact[0]=1;
    for(int i=1;i<=cf;i++){
        fact[i]=1LL*fact[i-1]*i;
        fr[X[i]-'0']++;
    }
    if(n>fact[cf]){
        fo<<"-1";
    }else{
        for(int i=1;i<=cf;i++){
            d=0;
            for(int j=1;j<=9;j++){
                if(fr[j]){
                    if(d<n){
                        perm[i]=j;
                    }else{
                        break;
                    }
                    d+=calc(i,j);
                }
            }
            d-=calc(i,perm[i]);
            n=n-d;
            fr[perm[i]]--;
        }               
    }
    for(int i=1;i<=cf;i++){
        fo<<perm[i];
    }
}