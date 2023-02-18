#include <iostream>
#include <fstream>
#define VMAX (1LL<<31)-1;

using namespace std;

int teste,n,q,x,m,st,dr,mij,stant,drant,sus[1005],jos[1005],rez[1005],nuiok;

ifstream f("bsrec.in");
ofstream g("bsrec.out");

int main(){
    f>>teste;
    while(teste--){
        f>>n>>q;
        for(int i=1;i<=n;i++){
            sus[i]=VMAX;
            jos[i]=1;
        }
        while(q--){
            f>>x>>m;
            f>>st>>dr;
            stant=st;
            drant=dr;
            while(--m){
                mij=(st+dr)/2;
                f>>st>>dr;
                if(st!=stant){
                    sus[mij]=min(x-1,sus[mij]);
                }else if(dr!=drant){
                    jos[mij]=max(x,jos[mij]);
                }
                stant=st;
                drant=dr;
            }
        }
        nuiok=0;
        rez[1]=jos[1];
        if(rez[1]>sus[1]){
            nuiok=1;
        }
        for(int i=2;i<=n&&!nuiok;i++){
            rez[i]=max(rez[i-1]+1,jos[i]);
            if(rez[i]>sus[i]){
                nuiok=1;
            }
        }
        if(nuiok==1){
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
