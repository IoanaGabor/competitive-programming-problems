
#include <iostream>
#include <fstream>
#define MOD 13007
using namespace std;

ifstream f("perspic.in");
ofstream g("perspic.out");

int n,m,matrice[101][101],v[10001],am_fost_aici[10001],nr_set_element,ciur[10001];
char ch;
int x1,y1,x2,y2;

void desc(){
    int cn=nr_set_element,p;
    for(int i=2;i*i<=nr_set_element;i++){
        p=0;
        while(cn!=1&&cn%i==0){
            p++;
            cn/=i;
        }
        ciur[i]=max(ciur[i],p);
    }
    if(cn>1){
        ciur[cn]=max(ciur[cn],1);
    }
}

int putere(int x,int y){
    int rez=1;
    while(y){
        if(y%2==1){
            rez=(rez*x)%MOD;
            y--;
        }else{
            x=(x*x)%MOD;
            y/=2;
        }
    }
    return rez;
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            matrice[i][j]=(i-1)*n+j;
        }
    }
    for(int i=1;i<=m;i++){
        f>>ch;
        if(ch=='E'){
            f>>x1>>y1>>x2>>y2;
            swap(matrice[x1][y1],matrice[x2][y2]);
        }else if(ch=='C'){
            f>>y1>>y2;
            for(int j=1;j<=n;j++){
                swap(matrice[j][y1],matrice[j][y2]);
            }
        }else if(ch=='R'){
            f>>x1>>x2;
            for(int j=1;j<=n;j++){
                swap(matrice[x1][j],matrice[x2][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            v[matrice[i][j]]=(i-1)*n+j;
        }
    }
    int nr;
    for(int i=1;i<=n*n;i++){
        nr_set_element=0;
        if(!am_fost_aici[i]){
            nr=i;
            do{
                am_fost_aici[nr]=1;
                nr=v[nr];
                nr_set_element++;
            }while(nr!=i);
            desc();
        }
    }
    int rez=1;
    for(int i=2;i<=n*n;i++){
        if(ciur[i]){
            rez=rez*putere(i,ciur[i]);
            rez%=MOD;
        }
    }
    g<<rez;
    f.close();
    g.close();
}
