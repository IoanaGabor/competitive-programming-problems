
#include <iostream>
#include <fstream>
#define GMAX 1000
#define VMAX 5000
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("energii.in");
ofstream g("energii.out");

int ng,w,e,c,cost[VMAX+5];

int main(){
    f>>ng>>w;
    for(int i=1;i<=w;i++){
        cost[i]=MAXVAL;
    }
    for(int i=1;i<=ng;i++){
        f>>e>>c;
        for(int j=w;j>=0;j--){
            if(cost[j]!=MAXVAL){
                cost[min(j+e,w)]=min(cost[min(j+e,w)],cost[j]+c);
            }
        }
    }
    if(MAXVAL==cost[w]){
        g<<-1;
    }else{
        g<<cost[w];
    }
    f.close();
    g.close();
}
