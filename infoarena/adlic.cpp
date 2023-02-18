
#include <fstream>
#include <set>

using namespace std;

ifstream f("adlic.in");
ofstream g("adlic.out");

int cerinta,n,val,ant,rez1,clase[1000005],nrc;

void insereaza(){
    int pas=1<<20,poz=0;
    while(pas){
        if(poz+pas<=nrc&& clase[poz+pas]>val){
            poz+=pas;
        }
        pas>>=1;
    }
    clase[++poz]=val;
    nrc=max(nrc,poz);
}

int main(){
    f>>cerinta;
    f>>n;
    if(cerinta==1){
        ant=-1;
        rez1=0;
        for(int i=1;i<=n;i++){
            f>>val;
            if(val<ant && rez1==0){
                rez1=val;
            }
            ant=val;
        }
        g<<rez1<<'\n';
        f.close();
        g.close();
        return 0;
    }
    for(int i=1;i<=n;i++){
        f>>val;
        insereaza();
    }
    g<<nrc;
    f.close();
    g.close();
}
