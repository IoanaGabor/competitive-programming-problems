
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("coins.in");
ofstream g("coins.out");

int t,sir[25],nr,suma;
int ok[(1<<22)+5];

int constr(){
    int aux=0,ult;
    for(int i=0;i<22;i++){
        aux+=(1<<i);
        ok[aux]=1;
    }
    for(int i=0;i<(1<<22);i++){
        if(!ok[i]){
            ult=-1;
            for(int j=0;j<22;j++){
                if(((i>>j)&1)==1){
                    if(ult!=-1){
                        if(ok[i+(1<<ult)-(1<<j)]==0){
                            ok[i]=1;
                            break;
                        }
                    }
                }else{
                    ult=j;
                }
            }
        }
    }
}

int main(){
    constr();
    f>>t;
    while(t--){
        nr=0;
        int cnt=0;
        for(int i=0;i<22;i++){
            f>>sir[i];
            cnt+=sir[i];
            nr=nr+(1<<i)*sir[i];
        }
        if(ok[nr]==1){
            suma+=cnt;
        }
    }
    g<<suma;
}
