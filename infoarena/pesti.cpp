
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("pesti.in");
ofstream g("pesti.out");

int main(){
    int n,x,z=0,cn,u=0,prev=0,poz_prec,poz;
    f>>n>>x;
    cn=n;
    while(cn>2){
        if(cn%2==1){
            cn=(cn+1)/2;
        }else{
            cn/=2;
        }
        z++;
    }
    poz=x;
    for(int i=1;i<=z;i++){
        poz_prec=poz;
        if(x%2==1){
            x=x/2+1;
            n=n/2+n%2;
        }else{
            prev+=n/2+n%2;
            x=x/2;
            n=n/2;
        }
        poz=prev+x;
        if(poz!=poz_prec){
            u=i;
        }
    }
    if(u==0){
        u=1;
    }
    g<<z<<' '<<poz<<' '<<u<<'\n';
    f.close();
    g.close();
}
