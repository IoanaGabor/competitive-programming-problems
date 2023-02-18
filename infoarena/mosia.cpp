
#include <bits/stdc++.h>
#define NMAX 1000

using namespace std;

ifstream f("mosia.in");
ofstream g("mosia.out");

struct par{
    int x,y,d;
} sir[NMAX+5],s[NMAX+5];
int n,k;
double adaug[NMAX+5],dp[2][NMAX+5],rez;

bool cmp(par a, par b){
    if(a.y==b.y){
        return a.x<b.x;
    }
    return a.y<b.y;
}

bool trigon(int x1,int y1,int x2,int y2,int x3,int y3){
    return x1*y2+x2*y3+x3*y1-x1*y3-x3*y2-x2*y1>0;
}

double dist(int x1,int y1,int x2,int y2){
    return (double)(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i].x>>sir[i].y>>sir[i].d;
    }
    sort(sir+1,sir+n+1,cmp);
    for(int i=1;i<=n;i++){
        while(k>=2 &&trigon(s[k-1].x,s[k-1].y,s[k].x,s[k].y,sir[i].x,sir[i].y)){
            k--;
        }
        s[++k]=sir[i];
    }
    for(int i=n-1;i>=1;i--){
        while(k>=2 &&trigon(s[k-1].x,s[k-1].y,s[k].x,s[k].y,sir[i].x,sir[i].y)){
            k--;
        }
        s[++k]=sir[i];
    }
    for(int i=2;i<n;i++){
        adaug[i]=(double)dist(s[i-1].x,s[i-1].y,s[i+1].x,s[i+1].y) * s[i].d /2;
    }
    adaug[1]=(double)dist(s[n].x,s[n].y,s[2].x,s[2].y) * s[1].d /2;
    adaug[n]=(double)dist(s[1].x,s[1].y,s[n-1].x,s[n-1].y) * s[n].d /2;
    dp[1][1]=adaug[1];
    dp[0][1]=0;
    rez=dp[1][1];
    for(int i=2;i<n;i++){
        dp[1][i]=adaug[i]+dp[0][i-1];
        dp[0][i]=max(dp[0][i-1],dp[1][i-1]);
        rez = max(rez,dp[1][i]);
    }
    dp[1][1]=dp[0][1]=0;
    for(int i=2;i<=n;i++){
        dp[1][i]=adaug[i]+dp[0][i-1];
        dp[0][i]=max(dp[0][i-1],dp[1][i-1]);
        rez = max(rez,dp[1][i]);
    }
    g<<fixed<<setprecision(4)<<rez;
    f.close();
    g.close();
}
