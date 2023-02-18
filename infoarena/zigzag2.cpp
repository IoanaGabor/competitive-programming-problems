
#include <iostream>
#include <fstream>
#define NMAX 1000000

using namespace std;

ifstream f("zigzag2.in");
ofstream g("zigzag2.out");

int n,k,sir[NMAX+5],gresit[NMAX+5],suma[NMAX+5],aux;
long long cnt;

int cauta(int poz){
    int pas=1<<20;
    int ret=poz+2;
    while(pas){
        if(ret+pas<=n&&suma[ret+pas]+aux<=k){
            ret+=pas;
        }
        pas>>=1;
    }
    return ret;
}

int main(){
    f>>n>>k;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    for(int i=3;i<=n;i++){
        if((sir[i-2]<sir[i-1]&&sir[i-1]>sir[i])||(sir[i-2]>sir[i-1]&&sir[i-1]<sir[i])){
            gresit[i]=0;
        }else{
            gresit[i]=1;
        }
        suma[i]=suma[i-1]+gresit[i];
    }
    for(int i=1;i<=n;i++){
        aux=-suma[i-1];
        if(gresit[i]){
            aux--;
        }
        if(gresit[i+1]){
            aux--;
        }
        if(i+2<=n){
            int j=cauta(i);
            cnt+=1LL*(j-i-1);
        }
    }
    g<<cnt<<'\n';
    f.close();
    g.close();
}
