
#include <iostream>
#include <fstream>
#include <cstring>
#define NMAX 100000

using namespace std;

ifstream f("aiacubile.in");
ofstream g("aiacubile.out");

int t,poz[NMAX+5],n,k,pas,marcat[NMAX+5],viz[NMAX+5],p,cnt;

int cmmdc(int a,int b){
    int c;
    while(b){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main(){
    f>>t;
    while(t--){
        f>>n>>k;
        for(int i=1;i<=n;i++){
            f>>poz[i];
        }
        pas=cmmdc(n,k);
        for(int i=1;i<=n;i++){
            if((i-1)%pas==0){
                marcat[i]=1;
            }
        }
        cnt=0;
        for(int i=1;i<=n;i++){
            if(viz[i]==0&&marcat[i]){
                p=poz[i];
                cnt++;
                while(p!=i){
                    cnt++;
                    viz[p]=1;
                    p=poz[p];
                }
            }
        }
        for(int i=1;i<=n;i++){
            viz[i]=marcat[i]=0;
        }
        g<<cnt<<'\n';
    }
    f.close();
    g.close();
}
