
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("fractal.in");
ofstream g("fractal.out");

int k,x,y,cnt;

int main(){
    f>>k>>x>>y;
    for(int i=k;i>=1;i--){
        if(x<=(1<<(i-1))&&y<=(1<<(i-1))){
            swap(x,y);
        }else if(x<=(1<<(i-1))&&y>(1<<(i-1))){
            cnt+=(1<<(i-1))*(1<<(i-1));
            y-=(1<<(i-1));
        }else if(x>(1<<(i-1))&&y>(1<<(i-1))){
            cnt+=2*(1<<(i-1))*(1<<(i-1));
            y-=(1<<(i-1));
            x-=(1<<(i-1));
        }else if(x>(1<<(i-1))&&y<=(1<<(i-1))){
            cnt+=3*(1<<(i-1))*(1<<(i-1));
            x-=(1<<(i-1));
            swap(x,y);
            y=(1<<(i-1))-y+1;
            x=(1<<(i-1))-x+1;
        }
    }
    g<<cnt;
    f.close();
    g.close();
}
