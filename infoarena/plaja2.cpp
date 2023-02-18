#include <iostream>
#include <fstream>
#define KMAX 100000

using namespace std;

ifstream f("plaja2.in");
ofstream g("plaja2.out");

long long n,k,T,d[KMAX+5],t[KMAX+5];
long long sol;

long long modul(long long x){
    if(x<0){
        return -x;
    }
    return x;
}

void cauta_max(int i){
    long long dd,tt,ddd,ttt;
    dd=d[i];
    ddd=d[i+1];
    tt=t[i];
    ttt=t[i+1];
    if(ttt<tt){
        swap(tt,ttt);
    }
    long long poz=((ttt-tt)+(ddd+dd)*T)/(2LL*T);
    long long v1=tt+(poz-dd)*T;
    long long v2=ttt+(ddd-poz)*T-T;
    sol=max(sol,max(v1,v2));
}

int main()
{
    f>>n>>k>>T;
    for(int i=1;i<=k;i++){
        f>>d[i]>>t[i];
    }
    for(int i=2;i<=k;i++){
        t[i]=min(t[i],t[i-1]+T*(d[i]-d[i-1]));
    }
    for(int i=k-1;i>=1;i--){
        t[i]=min(t[i],t[i+1]+T*(d[i+1]-d[i]));
    }
    sol=max(1LL*((n-d[k])*T+t[k]),1LL*((d[1]-1)*T+t[1]));
    for(int i=1;i<k;i++){
        cauta_max(i);
    }
    g<<sol<<'\n';
    f.close();
    g.close();
    return 0;
}
