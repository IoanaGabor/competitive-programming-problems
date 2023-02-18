
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream f("aria.in");
ofstream g("aria.out");

int n;
long double x,y,xp,yp,arie,px,py;

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>x>>y;
        if(i>1){
            arie+=(y*xp-x*yp);
        }else{
            px=x;
            py=y;
        }
        xp=x;
        yp=y;
    }
    arie+=py*x-px*y;
    arie=arie*0.5;
    if(arie<0){
        g<<setprecision(6)<<fixed<<-arie<<'\n';
    }else{
        g<<setprecision(6)<<fixed<<arie<<'\n';
    }
    f.close();
    g.close();
}
