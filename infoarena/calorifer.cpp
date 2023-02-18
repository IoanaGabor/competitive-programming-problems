
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("calorifer.in");
ofstream g("calorifer.out");

struct numar{
    int putere_2,putere_3,x,nr;
};

numar sir[200001];
int n,rest,ok;

void desc_x(int i){
    sir[i].putere_2=0;
    sir[i].putere_3=0;
    sir[i].x=sir[i].nr;
    while(sir[i].x%2==0){
        sir[i].x/=2;
        sir[i].putere_2++;
    }
    while(sir[i].x%3==0){
        sir[i].x/=3;
        sir[i].putere_3++;
    }
}

bool criteriu(numar a,numar b){
    if(a.putere_2==b.putere_2){
        return a.putere_3<b.putere_3;
    }
    return a.putere_2>b.putere_2;
}

int main(){
    f>>n;
    ok=1;
    for(int i=1;i<=n;i++){
        f>>sir[i].nr;
        desc_x(i);
        if(i==1){
            rest=sir[i].x;
        }else{
            if(sir[i].x!=rest){
                ok=0;
            }
        }
    }
    if(!ok){
        g<<-1;
        f.close();
        g.close();
        return 0;
    }
    sort(sir+1,sir+n+1,criteriu);
    for(int i=1;i<=n;i++){
        if(i>1&&(sir[i-1].putere_3>sir[i].putere_3||sir[i-1].putere_2<sir[i].putere_2)){
            ok=0;
        }
    }
    if(!ok){
        g<<-1;
        f.close();
        g.close();
        return 0;
    }
    for(int i=1;i<=n;i++){
        g<<sir[i].nr<<' ';
    }
    f.close();
    g.close();
}
