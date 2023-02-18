
#include <iostream>
#include <fstream>
#define MOD 9999991

using namespace std;

ifstream f("dirichlet.in");
ofstream g("dirichlet.out");

int n;
long long fact2n=1,factn1=1;

long long putere(long long baza,long long exp){
    long long rez=1;
    while(exp){
        if(exp%2==0){
            exp=exp/2;
            baza=(baza*baza)%MOD;
        }else{
            exp--;
            rez=(rez*baza)%MOD;
        }
    }
    return rez;
}

int main(){
    f>>n;
    for(int i=2;i<=n;i++){
        fact2n=(1LL*fact2n*(n+i))%MOD;
        factn1=(1LL*factn1*i)%MOD;
    }
    factn1=putere(factn1,MOD-2);
    g<<(1LL*fact2n*factn1)%MOD;
    f.close();
    g.close();
}
