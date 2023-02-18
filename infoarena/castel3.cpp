
#include <iostream>
#include <fstream>
#define NMAX 100

using namespace std;

ifstream f("castel3.in");
ofstream g("castel3.out");

int cerinta,n,matrice[NMAX+5][NMAX+5],camere[NMAX+5][NMAX+5],nrcamere,k,cnt,dimmax,x1,y1,x2,y2,i2,j2;

int filll(int i,int j){
    cnt++;
    camere[i][j]=k;
    if(matrice[i][j]==6||matrice[i][j]==7||matrice[i][j]==14||matrice[i][j]==15){
        i2=i;
        j2=j;
    }
    if((matrice[i][j]&1)==0){
        if(camere[i][j-1]==0){
            filll(i,j-1);
        }
    }
    if(((matrice[i][j]>>1)&1)==0){
        if(camere[i+1][j]==0){
            filll(i+1,j);
        }
    }
    if(((matrice[i][j]>>2)&1)==0){
        if(camere[i][j+1]==0){
            filll(i,j+1);
        }
    }
    if(((matrice[i][j]>>3)&1)==0){
        if(camere[i-1][j]==0){
            filll(i-1,j);
        }
    }
}


int main(){
    f>>cerinta>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f>>matrice[i][j];
            if(matrice[i][j]==9||matrice[i][j]==11||matrice[i][j]==13||matrice[i][j]==15){
                camere[i][j]=++nrcamere;
            }
        }
    }
    k=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(camere[i][j]==k){
                cnt=0;
                filll(i,j);
                if(cnt>dimmax){
                    dimmax=cnt;
                    x1=i,y1=j,x2=i2,y2=j2;
                }
                k++;
            }
        }
    }
    if(cerinta==1){
        g<<nrcamere<<'\n';
    }else if(cerinta==2){
        g<<dimmax<<'\n';
    }else if(cerinta==3){
        g<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<'\n';
    }
    f.close();
    g.close();
}
