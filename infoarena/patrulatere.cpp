
#include <bits/stdc++.h>
#define NMAX 256
#define x first
#define y second

using namespace std;

ifstream f("patrulatere.in");
ofstream g("patrulatere.out");

int n;
pair <int,int> puncte[NMAX+5];
int nrpct[NMAX+5][NMAX+5];
long long cnt;

bool sub_dreapta(int i,int j,int k){
    return (1LL*puncte[i].x*puncte[j].y+1LL*puncte[j].x*puncte[k].y+1LL*puncte[k].x*puncte[i].y-1LL*puncte[k].x*puncte[j].y-1LL*puncte[i].x*puncte[k].y-1LL*puncte[j].x*puncte[i].y<0);
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>puncte[i].x>>puncte[i].y;
    }
    if(n<4){
        g<<0<<'\n';
    }else{
        cnt=1LL*n*(n-1)*(n-2)*(n-3)/24;
        sort(puncte+1,puncte+n+1);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=i+1;k<j;k++){
                    if(sub_dreapta(i,j,k)){
                        nrpct[i][j]++;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(sub_dreapta(i,k,j)){
                        cnt-=(nrpct[i][k]-nrpct[i][j]-nrpct[j][k]-1);
                    }else{
                        cnt+=(nrpct[i][k]-nrpct[i][j]-nrpct[j][k]);
                    }
                }
            }
        }
        g<<cnt<<'\n';
    }
    f.close();
    g.close();
}
