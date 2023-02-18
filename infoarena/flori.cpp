
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("flori.in");
ofstream g("flori.out");

int prima_fetita[1005],rez[1005],n,m,floare;

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        rez[i]=i;
        for(int j=1;j<=m;j++){
            f>>floare;
            if(prima_fetita[floare]==0){
                prima_fetita[floare]=i;
            }else{
                if(prima_fetita[floare]<rez[i]){
                    rez[i]=prima_fetita[floare];
                }else{
                    rez[prima_fetita[floare]]=rez[i];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(rez[i]==i){
            for(int j=i;j<=n;j++){
                if(rez[i]==rez[j]){
                    g<<j<<' ';
                }
            }
            g<<'\n';
        }
    }
    f.close();
    g.close();
}
