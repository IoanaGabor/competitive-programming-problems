#include <bits/stdc++.h>
#define NMAX 20

using namespace std;

ifstream fi("zaruri.in");
ofstream fo("zaruri.out");

int n;
double rez[NMAX+5];

int main(){
    fi>>n;
    rez[1]=3.5;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(j<rez[i-1]){
                rez[i]+=(1.0/6)*rez[i-1];
            }else{
                rez[i]+=(1.0/6)*j;
            }
        }
    }
    fo<<fixed<<setprecision(7)<<rez[n];
}