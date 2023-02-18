
#include <iostream>
#include <fstream>
#define NMAX  4000000
#define RAD 2000

using namespace std;

ifstream f("xp.in");
ofstream g("xp.out");

unsigned long long n,a1,b1,p,q,prod,val,rez,bucket[RAD+5],stanga[RAD+5],dreapta[RAD+5],mini[RAD+5],mst[RAD+5],mdr[RAD+5],cnt,k;

unsigned long long maxim(unsigned long long x,unsigned long long y){
    if(x>y){
        return x;
    }
    return y;
}

int main(){
    f>>n>>a1>>b1>>p>>q;
    int a=a1,b=b1,an,bn;
    prod=1;
    for(int i=1;i<=n;i++){
        val=maxim(1,((i%p)^(((a+1)&(b+1))%p))%p);
        ++cnt;
        prod=(prod*val)%q;
        if(cnt==RAD){
            bucket[++k]=prod;
            cnt=0;
            prod=1;
        }
        an=((a+p-1)^(b+1))%p;
        bn=((a+p-1)|(b+1))%p;
        a=an;
        b=bn;
    }
    if(cnt){
        bucket[++k]=prod;
        cnt=0;
        prod=1;
    }
    stanga[0]=1;
    dreapta[k+1]=1;
    for(int i=1;i<=k;i++){
        stanga[i]=(stanga[i-1]*bucket[i])%q;
        dreapta[k-i+1]=(dreapta[k-i+2]*bucket[k-i+1])%q;
    }
    a=a1,b=b1;
    k=0;
    for(int i=1;i<=n;i++){
        val=maxim(1,((i%p)^(((a+1)&(b+1))%p))%p);
        mini[++cnt]=val;
        if(cnt==RAD){
            k++;
            mst[0]=mdr[cnt+1]=1;
            for(int j=1;j<=cnt;j++){
                mst[j]=(mst[j-1]*mini[j])%q;
                mdr[cnt-j+1]=(mdr[cnt-j+2]*mini[cnt-j+1])%q;
            }
            for(int j=1;j<=cnt;j++){
                rez^=(((stanga[k-1]*dreapta[k+1])%q)*((mst[j-1]*mdr[j+1])%q))%q;
            }
            cnt=0;
        }
        an=((a+p-1)^(b+1))%p;
        bn=((a+p-1)|(b+1))%p;
        a=an;
        b=bn;
    }
    if(cnt){
        k++;
        mst[0]=mdr[cnt+1]=1;
        for(int j=1;j<=cnt;j++){
            mst[j]=(mst[j-1]*mini[j])%q;
            mdr[cnt-j+1]=(mdr[cnt-j+2]*mini[cnt-j+1])%q;
        }
        for(int j=1;j<=cnt;j++){
            rez^=(((stanga[k-1]*dreapta[k+1])%q)*((mst[j-1]*mdr[j+1])%q))%q;
        }
        cnt=0;
    }
    g<<rez<<'\n';
    f.close();
    g.close();
}
