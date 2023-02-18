
#include <iostream>
#include <fstream>
#define NMAX 15
#define LMAX 1000
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("sobo.in");
ofstream g("sobo.out");

int n,l,rasp[LMAX+5],cost[(1LL<<16)+5];
char cod[NMAX+5][LMAX+5];

int calculeaza(int stare){
    if(cost[stare]!=MAXVAL){
        return cost[stare];
    }
    int bit,bit2,mask1,mask2;
    for(int i=0;i<l;i++){
        mask1=mask2=0;
        for(int j=0;j<n;j++){
            bit=((stare>>j)&1);
            if(bit){
                bit2=cod[j+1][i]-'0';
                if(bit2){
                    mask1+=(1<<j);
                }else{
                    mask2+=(1<<j);
                }
            }
        }
        if(mask1&&mask2){
            calculeaza(mask1);
            calculeaza(mask2);
            if(cost[mask1]<cost[mask2]){
                cost[stare]=min(cost[stare],cost[mask2]+rasp[i]);
            }else{
                cost[stare]=min(cost[stare],cost[mask1]+rasp[i]);
            }
        }
    }
    if(cost[stare]==MAXVAL){
        cost[stare]=0;
    }
    return cost[stare];
}

int main(){
    f>>n>>l;
    for(int i=1;i<=n;i++){
        f>>cod[i];
    }
    for(int i=0;i<l;i++){
        f>>rasp[i];
    }
    for(int i=0;i<(1<<n);i++){
        cost[i]=MAXVAL;
    }
    g<<calculeaza((1<<n)-1);
    f.close();
    g.close();
}
