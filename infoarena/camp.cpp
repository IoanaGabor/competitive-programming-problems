
#include <iostream>
#include <fstream>
#include <queue>
#include <cmath>
#define NMAX 100000
#define x first
#define y second

using namespace std;

ifstream f("camp.in");
ofstream g("camp.out");

int n,xmin=NMAX+5,xmax=0,i1=-1,i2=-1;
int yy1,yy2;
long long rez;
pair <int,int> pct[NMAX+5];

int inainte(int i){
    i++;
    if(i==n+1){
        i=1;
    }
    return i;
}

int inapoi(int i){
    i--;
    if(i==0){
        i=n;
    }
    return i;
}

bool intersect(pair<int,int> p1,pair<int,int> p2,int x2){
    return (min(p1.x,p2.x)<=x2&&x2<=max(p1.x,p2.x));
}

int muta(int& ind,int x2,int s){
    while(!intersect(pct[ind],pct[ind+1],x2)||pct[ind].x==pct[ind+1].x){
        if(s==1){
            ind=inainte(ind);
        }else{
            ind=inapoi(ind);
        }
    }
    if(s==-1){
        long double yy=pct[ind].y+(long double)((pct[ind+1].y-pct[ind].y)*(x2-pct[ind].x)/((long double)(pct[ind+1].x-pct[ind].x)));
        return floor(yy);
    }else{
        long double yy=pct[ind].y+(long double)((pct[ind+1].y-pct[ind].y)*(x2-pct[ind].x)/((long double)(pct[ind+1].x-pct[ind].x)));
        return ceil(yy);
    }
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>pct[i].x>>pct[i].y;
        xmin=min(xmin,pct[i].x);
        xmax=max(xmax,pct[i].x);
    }
    for(int i=1;i<=n;i++){
        if(xmin==pct[i].x){
            if(i1==-1){
                i1=i;
            }else{
                i2=i;
                if(pct[i1].y>pct[i2].y){
                    swap(i1,i2);
                }
            }
            if(i2==-1){
                i2=i;
            }
        }
    }
    i1=inapoi(i1);
    pct[n+1]=pct[1];
    for(int x2=xmin;x2<=xmax;x2++){
        yy1=muta(i1,x2,-1);
        yy2=muta(i2,x2,1);
        rez+=1LL*(yy1-yy2+1)*x2+1LL*yy1*(yy1+1)/2-1LL*yy2*(yy2-1)/2;
    }
    g<<rez;
    f.close();
    g.close();
}
