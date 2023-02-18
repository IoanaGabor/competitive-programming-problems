
#include <iostream>
#include <fstream>
#define CMAX 1000

using namespace std;

ifstream f("pm.in");
ofstream g("pm.out");

int x,y,rez[CMAX+5];

void inmultire(int nr){
    int t=0;
    for(int i=1;i<=rez[0];i++){
        rez[i]=rez[i]*nr+t;
        t=rez[i]/10;
        rez[i]=rez[i]%10;
    }
    while(t){
        rez[++rez[0]]=t%10;
        t/=10;
    }
}

void impartire(int nr){
    int t=0;
    for(int i=rez[0];i>=1;i--){
        rez[i]=t*10+rez[i];
        t=rez[i]%nr;
        rez[i]=rez[i]/nr;
    }
    while(rez[rez[0]]==0){
        rez[0]--;
    }
}

int main(){
    f>>x>>y;
    rez[0]=rez[1]=1;
    for(int i=x+1;i>=x-y+2;i--){
        inmultire(i);
    }
    for(int i=2;i<=y;i++){
        impartire(i);
    }
    for(int i=rez[0];i>=1;i--){
        g<<rez[i];
    }
    f.close();
    g.close();
}
