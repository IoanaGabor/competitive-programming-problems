
#include <iostream>
#include <fstream>
#define NMAX 500
#define NCIF 500

using namespace std;

ifstream f("expozitie.in");
ofstream g("expozitie.out");

int n,d,k,r,linie[NMAX+5][NCIF+5];

void aduna(int ind){
    int i=1,t=0;
    while(i<=linie[ind][0]||i<=linie[ind-1][0]||t!=0){
        linie[ind][i]=linie[ind][i]+linie[ind-1][i]+t;
        t=linie[ind][i]/10;
        linie[ind][i]%=10;
        i++;
    }
    linie[ind][0]=i-1;
}

int main(){
    f>>n>>d>>k;
    r=n-k*d+d-1;
    if(r==0){
        g<<1;
        return 0;
    }else if(r<0){
        g<<0;
        return 0;
    }
    linie[0][0]=linie[0][1]=1;
    for(int i=1;i<=r;i++){
        for(int j=i;j>=1;j--){
            aduna(j);
        }
    }
    for(int i=linie[d-1][0];i>=1;i--){
        g<<linie[d-1][i];
    }
    f.close();
    g.close();
}
