
#include <iostream>
#include <fstream>
#define NMAX 100000
#define MOD 1000000007

using namespace std;

ifstream f("leftmax.in");
ofstream g("leftmax.out");

int n,sir[NMAX+5];
int st[NMAX+5],dr[NMAX+5],stiva[NMAX+5],top,l,r;
long long rez;

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    sir[0]=sir[n+1]=NMAX+5;
    top=1;
    stiva[top]=0;
    for(int i=1;i<=n;i++){
        while(top&&sir[stiva[top]]<sir[i]){
            top--;
        }
        st[i]=stiva[top];
        stiva[++top]=i;
    }
    top=1;
    stiva[top]=n+1;
    for(int i=n;i>=1;i--){
        while(top&&sir[stiva[top]]<sir[i]){
            top--;
        }
        dr[i]=stiva[top];
        stiva[++top]=i;
    }
    for(int i=1;i<=n;i++){
        l=i-st[i]-1;
        r=dr[i]-i-1;
        if(l<=r){
            rez=(rez+1LL*(2*r-l+2)*(l+1)/2)%MOD;
        }else{
            rez=(rez+1LL*(r+2)*(r+1)/2)%MOD;
        }
    }
    g<<rez;
    f.close();
    g.close();
}
