
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("origami.in");
ofstream g("origami.out");

int foaie[8000][8000],sus,jos,stanga,dreapta,n,m,a,b,aux,gr;

int main(){
    f>>n>>m;
    sus=1;
    jos=n;
    stanga=1;
    dreapta=n;
    for(int i=sus;i<=jos;i++){
        for(int j=stanga;j<=dreapta;j++){
            foaie[i][j]=1;
        }
    }
    while(m--){
        f>>a>>b;
        if(a==1){
            for(int i=sus;i<=jos;i++){
                aux=stanga+2*b-1;
                for(int j=stanga;j<=stanga+b-1;j++){
                    foaie[i][aux]+=foaie[i][j];
                    aux--;
                }
            }
            dreapta=max(dreapta,stanga+2*b-1);
            stanga+=b;
        }
        if(a==2){
            aux=sus+2*b-1;
            for(int i=sus;i<=sus+b-1;i++){
                for(int j=stanga;j<=dreapta;j++){
                    foaie[aux][j]+=foaie[i][j];
                }
                aux--;
            }
            jos=max(jos,sus+2*b-1);
            sus+=b;
        }
    }
    gr=1;
    for(int i=sus;i<=jos;i++){
        for(int j=stanga;j<=dreapta;j++){
           gr=max(gr,foaie[i][j]);
        }
    }
    g<<jos-sus+1<<' '<<dreapta-stanga+1<<' '<<gr<<'\n';
    f.close();
    g.close();
}
