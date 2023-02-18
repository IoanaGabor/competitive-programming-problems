
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#define NMAX 1000

using namespace std;

ifstream f("compresie.in");
ofstream g("compresie.out");

int n,nr,l,x,etape;
char matrice[NMAX+5][NMAX+5];
string sir;

int getnumber(int& i){
    int r=0;
    while(sir[i]<='9'&&sir[i]>='0'){
        r=r*10+sir[i]-'0';
        i++;
    }
    return r;
}

void rez(int x1,int y1,int x2,int y2, int& i){
    if(i==l||x1>x2||y1>y2){
        return;
    }
    if(sir[i]=='*'){
        i++;
        rez(x1,y1,(x1+x2)/2,(y1+y2)/2,i);
        rez(x1,(y1+y2)/2+1,(x1+x2)/2,y2,i);
        rez((x1+x2)/2+1,y1,x2,(y1+y2)/2,i);
        rez((x1+x2)/2+1,(y1+y2)/2+1,x2,y2,i);
    }else if(sir[i]<='9'&&sir[i]>='0'){
        getnumber(i);
        for(int ii=x1;ii<=x2;ii++){
            for(int jj=y1;jj<=y2;jj++){
                matrice[ii][jj]=sir[i];
            }
        }
        i++;
    }else{
        matrice[x1][y1]=sir[i];
        i++;
    }
}

int main(){
    f>>sir;
    l=sir.size();
    for(int i=0;i<l;i++){
        if(sir[i]<='9'&&sir[i]>='0'){
            x=getnumber(i);
            n=n+x;
        }else if(sir[i]>='a'&&sir[i]<='z'){
            n++;
        }else if(sir[i]=='*'){
            etape++;
        }
    }
    n=sqrt(n);
    g<<etape<<'\n';
    int i=0;
    rez(1,1,n,n,i);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g<<matrice[i][j];
        }
        g<<'\n';
    }
    f.close();
    g.close();
}
