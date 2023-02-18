
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("br.in");
ofstream g("br.out");

int sume[30005],n,t,k,x;

int cauta(){
    int pas=1<<14,i=k;
    while(pas){
        if(i+pas<=2*n&&sume[i+pas]-sume[k-1]<=x){
            i+=pas;
        }
        pas=pas/2;
    }
    return i-k+1;
}

int main(){
    f>>n>>t;
    for(int i=1;i<=n;i++){
        f>>sume[i];
        sume[n+i]=sume[i];
    }
    for(int i=2;i<=2*n;i++){
        sume[i]+=sume[i-1];
    }
    while(t--){
        f>>k>>x;
        if(x>=sume[n]){
            g<<n<<'\n';
        }else if(x<sume[k]-sume[k-1]){
            g<<0<<'\n';
        }else{
            g<<cauta()<<'\n';
        }
    }
    f.close();
    g.close();
}
