
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ifstream f("cercuri.in");
    ofstream g("cercuri.out");
    int x1,y1,x2,y2,n;
    double r1,r2;
    f>>n;
    for(int i=1;i<=n;i++){
        f>>x1>>y1>>r1>>x2>>y2>>r2;
        if(x1==x2&&y1==y2&&r1==r2){
            g<<-1<<'\n';
        }else{
            double distanta=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
            int modul=abs(r1-r2);
            if(distanta>r1+r2 || distanta<modul){
                g<<-2<<'\n';
            }else if(distanta==r1+r2 || distanta==modul){
                g<<-3<<'\n';
            }else{
                double semip=(r1+r2+distanta)/2;
                g<<fixed<<setprecision(3)<<4*sqrt(semip*(semip-r1)*(semip-r2)*(semip-distanta))/distanta<<'\n';

            }
        }

    }

    f.close();
    g.close();
}
