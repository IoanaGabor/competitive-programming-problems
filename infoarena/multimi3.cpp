
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("multimi3.in");
ofstream g("multimi3.out");

int p,q,mij,suma;

int main(){
    f>>p>>q;
    mij=(p+1)/2;
    suma=p*3*(p*3+1)/(2*p);
    for(int i=1;i<=p;i++){
        for(int j=1;j<=q;j++){
            if(j==1){
                g<<i<<' ';
            }else if(j==2){
                if(i<=mij){
                    g<<2*p-(mij-i)<<' ';
                }else{
                    g<<p+i-mij<<' ';
                }
            }else if(j==3){
                if(i<=mij){
                    g<<suma-i-(2*p-(mij-i))<<' ';
                }else{
                    g<<suma-i-(p+i-mij)<<' ';
                }
            }else{
                if(j%2==0){
                    g<<p*(j-1)+i<<' ';
                }else{
                    g<<p*(j-1)+p-i+1<<' ';
                }
            }
        }
        g<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
