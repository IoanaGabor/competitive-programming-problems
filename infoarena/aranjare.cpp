
#include <iostream>
#include <fstream>
#define NMAX 5000

using namespace std;

ifstream f("aranjare.in");
ofstream g("aranjare.out");

int n,sp,pf;
char sir[2*NMAX+5];

void afis(int p){
    g<<p<<'\n';
    swap(sir[p],sir[sp]);
    swap(sir[p+1],sir[sp+1]);
    sp=p;
}

int main(){
    f>>n;
    f>>sir+1;
    for(int i=1;i<=2*n+2&&!sp;i++){
        if(sir[i]=='S'){
            sp=i;
        }
    }
    for(int i=1;i<=n;i++){
        if(sir[i]=='F'){
            continue;
        }
        if(sir[i]=='B'&&sir[i+1]!='S'){
            afis(i);
        }else{
            afis(2*n+1);
            afis(i);
        }
        pf=0;
        for(int j=i+1;j<=2*n+2&&!pf;j++){
            if(sir[j]=='F'){
                pf=j;
            }
        }
        if(pf!=2*n+2){
            afis(pf);
        }else{
            afis(2*n+1);
            afis(i+2);
            afis(i-1);
            afis(i+1);
        }
    }
    if(sir[n+1]!='S'){
        afis(n+1);
    }
    f.close();
    g.close();
}
