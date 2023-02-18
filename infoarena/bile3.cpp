
#include <iostream>
#include <fstream>
#include <string>
#define NMAX 20

using namespace std;

ifstream f("bile3.in");
ofstream g("bile3.out");

int n,k,nr1[(1<<NMAX)+5],rez[NMAX+5],inv[NMAX+5];
string s;

void adauga(int x){
    if(s.size()>1000000){
        g<<s;
        s.clear();
    }
    if(x<=9){
        s.push_back('0'+x);
    }else{
        s.push_back('0'+x/10);
        s.push_back('0'+x%10);
    }
    s.push_back(' ');
}

void bkt(int lev){
    if(lev==k+1){
        for(int i=1;i<=k;i++){
            adauga(rez[i]);
        }
        s.push_back('\n');
        return;
    }
    inv[lev]=1-inv[lev];
    if(inv[lev]){
        for(int i=rez[lev-1]+1;i<=n-k+lev;i++){
            rez[lev]=i;
            bkt(lev+1);
        }
    }else{
        for(int i=n-k+lev;i>=rez[lev-1]+1;i--){
            rez[lev]=i;
            bkt(lev+1);
        }
    }
}

int main(){
    f>>n>>k;
    bkt(1);
    g<<s;
    f.close();
    g.close();
}
