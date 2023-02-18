
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("banda.in");
ofstream g("banda.out");

int n,k,c,s,px,py,fix,fiy;

void unu(){
    px=1;
    py=s;
    fix=1;
    fiy=k;
    for(int i=n;i>=1;i--){
        if((1<<(i-1))<fiy&&(1<<(i-1))>=py){
            px=(1<<(n-i))+(1<<(n-i))-px+1;
            py=(1<<(i-1))-py+1;
            fiy-=(1<<(i-1));
        }else if((1<<(i-1))<py&&(1<<(i-1))>=fiy){
            px=(1<<(n-i))+(1<<(n-i))-px+1;
            py-=(1<<(i-1));
            py=(1<<(i-1))-py+1;
        }else if(fiy>(1<<(i-1))&&py>(1<<(i-1))){
            fiy-=(1<<(i-1));
            py-=(1<<(i-1));
        }
    }
}

void doi(){
    px=s;
    py=1;
    for(int i=1;i<=n;i++){
        if((k-1)&(1<<(i-1))){
            if(px>(1<<(n-i))){
                px-=(1<<(n-i));
                px=(1<<(n-i))-px+1;
                py=(1<<(i-1))-py+1;
            }else{
                py+=(1<<(i-1));
            }
        }else{
            if(px>(1<<(n-i))){
                px-=(1<<(n-i));
                px=(1<<(n-i))-px+1;
                py=(1<<(i-1))+(1<<(i-1))-py+1;
            }
        }
    }
}

int main(){
    f>>n>>k>>c>>s;
    if(c==1){
        unu();
        g<<px<<'\n';
    }else{
        doi();
        g<<py<<'\n';
    }
    f.close();
    g.close();
}
