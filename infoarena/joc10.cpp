
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("joc10.in");
ofstream g("joc10.out");

int n,m,castigator=0,eliminati=0;

struct jucator{
    int joc[905],pozitie,stat;
    bool eliminat;
};

jucator a[401];

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>a[i].joc[j];
        }
        a[i].pozitie=0;
        a[i].stat=0;
        a[i].eliminat=false;
    }
    int etapa=0;
    while(!castigator){
        for(int i=1;i<=n;i++){
            if(!a[i].eliminat){
                if(a[i].pozitie==0){
                    a[i].pozitie=1;
                    if(a[i].joc[1]==0){
                        a[i].eliminat=true;
                        eliminati++;
                    }else if(a[i].joc[1]==9999){
                        castigator=i;
                    }else{
                        a[i].stat=a[i].joc[1]%10;
                    }
                }else{
                    if(a[i].stat==0){
                        a[i].pozitie=a[i].joc[a[i].pozitie]/10;
                        if(a[i].joc[a[i].pozitie]==0){
                            a[i].eliminat=true;
                            eliminati++;
                        }else if(a[i].joc[a[i].pozitie]==9999){
                            castigator=i;
                        }else{
                            a[i].stat=a[i].joc[a[i].pozitie]%10;
                        }
                    }else{
                        a[i].stat--;
                    }
                }
            }
        }
        etapa++;
    }
    g<<castigator<<' '<<a[castigator].pozitie<<' '<<etapa<<' '<<eliminati<<'\n';
    f.close();
    g.close();
}
