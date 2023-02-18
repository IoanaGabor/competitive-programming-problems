
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("linterv.in");
ofstream g("linterv.out");

struct interval{
    int a,b;
};

bool criteriu(interval x,interval y){
    if(x.a==y.a){
        return x.b<=y.b;
    }else{
        return x.a<y.a;
    }
}

int main(){
    int t,n,ultimulb,s=0;
    interval sir[5005];
    f>>t;
    while(t--){
        s=0;
        f>>n;
        for(int i=1;i<=n;i++){
            f>>sir[i].a>>sir[i].b;
        }
        sort(sir+1,sir+n+1,criteriu);
        s=sir[1].b-sir[1].a;
        ultimulb=sir[1].b;
        for(int i=2;i<=n;i++){
            if(sir[i].b>ultimulb){
                if(sir[i].a<ultimulb){
                    s+=sir[i].b-ultimulb;
                }else{
                    s+=sir[i].b-sir[i].a;
                }
                ultimulb=sir[i].b;
            }
        }
        g<<s<<'\n';
    }
    f.close();
    g.close();
}
