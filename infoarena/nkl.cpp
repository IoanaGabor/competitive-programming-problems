
///am gresit la ciur si am uitat sa pun MOD la o adunare
///am inlocuit functia exp_rapida
#include <iostream>
#include <fstream>
#include <bitset>
#define MOD 1000000007
#define SQRT 40000
#define KMAX 1000

using namespace std;

ifstream f("nkl.in");
ofstream g("nkl.out");

int n,q,k,l;
bitset<SQRT+5> ciur;
int prime[SQRT+5],lprime,exp[30],lexp;
long long rez,suma,putere;
int combinari[KMAX+5][KMAX+5];

void constr_ciur(){
    for(int i=2;i<=SQRT;i++){
        if(ciur[i]==0){
            prime[++lprime]=i;
            for(int j=2*i;j<=SQRT;j+=i){
                ciur[j]=1;
            }
        }
    }
}

void desc(){
    for(int i=1;i<=lprime&&prime[i]<=n;i++){
        if(n%prime[i]==0){
            exp[++lexp]=0;
            while(n%prime[i]==0){
                exp[lexp]++;
                n/=prime[i];
            }
        }
    }
    if(n!=1){
        exp[++lexp]=1;
    }
}

void calc_combinari(){
    combinari[0][0]=1;
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=i;j++){
            if(j==0){
                combinari[i][j]=1;
            }else{
                combinari[i][j]=(combinari[i-1][j]+combinari[i-1][j-1])%MOD;
            }
        }
    }
}

int main(){
    f>>n>>q;
    constr_ciur();
    desc();
    calc_combinari();
    while(q--){
        f>>k>>l;
        rez=1;
        for(int i=1;i<=lexp;i++){
            suma=0;
            putere=1;
            for(int j=k;j>=k-l+1;j--){
                suma=(suma+1LL*combinari[k][j]*putere)%MOD;
                putere=(1LL*putere*exp[i])%MOD;
            }
            rez=(rez*suma)%MOD;
        }
        g<<rez<<'\n';
    }
    f.close();
    g.close();
}
