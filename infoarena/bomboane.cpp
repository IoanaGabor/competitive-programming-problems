
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("bomboane.in");
ofstream g("bomboane.out");

int cerinta,n,sir[10005],minim=1000005,rez1;

int gcd(int a,int b){
    int c;
    while(b){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int cauta(int x){
    int pas=1<<16,r=0;
    while(pas){
        if(1LL*(r+pas)*(r+pas+1)/2<=1LL*x){
            r+=pas;
        }
        pas>>=1;
    }
    return r;
}

int main(){
    f>>cerinta>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
        if(cerinta==1){
            minim=min(minim,sir[i]);
        }
    }
    if(cerinta==1){
        rez1=0;
        for(int i=1;i<=n;i++){
            sir[i]=sir[i]-minim;
            rez1=gcd(rez1,sir[i]);
        }
        g<<rez1<<'\n';
    }else{
        int l,r;
        for(int i=1;i<=n;i++){
            r=cauta(sir[i]);
            l=1;
            g<<r<<' ';
            while(l<r){
                if(l==1){
                    g<<l<<' '<<r+sir[i]-r*(r+1)/2<<' ';
                }else{
                    g<<l<<' '<<r<<' ';
                }
                l++;
                r--;
            }
            if(l==r){
                g<<l;
            }
            g<<'\n';
        }
    }
    f.close();
    g.close();
}
