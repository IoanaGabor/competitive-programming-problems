
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cern.in");
ofstream g("cern.out");

int main(){
    char ch;
    int s,t;
    f>>ch>>s>>t;
    int aux[6]={0,60,720,780,360,420};
    t+=s*aux[ch-'A'];
    t=(t+1080)%1080;
    if(s==-1){
        t=1080-t;
    }
    if(t<180){
        g<<t<<' '<<1<<'\n';
    }else if(t<240){
        g<<360-(t-180)<<' '<<2<<'\n';
    }else if(t<540){
        g<<(120+(t-240))%360<<' '<<3<<'\n';
    }else if(t<600){
        t=t-540;
        g<<120+(60-t)<<' '<<1<<'\n';
    }else if(t<900){
        t=t-600;
        g<<t<<' '<<2<<'\n';
    }else if(t<960){
        t=t-900;
        g<<60+(60-t)<<' '<<3<<'\n';
    }else {
        t=t-960;
        g<<(240+t)%360<<' '<<1<<'\n';
    }
    f.close();
    g.close();
}
