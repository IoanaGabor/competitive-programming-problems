
#include <bits/stdc++.h>

using namespace std;

ifstream fi("galeti2.in");
ofstream fo("galeti2.out");

int n;
long long e;

void solve(int l, int r, long long ef){
    if(ef==0){
        return;
    }
    int nn=r-l+1;
    if(2*nn-3<=ef){
        solve(l+1,r,ef-nn+1);
        fo<<l+1<<' '<<l<<'\n';
    }else{
        solve(l,r-1,ef-1);
        fo<<r<<' '<<l<<'\n';
    }
}

int main(){
    fi>>n>>e;
    solve(1,n,e);
    fi.close();
    fo.close();
}
