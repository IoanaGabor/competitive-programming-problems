
#include <bits/stdc++.h>
#define NMAX 1000
#define MMAX 1000
#define x first
#define y second
#define MAXVAL (1LL<<60)-1

using namespace std;

ifstream f("elmer.in");
ofstream g("elmer.out");

int n,m,top,lint;
pair<long long,long long> r[NMAX+5],z[MMAX+5],stiva[NMAX+5],interv[2*NMAX*MMAX+5];

int cauta(int i){
    int pas=1<<9,ret=0;
    while(pas){
        if(ret+pas<=m&&z[ret+pas].x<=r[i].x){
            ret+=pas;
        }
        pas>>=1;
    }
    return ret;
}

long long det(pair<long long,long long> a,pair<long long,long long> b,pair<long long,long long> c){
    return 1LL*a.x*b.y+1LL*b.x*c.y+1LL*c.x*a.y-1LL*c.x*b.y-1LL*a.x*c.y-1LL*b.x*a.y;
}

long long afla_min(pair <long long,long long> a,pair<long long,long long> b){
    if(a.y<=b.y){
        return MAXVAL;
    }
    long double aux=1LL*1.0*(1LL*a.x*b.y-1LL*b.x*a.y)/(b.y-a.y);
    if(aux-(long long)aux<=0.000001){
        return aux;
    }else{
        return aux+1;
    }
}

long long afla_max(pair <long long,long long> a,pair<long long,long long> b){
    if(a.y<=b.y){
        return -MAXVAL;
    }
    long double aux=1LL*1.0*(1LL*a.x*b.y-1LL*b.x*a.y)/(b.y-a.y);
    return aux;
}

void calc_interv(){
    sort(r+1,r+n+1);
    sort(z+1,z+m+1);
    int ind;
    long long st[NMAX+5],dr[NMAX+5],stt,drr;
    for(int i=1;i<=n;i++){
        top=0;
        ind=cauta(i);
        for(int j=ind+1;j<=m;j++){
            while(top&&det(r[i],stiva[top],z[j])>=0){
                top--;
            }
            stiva[++top]=z[j];
            st[j]=afla_min(r[i],stiva[1]);
            dr[j]=MAXVAL-1;
        }
        top=0;
        for(int j=ind;j>=1;j--){
            while(top&&det(r[i],stiva[top],z[j])<=0){
                top--;
            }
            stiva[++top]=z[j];
            st[j]=-MAXVAL+1;
            dr[j]=afla_max(r[i],stiva[1]);
        }
        for(int j=1;j+1<=m;j++){
            stt=max(1LL*z[j].x+1,st[j]);
            drr=min(1LL*z[j+1].x-1,dr[j+1]);
            //cout<<i<<' '<<j<<' '<<stt<<' '<<drr<<'\n';
            if(stt<=drr){
                interv[++lint]=make_pair(stt,-1);
                interv[++lint]=make_pair(drr,1);
            }
        }
    }
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>r[i].x>>r[i].y;
    }
    f>>m;
    for(int i=1;i<=m;i++){
        f>>z[i].x>>z[i].y;
    }
    z[m+1].x=0,z[m+1].y=0;
    z[m+2].x=MAXVAL,z[m+2].y=0;
    m+=2;
    calc_interv();
    sort(interv+1,interv+lint+1);
    int rez=0,nr=0;
    for(int i=1;i<=lint;i++){
        //cout<<interv[i].x<<' '<<interv[i].y<<'\n';
        nr-=interv[i].y;
        rez=max(rez,nr);
    }
    g<<rez;
}
