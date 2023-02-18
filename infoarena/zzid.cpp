#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("zzid.in");
ofstream g("zzid.out");

int h,w,sir[1000005],n,x,lsir,aux[1000005],s,laux,frecv[1000005],frmax,d;

int modul(int a){
    if(a>=0){
        return a;
    }
    return -a;
}

int main(){
    f>>h>>w;
    for(int i=1;i<=h;i++){
        f>>n;
        s=0;
        for(int j=1;j<=n;j++){
            f>>x;
            s=s+x;
            sir[++lsir]=s;
        }
    }
    sort(sir+1,sir+lsir+1);
    sir[0]=w+5;
    for(int i=1;i<=lsir;i++){
        if(sir[i]!=sir[i-1]){
            aux[++laux]=sir[i];
            frecv[laux]=1;
        }else{
            frecv[laux]++;
        }
    }
    if(laux==1){
        g<<h<<' '<<0<<'\n';
    }else{
        frmax=-1;
        for(int i=1;i<laux;i++){
            if(frecv[i]>frmax){
                frmax=frecv[i];
                d=aux[i];
            }else if(frecv[i]==frmax){
                if(modul((w-2*d))>modul((w-2*aux[i]))){
                    d=aux[i];
                }
            }
        }
        g<<h-frmax<<' '<<modul((w-2*d));
    }
    f.close();
    g.close();
}
