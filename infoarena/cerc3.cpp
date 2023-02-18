
#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

ifstream f("cerc3.in");
ofstream g("cerc3.out");

struct circle{
    int x,y,r;
    long double slope;
} circles[MAXN+5];
int n;

long double infx(circle a){
    return (a.x+a.slope*a.y-sqrt((a.x+a.slope*a.y)*(a.x+a.slope*a.y)-(1+a.slope*a.slope)*(a.x*a.x+a.y*a.y-a.r*a.r)))/(1+a.slope*a.slope);
}

long double supx(circle a){
    return (a.x+a.slope*a.y+sqrt((a.x+a.slope*a.y)*(a.x+a.slope*a.y)-(1+a.slope*a.slope)*(a.x*a.x+a.y*a.y-a.r*a.r)))/(1+a.slope*a.slope);
}

bool cmp(circle a,circle b){
    if(a.slope==b.slope){
        return supx(a)<supx(b);
    }
    return a.slope<b.slope;
}

void solve(){
    int m=0,cntc=0,cntl=0,maxc=0;
    circle last;
    for(int i=1;i<=n;i++){
        if(circles[i].slope!=circles[i-1].slope){
            m++;
            if(maxc<cntc){
                maxc=cntc;
                cntl=1;
            }else if(maxc==cntc){
                cntl++;
            }            
            last=circles[i];
            cntc=1;
        }else{
            if((long double)infx(circles[i])>(long double)supx(last)){
                cntc++;
                last=circles[i];
            }
        }
    }
    if(maxc<cntc){
        maxc=cntc;
        cntl=1;
    }else if(maxc==cntc){
        cntl++;
    }
    g<<m<<' '<<maxc<<' '<<cntl<<'\n';
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>circles[i].x>>circles[i].y>>circles[i].r;
        circles[i].slope=(long double)circles[i].y/circles[i].x;
    }
    sort(circles+1,circles+n+1,cmp);
    solve();
    f.close();
    g.close();
}