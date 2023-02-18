
#include <iostream>
#include <fstream>
#include <algorithm>
#define NMAX 46

using namespace std;

ifstream f("triunghi5.in");
ofstream g("triunghi5.out");

int v,n,k,sir[NMAX+5],rez[2*NMAX+5],cnt;

int main(){
    f>>v>>n>>k;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    sort(sir+1,sir+n+1);
    if(v==1){
        rez[1]=sir[1];
        g<<rez[1]<<' ';
        for(int i=2;i<=k;i++){
            rez[i]=rez[i-1]+rez[i-2];
            g<<rez[i]<<' ';
        }

    }else{
        int i;
        if(sir[1]==sir[2]){
            rez[1]=rez[2]=sir[1];
            i=3;
        }else if(sir[1]==1){
            rez[1]=rez[2]=1;
            i=2;
        }else{
            rez[1]=rez[0]=1;
            i=1;
        }
        cnt=2;
        while(cnt<=k){
            rez[cnt]=rez[cnt-1]+rez[cnt-2];
            if(i<=n&&(((k-cnt)==(n-i))||rez[cnt]+rez[cnt-1]>sir[i])){
                rez[cnt]=sir[i];
                i++;
            }
            cnt++;
        }
        for(int i=1;i<=k;i++){
            g<<rez[i]<<' ';
        }
    }
    f.close();
    g.close();
}
