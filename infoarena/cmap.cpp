#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#define NMAX 100000
#define x first
#define y second
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("cmap.in");
ofstream g("cmap.out");

int n;
pair <int,int> sir[NMAX+5],aux[NMAX+5];

long long dist2(int i,int j){
    return (long long)(1LL*(sir[i].x-sir[j].x)*(sir[i].x-sir[j].x)+1LL*(sir[i].y-sir[j].y)*(sir[i].y-sir[j].y));
}

long long minim(long long a,long long b){
    if(a<b){
        return a;
    }
    return b;
}

long long modul(long long a){
    if(a<0){
        return -a;
    }
    return a;
}

long long distanta(int st,int dr){
    if(dr-st+1==3){
        if(sir[dr].y<sir[st].y){
            swap(sir[st],sir[dr]);
        }
        if(sir[dr-1].y<sir[st].y){
            swap(sir[st],sir[dr-1]);
        }
        if(sir[dr].y<sir[dr-1].y){
            swap(sir[dr-1],sir[dr]);
        }
        return minim(dist2(st,st+1),minim(dist2(st+1,dr),dist2(st,dr)));
    }
    if(dr-st+1==2){
        if(sir[dr].y<sir[st].y){
            swap(sir[st],sir[dr]);
        }
        return dist2(st,dr);
    }
    int mij=(st+dr)/2,ii=st,jj=mij+1,ll=st-1;
    long long d1,d2,dmin,dreapta;
    dreapta=sir[mij].x;
    d1=distanta(st,mij);
    d2=distanta(mij+1,dr);
    dmin=minim(d1,d2);
    //cout<<st<<' '<<dr<<' '<<mij<<' '<<dreapta;
    ///interclasare
    while(ii<=mij&&jj<=dr){
        if(sir[ii].y<sir[jj].y){
            aux[++ll]=sir[ii++];
        }else{
            aux[++ll]=sir[jj++];
        }
    }
    while(ii<=mij){
        aux[++ll]=sir[ii++];
    }
    while(jj<=dr){
        aux[++ll]=sir[jj++];
    }
    for(int i=st;i<=dr;i++){
        sir[i]=aux[i];
    }
    ll=0;
    for(int i=st;i<=dr;i++){
        if(1LL*modul(sir[i].x-dreapta)*modul(sir[i].x-dreapta)<=1LL*dmin){
            aux[++ll]=sir[i];
        }
    }
    for(int i=1;i<=ll;i++){
        for(int j=i+1;j<=min(i+8,ll);j++){
            d1=(long long)(1LL*(aux[i].x-aux[j].x)*(aux[i].x-aux[j].x)+1LL*(aux[i].y-aux[j].y)*(aux[i].y-aux[j].y));
            dmin=minim(dmin,d1);
        }
    }
    //cout<<' '<<dmin<<' '<<fixed<<setprecision(6)<<(double)sqrt((double)dmin)<<'\n';
    return dmin;
}

int main() {
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i].x>>sir[i].y;
    }
    sort(sir+1,sir+n+1);
    g<<fixed<<setprecision(6)<<sqrt((long double)distanta(1,n));
}
