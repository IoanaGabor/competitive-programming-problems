
#include <iostream>
#include <fstream>
#define NMAX 1000
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("segmente.in");
ofstream g("segmente.out");

struct segment{
    int x1,x2,y1,y2;
} o[NMAX+5],v[NMAX+5],aux;
int n,lo,lv,dist[NMAX+5][NMAX+5],rez=MAXVAL;

void inverseaza(){
    for(int i=1;i<=lv;i++){
        aux=v[i];
        v[i]=o[i];
        o[i]=aux;
    }
    for(int i=lv+1;i<=lo;i++){
        v[i]=o[i];
    }
    swap(lo,lv);
    for(int i=1;i<=lo;i++){
        aux=o[i];
        swap(aux.x1,aux.y1);
        swap(aux.x2,aux.y2);
        o[i]=aux;
    }
    for(int i=1;i<=lv;i++){
        aux=v[i];
        swap(aux.x1,aux.y1);
        swap(aux.x2,aux.y2);
        v[i]=aux;
    }

}

void ordoneaza(){
    for(int i=1;i<=lo;i++){
        if(o[i].x1>o[i].x2){
            swap(o[i].x1,o[i].x2);
        }
    }
    for(int i=1;i<=lv;i++){
        if(v[i].y1>v[i].y2){
            swap(v[i].y1,v[i].y2);
        }
    }
}

int modul(int a){
    if(a<0){
        return -a;
    }
    return a;
}

int distanta(int i,int j){
    int d1,d2,d3,d4,a,b;
    d1=modul(v[j].y2-o[i].y1);
    d2=modul(v[j].y1-o[i].y1);
    d3=modul(o[i].x2-v[j].x1);
    d4=modul(o[i].x1-v[j].x1);
    if(d1+d2==v[j].y2-v[j].y1){
        a=0;
    }else{
        a=min(d1,d2);
    }
    if(d3+d4==o[i].x2-o[i].x1){
        b=0;
    }else{
        b=min(d3,d4);
    }
    return max(a,b);
}

void calc_dist(){
    for(int i=1;i<=lo;i++){
        for(int j=1;j<=lv;j++){
            dist[i][j]=distanta(i,j);
        }
    }
}

void rezolva(){
    int minim1=MAXVAL,minim2=MAXVAL;
    for(int i=1;i<=lo;i++){
        for(int j=i+1;j<=lo;j++){
            minim1=MAXVAL;
            minim2=MAXVAL;
            for(int k=1;k<=lv;k++){
                if(minim1>=max(dist[i][k],dist[j][k])){
                    minim2=minim1;
                    minim1=max(dist[i][k],dist[j][k]);
                }else if(minim2>max(dist[i][k],dist[j][k])){
                    minim2=max(dist[i][k],dist[j][k]);;
                }
            }
            rez=min(rez,max(minim1,minim2));
        }
    }
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>aux.x1>>aux.y1>>aux.x2>>aux.y2;
        if(aux.x1==aux.x2){
            v[++lv]=aux;
        }else{
            o[++lo]=aux;
        }
    }
    if(lo>lv){
        inverseaza();
    }
    ordoneaza();
    calc_dist();
    rezolva();
    g<<rez;
    f.close();
    g.close();
}
