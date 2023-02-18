
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid3.in");
ofstream g("euclid3.out");

int t,a,b,c,d,x,y;

void euclid(int a,int b,int& d,int& x,int& y){
    if(b==0){
        d=a;
        x=1;
        y=0;
        return;
    }else{
        int x0,y0;
        euclid(b,a%b,d,x0,y0);
        x=y0;
        y=x0-(a/b)*y0;
    }
}

int main(){
    f>>t;
    while(t--){
        f>>a>>b>>c;
        euclid(a,b,d,x,y);
        if(c%d!=0){
            g<<0<<' '<<0<<'\n';
        }else{
            g<<x*(c/d)<<' '<<y*(c/d)<<'\n';
        }
    }
    f.close();
    g.close();
}
