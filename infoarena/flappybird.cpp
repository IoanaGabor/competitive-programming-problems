#include <bits/stdc++.h>
#define NMAX 100000

using namespace std;

ifstream fi("flappybird.in");
ofstream fo("flappybird.out");

int n,x,y,lx,ly;

bool pok(int a,int b,int la,int lb){
    if(b<la){
        return false;
    }
    if(lb<a){
        return false;
    }
    return true;
}

bool ok(){
    fi>>n;
    lx=0;
    ly=(1LL<<31)-1;
    for(int i=1;i<=n;i++){
        fi>>x>>y;
        if(!pok(x,y,lx,ly)){
            return false;
        }
        lx=x;
        ly=y;
    }
    return true;
}

int main(){
    if(ok()){
        fo<<"YES"<<'\n';
    }else{
        fo<<"NO"<<'\n';
    }
}