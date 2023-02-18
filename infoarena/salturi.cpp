
#include <iostream>
#include <fstream>
#define NMAX 250000
using namespace std;

ifstream f("salturi.in");
ofstream g("salturi.out");

int t,n,sir[NMAX+1],rez[NMAX+1],hmax,nuibine,j;

int main(){
    f>>t;
    while(t--){
        f>>n;
        hmax=n+1;
        nuibine=0;
        rez[1]=hmax;
        for(int i=1;i<=n;i++){
            f>>sir[i];
            if(i>1){
                if(sir[i]==1){
                    rez[i]=hmax;
                }else{
                    j=i-1;
                    while(j>=1&&sir[i]!=sir[j]+1){
                        j--;
                    }
                    if(j==0){
                        nuibine=1;
                    }else{
                        rez[i]=rez[j]-1;
                    }
                }
            }
        }
        if(nuibine){
            g<<-1<<'\n';
        }else{
            for(int i=1;i<=n;i++){
                g<<rez[i]<<' ';
            }
            g<<'\n';
        }
    }
    f.close();
    g.close();
}
