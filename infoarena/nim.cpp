#include <bits/stdc++.h>
#define NMAX 10000

using namespace std;

ifstream fi("nim.in");
ofstream fo("nim.out");

int t;
int n,el;
int sum;

int main(){
    fi>>t;
    while(t--){
        fi>>n;
        sum=0;
        for(int i=1;i<=n;i++){
            fi>>el;
            sum=sum^el;
        }
        if(sum==0){
            fo<<"NU"<<'\n';
        }else{
            fo<<"DA"<<'\n';
        }
    }
    fi.close();
    fo.close();
}