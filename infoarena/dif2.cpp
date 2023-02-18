
#include <iostream>
#include <fstream>
#include <algorithm>
#define NMAX 300001

using namespace std;

ifstream f("dif2.in");
ofstream g("dif2.out");

long long n,sir[NMAX],cerinta;
long long p1,p2;

bool ok(long long x,long long p){
    if(x>sir[n]*sir[n]){
        return 0;
    }
    long long j=n,poz=0;
    for(int i=1;i<=n&&j;i++){
        while(sir[i]*sir[j]>=x&&j){
            j--;
        }
        poz=poz+j;

}
    if(poz<=p){

        return true;
    }
    return false;
}

long long cauta(long long p){
    long long pas=1LL<<37,i=0;
    while(pas){
        if(ok(i+pas,p)){
            i=i+pas;
        }
        pas=pas/2;
    }
    return i;
}

int main(){
    f>>cerinta>>n;
    if(cerinta==2){
        f>>p1>>p2;
    }
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    sort(sir+1,sir+n+1);
    if(cerinta==1){
        g<<sir[n]*sir[n]-sir[1]*sir[1]<<'\n';
        return 0;
    }
    p1=n*n-p1;
    p2=n*n-p2;
    g<<cauta(p1)-cauta(p2);
    f.close();
    g.close();
}
