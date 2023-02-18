
#include <iostream>
#include <fstream>
#include <algorithm>
#define x first
#define y second
#define NMAX 50000

using namespace std;

ifstream f("cabana2.in");
ofstream g("cabana2.out");

int n;
pair<int,int> pct[NMAX+5];
long long rez;

long long verifica(int i){
    if(pct[i].x==pct[i+1].x){
        int x1=pct[i].x,y1=pct[i].y,y2=pct[i+1].y;
        i+=2;
        while(i<n){
            if(pct[i].x==pct[i+1].x&&pct[i].y==y1&&pct[i+1].y==y2){
                return (1LL*(pct[i].x-x1)*(y2-y1));
            }else if(y1<=pct[i].y&&pct[i].y<=y2){
                return 0;
            }
            i++;
        }
    }
    return 0;
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>pct[i].x>>pct[i].y;
    }
    sort(pct+1,pct+n+1);
    for(int i=1;i<=n-4;i++){
        rez=max(rez,verifica(i));
    }
    g<<rez;
    f.close();
    g.close();
}
