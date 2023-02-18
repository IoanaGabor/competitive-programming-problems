
#include <iostream>
#include <fstream>
#define NMAX 30000

using namespace std;

ifstream f("matrice.in");
ofstream g("matrice.out");

int n,m,a,r[NMAX+5][3],c[NMAX+5][3],val,rez,cnt;

void numara(int x,int y){
    if(x<=n&&y<=m){
        int ymin=m,ymax=0,cntymax=0,cntymin=0,aux,nr0;
        for(int i=1;i+y-1<=m;i++){
            if(ymin>c[i+y-1][0]-c[i-1][0]){
                ymin=c[i+y-1][0]-c[i-1][0];
                cntymin=1;
            }else if(ymin==c[i+y-1][0]-c[i-1][0]){
                cntymin++;
            }
            if(ymax<c[i+y-1][0]-c[i-1][0]){
                ymax=c[i+y-1][0]-c[i-1][0];
                cntymax=1;
            }else if(ymax==c[i+y-1][0]-c[i-1][0]){
                cntymax++;
            }
        }
        for(int i=1;i+x-1<=n;i++){
            nr0=r[i+x-1][0]-r[i-1][0];
            if(2*nr0-x<0){
                aux=nr0*ymin+(x-nr0)*(y-ymin);
                if(aux>rez){
                    rez=aux;
                    cnt=cntymin;
                }else if(aux==rez){
                    cnt+=cntymin;
                }
            }else if(2*nr0-x>0){
                aux=nr0*ymax+(x-nr0)*(y-ymax);
                if(aux>rez){
                    rez=aux;
                    cnt=cntymax;
                }else if(aux==rez){
                    cnt+=cntymax;
                }
            }else{
                aux=nr0*ymin+(x-nr0)*(y-ymin);
                if(aux>rez){
                    rez=aux;
                    cnt=m-y+1;
                }else if(aux==rez){
                    cnt+=m-y+1;
                }
            }
        }
    }
}

void calc(){
    numara(1,a);
    if(a!=1){
        numara(a,1);
    }
    for(int i=2;i*i<=a;i++){
        if(i*i==a){
            numara(i,i);
        }else{
            if(a%i==0){
                numara(a/i,i);
                numara(i,a/i);
            }
        }
    }
}

int main(){
    f>>n>>m>>a;
    for(int i=1;i<=n;i++){
        f>>val;
        r[i][0]=r[i-1][0];
        r[i][1]=r[i-1][1];
        r[i][val]++;
    }
    for(int i=1;i<=m;i++){
        f>>val;
        c[i][0]=c[i-1][0];
        c[i][1]=c[i-1][1];
        c[i][val]++;
    }
    calc();
    g<<rez<<' '<<cnt;
    f.close();
    g.close();
}
