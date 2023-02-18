
#include <iostream>
#include <fstream>
#define NMAX 40000

using namespace std;

ifstream f("piata.in");
ofstream g("piata.out");

int n,i1,i2,j1,j2,suma[NMAX+5],dp[NMAX+5],inc,sf,rez;

int main(){
    f>>n>>i1>>j1>>i2>>j2;
    for(int i=1;i<=n;i++){
        suma[i]=suma[i/10]+i%10;
        dp[i]=dp[i-1]+suma[i];
    }
    for(int i=i1;i<=i2;i++){
        inc=(j1+n-i+1)%n;
        if(inc==0){
            inc=n;
        }
        sf=(j2+n-i+1)%n;
        if(sf==0){
            sf=n;
        }
        if(inc<=sf){
            rez+=dp[sf]-dp[inc-1];
        }else{
            rez+=dp[n]-dp[inc-1]+dp[sf];
        }
    }
    g<<rez;
    f.close();
    g.close();
}
