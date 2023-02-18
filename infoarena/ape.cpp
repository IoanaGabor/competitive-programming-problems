
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("ape.in");
ofstream g("ape.out");

int n,minx,maxx,miny,maxy,rez,x,y,s;
char sir[10005];
int main(){
    f>>n>>sir+1;
    for(int i=1;i<=n;i++){
        if(sir[i]=='N'){
            y++;
        }
        if(sir[i]=='S'){
            y--;
        }
        if(sir[i]=='V'){
            x--;
        }
        if(sir[i]=='E'){
            x++;
        }
        minx=min(minx,x);
        miny=min(miny,y);
        maxx=max(maxx,x);
        maxy=max(maxy,y);
    }
    sir[n+1]=sir[1];
    x=0;
    y=0;

    for(int i=2;i<=n+1;i++){
        if((sir[i-1]=='N'&&sir[i]=='N')||(sir[i-1]=='N'&&sir[i]=='V')||(sir[i-1]=='E'&&sir[i]=='N')){
            rez=rez-x-1;
        }
        if((sir[i-1]=='S'&&sir[i]=='S')||(sir[i-1]=='S'&&sir[i]=='E')||(sir[i-1]=='V'&&sir[i]=='S')){
            rez=rez+x;
        }
        if(sir[i]=='N'){
            y++;
        }
        if(sir[i]=='S'){
            y--;
        }
        if(sir[i]=='V'){
            x--;
        }
        if(sir[i]=='E'){
            x++;
        }
    }
    if(rez<0){
        rez=-rez-n;
        s=1;
    }
    g<<maxx-minx-1<<' '<<maxy-miny-1<<' '<<s<<' '<<rez<<'\n';
    f.close();
    g.close();
}
