
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#define NMAX  120000
#define VMAX 1000000000

using namespace std;

ifstream f("infasuratoare.in");
ofstream g("infasuratoare.out");

int n,start,minx=VMAX+1,miny=VMAX+1,indici[NMAX+5],ind1,ind2,rez[NMAX+5],nrez;
pair <double,double> puncte[NMAX+5];
double c1,c2,c3,c4;
int stiva[NMAX+5],top;

bool ok(int i1,int i2,int i){
    return (puncte[i1].first*puncte[i2].second+puncte[i2].first*puncte[i].second+puncte[i].first*puncte[i1].second-puncte[i].first*puncte[i2].second-puncte[i].second*puncte[i1].first-puncte[i2].first*puncte[i1].second)>0;
}

bool criteriu(int a,int b){
    return ok(start,a,b);
}

int main() {
    f>>n;
    for(int i=1;i<=n;i++){
        f>>puncte[i].first>>puncte[i].second;
        if(puncte[i].second<miny){
            miny=puncte[i].second;
            minx=puncte[i].first;
            start=i;
        }else if(puncte[i].second==miny&&minx>puncte[i].first){
            minx=puncte[i].first;
            start=i;
        }
        indici[i]=i;
    }
    swap(indici[1],indici[start]);
    sort(indici+2,indici+n+1,criteriu);
    indici[n+1]=start;
    stiva[1]=start;
    stiva[2]=indici[2];
    top=2;
    int viz;
    for(int i=3;i<=n+1;i++){
        while(top>=2&&!ok(stiva[top-1],stiva[top],indici[i])){
            top--;
        }
        stiva[++top]=indici[i];
    }
    while(top){
        rez[++nrez]=stiva[top];
        top--;
    }
    nrez--;
    g<<nrez<<'\n';
    for(int i=nrez+1;i>=2;i--){
        g<<fixed<<setprecision(12)<<puncte[rez[i]].first<<' '<<puncte[rez[i]].second<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
