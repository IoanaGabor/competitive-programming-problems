
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("reflex.in");
ofstream g("reflex.out");

int n,m,gcd,h,v;

int cmmdc(int a,int b){
    int c;
    while(b){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main(){
    f>>n>>m;
    n--;
    m--;
    gcd=cmmdc(n,m);
    h=m/gcd;
    v=n/gcd;
    g<<1LL*n*m/gcd+1<<' ';
    if(h%2==0&& v%2==1){
        g<<2<<'\n';
    }
    if(h%2==1&& v%2==0){
        g<<4<<'\n';
    }
    if(h%2==1&& v%2==1){
        g<<3<<'\n';
    }
    g<<h-1<<' '<<v-1<<'\n';
    f.close();
    g.close();
}
