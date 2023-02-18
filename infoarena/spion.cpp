
#include <iostream>
#include <fstream>
#include <cstring>
#define NMAX 100000
#define MOD 100003

using namespace std;

ifstream f("spion.in");
ofstream g("spion.out");

char sir[NMAX+5];
int n,x,y,cerinta,dp[2][NMAX+5];
long long fact[NMAX+5],sol;

long long putere(long long baza,int ex){
    long long rez=1;
    while(ex){
        if(ex%2==0){
            ex/=2;
            baza=(baza*baza)%MOD;
        }else{
            ex--;
            rez=(rez*baza)%MOD;
        }
    }
    return rez;
}

int main(){
    f>>cerinta>>sir;
    x=1;
    y=1;
    n=strlen(sir);
    for(int i=0;i<n;i++){
        if(sir[i]=='V'){
            x++;
        }else{
            x++;
            y++;
        }
    }
    if(cerinta==1){
        g<<y;
    }else{
        x--;
        y--;
        fact[0]=1;
        for(int i=1;i<=x;i++){
            fact[i]=(fact[i-1]*i)%MOD;
        }
        putere(fact[x-y],MOD-2);
        sol=(((fact[x]*putere(fact[y],MOD-2))%MOD)*putere(fact[x-y],MOD-2))%MOD;
        g<<sol;
    }
    f.close();
    g.close();
}
