
#include <iostream>
#include <fstream>
#define NMAX 100000

using namespace std;

ifstream f("rmq.in");
ofstream g("rmq.out");

int n,m,sir[NMAX+5],st[NMAX+5][25],x,y,log2[NMAX+5],aux;

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        f>>sir[i];
        st[i][0]=i;
    }
    aux=0;
    for(int i=1;i<=n;i++){
        if(i<(1<<(aux+1))){
            log2[i]=aux;
        }else{
            aux++;
            log2[i]=aux;
        }
    }
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            if(sir[st[i][j-1]]<sir[st[i+(1<<(j-1))][j-1]]){
                st[i][j]=st[i][j-1];
            }else{
                st[i][j]=st[i+(1<<(j-1))][j-1];
            }
        }
    }
    while(m--){
        f>>x>>y;
        aux=(y-x+1);
        aux=log2[aux];
        g<<min(sir[st[x][aux]],sir[st[y-(1<<aux)+1][aux]])<<'\n';
    }
    f.close();
    g.close();
}
