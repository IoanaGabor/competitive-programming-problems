
#include <iostream>
#include <fstream>
#define NMAX 1000000

using namespace std;

ifstream f("prefix.in");
ofstream g("prefix.out");

int t,pi[NMAX+5],n,sol;
string sir;

void make_prefix(){
    pi[1]=0;
    int k=0;
    sol=0;
    for(int i=2;i<=n;i++){
        while(k!=0&&sir[k+1]!=sir[i]){
            k=pi[k];
        }
        if(sir[k+1]==sir[i]){
            k++;
        }
        pi[i]=k;
        if(pi[i]*2>=i&&i%(i-pi[i])==0){
            sol=i;
        }
    }
}

int main(){
    f>>t;
    while(t--){
        f>>sir;
        n=sir.size();
        for(int i=n;i>=1;i--){
            sir[i]=sir[i-1];
        }
        make_prefix();
        g<<sol<<'\n';
    }
    f.close();
    g.close();
}
