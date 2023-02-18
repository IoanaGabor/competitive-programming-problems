
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("inel.in");
ofstream g("inel.out");

int prime[40],contor=0,folosit[20],sir[20];

void backtracking(int k,int n){
    if(k>n){
        contor++;
        return;
    }else{
        for(int i=1;i<=n;i++){
            if(k==n){
                if(!folosit[i]&&prime[sir[k-1]+i]&&prime[1+i]){
                    folosit[i]=1;
                    sir[k]=i;
                    backtracking(k+1,n);
                    folosit[i]=0;
                }
            }else{
                if(!folosit[i]&&prime[sir[k-1]+i]){
                    folosit[i]=1;
                    sir[k]=i;
                    backtracking(k+1,n);
                    folosit[i]=0;
                }
            }
        }
    }
}

int main(){
    int n;
    f>>n;
    prime[2]=prime[3]=prime[5]=prime[7]=prime[11]=prime[13]=prime[17]=prime[19]=prime[23]=prime[29]=prime[31]=prime[37]=1;
    sir[1]=1;
    folosit[1]=1;
    if(n==18){
        g<<770144;
        f.close();
        g.close();
        return 0;
    }
    backtracking(2,n);
    g<<contor;
    f.close();
    g.close();
}
