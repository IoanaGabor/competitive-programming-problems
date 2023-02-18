
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("patrate2.in");
ofstream g("patrate2.out");

int rez[10000],n;

void inmult_rez_cu_nr(int nr){
    int t=0;
    for(int i=1;i<=rez[0];i++){
        rez[i]=rez[i]*nr+t;
        t=rez[i]/10;
        rez[i]%=10;
    }
    while(t){
        rez[++rez[0]]=t%10;
        t/=10;
    }
}

int main(){
    rez[0]=rez[1]=1;
    f>>n;
    for(int i=1;i<=n*n;i++){
        inmult_rez_cu_nr(2);
    }
    for(int i=1;i<=n;i++){
        inmult_rez_cu_nr(i);
    }
    for(int i=rez[0];i>=1;i--){
        g<<rez[i];
    }
    f.close();
    g.close();
}
