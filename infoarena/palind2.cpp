
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("palind2.in");
ofstream g("palind2.out");

int t,n,x,par[5020],impar[5020],np,ni,p,rez1,rez2;

int modul(int a){
    if(a>=0){
        return a;
    }
    return -a;
}

int main(){
    f>>t;
    while(t--){
        f>>n;
        np=ni=0;
        for(int i=1;i<=n;i++){
            f>>x;
            if(i%2==0){
                par[++np]=x;
            }else{
                impar[++ni]=x;
            }
        }
        sort(par+1,par+np+1);
        sort(impar+1,impar+ni+1);
        p=np/2+1;
        rez1=0;
        rez2=1;
        for(int i=1;i<=np;i++){
            rez1+=modul(par[i]-par[p]);
        }
        if(np>0&&np%2==0){
            rez2*=(par[p]-par[p-1]+1);
        }
        p=ni/2+1;
        for(int i=1;i<=ni;i++){
            rez1+=modul(impar[i]-impar[p]);
        }
        if(ni%2==0){
            rez2*=(impar[p]-impar[p-1]+1);
        }
        g<<rez1<<' '<<rez2<<'\n';
    }
    f.close();
    g.close();
}
