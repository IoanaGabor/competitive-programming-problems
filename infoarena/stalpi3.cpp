
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#define NMAX 10000
#define KMAX 100

using namespace std;

ifstream f("stalpi3.in");
ofstream g("stalpi3.out");

struct punct{
    int val,ii,cablu;
};

pair <int,int> rez[KMAX+1];

punct m[KMAX+1][NMAX+1];
int n,d,k,n_culori[KMAX+1],distante[KMAX+1];
double sarma;

bool criteriu(punct a,punct b){
    return a.val<=b.val;
}

double pitagora(int a,int b){
    return (double)sqrt(a*a+b*b);
}

void rez_culoare(int c){
    int l=n_culori[c];
    sort(m[c]+1,m[c]+l+1,criteriu);
    int dist=30001,a,b;
    for(int i=1;i<l;i++){
        if(m[c][i].cablu!=m[c][i+1].cablu){
            if(abs(m[c][i+1].val-m[c][i].val)<dist){
                dist=abs(m[c][i+1].val-m[c][i].val);
                if(m[c][i].cablu==1){
                    a=m[c][i].ii;
                    b=m[c][i+1].ii;
                }else{
                    a=m[c][i+1].ii;
                    b=m[c][i].ii;
                }
            }
        }
    }
    rez[c].first=a;
    rez[c].second=b;
    distante[c]=dist;
}

int main(){
    f>>n>>d;
    int c,v;
    for(int i=1;i<=n;i++){
        f>>v>>c;
        m[c][++n_culori[c]].val=v;
        m[c][n_culori[c]].ii=i;
        m[c][n_culori[c]].cablu=1;
        k=max(k,c);
    }
    for(int i=1;i<=n;i++){
        f>>v>>c;
        m[c][++n_culori[c]].val=v;
        m[c][n_culori[c]].ii=i;
        m[c][n_culori[c]].cablu=2;
        k=max(k,c);
    }
    for(int i=1;i<=k;i++){
        rez_culoare(i);
        sarma+=pitagora(distante[i],d);
    }
    g<<fixed<<setprecision(3)<<sarma;
    g<<'\n';
    for(int i=1;i<=k;i++){
        g<<rez[i].first<<' '<<rez[i].second<<'\n';
    }
    f.close();
    g.close();
}
