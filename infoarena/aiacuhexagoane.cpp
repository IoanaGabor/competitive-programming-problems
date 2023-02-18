
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("aiacuhexagoane.in");
ofstream g("aiacuhexagoane.out");

long long n,m,a,b,q;

int main(){
    f>>n>>m>>q;
    if(n==1){
        while(q--){
            g<<"nu"<<'\n';
        }
    }else{
        while(q--){
            f>>a>>b;
            a=a%(2*m-1);
            b=b%(2*m-1);
            if(!a){
                a=2*m-1;
            }
            if(!b){
                b=2*m-1;
            }
            if(a>m){
                a=a-m+2;
            }
            if(b>m){
                b=b-m+2;
            }
            if(a%3==b%3){
                g<<"da"<<'\n';
            }else{
                g<<"nu"<<'\n';
            }
        }
    }
    f.close();
    g.close();
}
