
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream f("livada.in");
    ofstream g("livada.out");
    int n,m,p,sir[700001],maxim=0,contor_max=1,soi,contor_soi=1,contor_randuri=0,bine=0;
    f>>m>>n>>p;
    soi=n/2+1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            f>>sir[j];
            if(sir[j-1]==sir[j]){
                contor_max++;
            }else{
                if(contor_max>maxim){
                    maxim=contor_max;
                }
                contor_max=1;
            }
        }
        sort(sir+1,sir+n+1);
        for(int j=1;j<=n;j++) {
            if(sir[j-1]==sir[j]){
                contor_soi++;
            }else{
                contor_soi=1;
            }
            if(contor_soi>=soi){
                bine=1;
            }
        }
        if(bine==1){
            contor_randuri++;
            bine=0;
        }
        contor_soi=1;
        contor_max=1;
    }
    g<<contor_randuri<<'\n';
    g<<maxim;
    f.close();
    g.close();
}
