
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define NMAX 1000


using namespace std;

ifstream f("desen.in");
ofstream g("desen.out");

int n,x,y,lm,lr,parent[NMAX+5],nrelem[NMAX+5],p1,p2;
double suma;
struct muchie{
    int x,y;
    double cost;
} muchii[2*NMAX+5],rez[NMAX+5];
struct punct{
    int x,y;
} puncte[NMAX+5];

bool cmp(muchie a,muchie b){
    return a.cost<b.cost;
}

int functie(int val){
    if(parent[val]==val){
        return val;
    }
    parent[val]=functie(parent[val]);
    return parent[val];

}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>puncte[i].x>>puncte[i].y;
        for(int j=1;j<i;j++){
            muchii[++lm].x=i;
            muchii[lm].y=j;
            muchii[lm].cost=(double)sqrt((puncte[i].x-puncte[j].x)*(puncte[i].x-puncte[j].x)+(puncte[i].y-puncte[j].y)*(puncte[i].y-puncte[j].y));
        }
        sort(muchii+1,muchii+lm+1,cmp);
        lr=0;
        suma=0;
        for(int j=1;j<=i;j++){
            parent[j]=j;
        }
        for(int j=1;j<=lm&&lr<i-1;j++){
            p1=functie(muchii[j].x);
            p2=functie(muchii[j].y);
            if(p1!=p2){
                if(nrelem[p1]<=nrelem[p2]){
                    nrelem[p2]+=nrelem[p1];
                    parent[p1]=p2;
                }else{
                    nrelem[p1]+=nrelem[p2];
                    parent[p2]=p1;
                }
                lr++;
                rez[lr].x=muchii[j].x;
                rez[lr].y=muchii[j].y;
                rez[lr].cost=muchii[j].cost;
                suma+=rez[lr].cost;
            }
        }
        g<<fixed<<setprecision(6)<<suma<<'\n';
        lm=lr;
        for(int j=1;j<=lr;j++){
            muchii[j].x=rez[j].x;
            muchii[j].y=rez[j].y;
            muchii[j].cost=rez[j].cost;
        }
    }
    f.close();
    g.close();
}
