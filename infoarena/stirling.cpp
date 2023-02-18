
#include <iostream>
#include <fstream>
#define NMAX 200
#define MOD 98999

using namespace std;

ifstream f("stirling.in");
ofstream g("stirling.out");

int s[NMAX+5][NMAX+5],S[NMAX+5][NMAX+5],t,n,k,cerinta;

int main(){
    s[0][0]=1;
    S[0][0]=1;
    for(int i=1;i<=NMAX;i++){
        for(int j=1;j<=i;j++){
            s[i][j]=(-(i-1)*s[i-1][j]+s[i-1][j-1])%MOD;
            S[i][j]=(S[i-1][j-1]+j*S[i-1][j])%MOD;
        }
    }
    f>>t;
    while(t--){
        f>>cerinta>>n>>k;
        if(cerinta==1){
            g<<s[n][k]<<'\n';
        }else{
            g<<S[n][k]<<'\n';
        }
    }
    f.close();
    g.close();
}
