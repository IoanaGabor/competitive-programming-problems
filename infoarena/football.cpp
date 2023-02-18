#include <bits/stdc++.h>
#define SMAX 25

using namespace std;

ifstream fi("football.in");
ofstream fo("football.out");

int t,s;
long long sol[SMAX+1];
int pct[4]={1,2,3,6};

void build_sol(){
    sol[0]=1;
    for(int i=1;i<=SMAX;i++){
        for(int j=0;j<4;j++){
            if(i-pct[j]>=0){
                sol[i]+=sol[i-pct[j]];
            }
        }
    }
}

void solve_test(int test){
    fi>>s;
    fo<<"Case "<<test<<": "<<sol[s]<<'\n';
}

int main(){
    build_sol();
    fi>>t;
    for(int test=1;test<=t;test++){
        solve_test(test);
    }
}