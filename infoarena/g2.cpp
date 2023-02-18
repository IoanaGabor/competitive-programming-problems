
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream f("g2.in");
    ofstream g("g2.out");
    long long n,rez=0,cn,i=9;
    f>>n;
    if(n==1){
        g<<1;
        return 0;
    }
    cn=n;
    while(cn!=1||i!=1){
        if(cn%i==0){
            rez=rez*10+i;
            cn=cn/i;
        }else{
            i--;
        }
    }
    if(cn>1){
        g<<0;
    }else{
        cn=rez;
        rez=0;
        while(cn){
            rez=rez*10+cn%10;
            cn=cn/10;
        }
        g<<rez;
    }
    f.close();
    g.close();
}
