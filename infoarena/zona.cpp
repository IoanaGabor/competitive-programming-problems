
#include <iostream>
#include <fstream>
#define LMAX 2500
#define NMAX 50

using namespace std;

ifstream f("zona.in");
ofstream g("zona.out");

int x,y,n,l,sir[LMAX+5],matrice[NMAX+5][NMAX+5],ind,rez;

int main(){
    f>>x>>y>>n>>l;
    matrice[x][y]=1;
    for(int i=1;i<l;i++){
        f>>sir[i];
        if(sir[i]==1){
            x--;
        }else if(sir[i]==2){
            y++;
        }else if(sir[i]==3){
            x++;
        }else if(sir[i]==4){
            y--;
        }
        matrice[x][y]=i+1;
    }
    f>>sir[l];
    if(sir[l]==1){
        x--;
    }else if(sir[l]==2){
        y++;
    }else if(sir[l]==3){
        x++;
    }else if(sir[l]==4){
        y--;
    }
    g<<l-matrice[x][y]+1<<'\n';
    ind=matrice[x][y];
    for(int i=ind;i<=l;i++){
        if(sir[i]==1){
            x--;
            rez+=y;
        }else if(sir[i]==2){
            y++;
        }else if(sir[i]==3){
            x++;
            rez-=y;
        }else if(sir[i]==4){
            y--;
        }
    }
    if(rez<0){
        rez=-rez;
    }
    g<<rez;
    f.close();
    g.close();
}
