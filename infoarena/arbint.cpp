
#include <iostream>
#include <fstream>
#include <cmath>
#define NMAX 100000
#define SQRT 1000
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("arbint.in");
ofstream g("arbint.out");

int a[NMAX+5],sq[SQRT+5],stanga[SQRT+5],dreapta[SQRT+5],n,k,rad,m,op,x,y;

int zero(){
    int st=MAXVAL,dr=-1,rez=-1;
    for(int i=1;i<=k&&dreapta[i]<=y;i++){
        if(x<=stanga[i]&&dreapta[i]<=y){
            st=min(stanga[i],st);
            dr=max(dr,dreapta[i]);
            rez=max(rez,sq[i]);
        }
    }
    if(st==MAXVAL){
        st=dr=y;
    }
    for(int i=x;i<=st;i++){
        rez=max(rez,a[i]);
    }
    for(int i=dr;i<=y;i++){
        rez=max(rez,a[i]);
    }
    return rez;
}

void unu(){
    a[x]=y;
    for(int i=1;i<=k&&stanga[i]<=x;i++){
        if(stanga[i]<=x&&x<=dreapta[i]){
            sq[i]=-1;
            for(int j=stanga[i];j<=dreapta[i];j++){
                sq[i]=max(sq[i],a[j]);
            }
            break;
        }
    }
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        f>>a[i];
    }
    k=sqrt(n);
    rad=k;
    k=n/rad;
    for(int i=1;i*rad<=n;i++){
        sq[i]=-1;
        stanga[i]=(i-1)*rad+1;
        dreapta[i]=i*rad;
        for(int j=stanga[i];j<=dreapta[i];j++){
            sq[i]=max(sq[i],a[j]);
        }
    }
    while(m--){
        f>>op>>x>>y;
        if(op==0){
            g<<zero()<<'\n';
        }else{
            unu();
        }
    }
    f.close();
    g.close();
}
