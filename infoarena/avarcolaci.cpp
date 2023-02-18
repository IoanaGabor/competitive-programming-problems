
#include <bits/stdc++.h>
#define NMAX 500000

using namespace std;

ifstream fi("avarcolaci.in");
ofstream fo("avarcolaci.out");

int t,n,sir[2*NMAX+5];

void elmaj(){
    int cand,k=0,cnt=0;
    fi>>n;
    for(int i=1;i<=2*n;i++){
        fi>>sir[i];
        if(k==0){
            cand=sir[i];
            k++;
        }else if(cand==sir[i]){
            k++;
        }else{
            k--;
        }
    }    
    for(int i=1;i<=2*n;i++){
        if(sir[i]==cand){
            cnt++;
        }
    }
    if(cnt>n){
        fo<<cand<<'\n';
    }else{
        fo<<"Mozart"<<'\n';
    }
}

int main(){
    fi>>t;
    while(t--){
        elmaj();
    }
    fi.close();
    fo.close();
}