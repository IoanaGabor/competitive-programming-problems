
#include <iostream>
#include <fstream>
#define LMAX 10000

using namespace std;

ifstream f("culori3.in");
ofstream g("culori3.out");

int n,rez[LMAX+5];

void inmulteste_cu_3(){
    int t=0;
    for(int i=1;i<=rez[0];i++){
        rez[i]=rez[i]*3+t;
        t=rez[i]/10;
        rez[i]%=10;
    }
    while(t){
        rez[++rez[0]]=t%10;
        t=t/10;
    }
}

int main(){
    f>>n;
    if(n==1){
        g<<5;
        f.close();
        g.close();
        return 0;
    }
    if(n%2==0){
        rez[0]=1;
        rez[1]=8;
    }
    if(n%2==1){
        rez[0]=2;
        rez[1]=4;
        rez[2]=1;
    }
    for(int i=1;i<=n/2-1;i++){
        inmulteste_cu_3();
    }
    for(int i=rez[0];i>=1;i--){
        g<<rez[i];
    }
    f.close();
    g.close();
}
