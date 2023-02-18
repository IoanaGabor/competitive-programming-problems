
#include <bits/stdc++.h>
#define NMAX 200000
#define MOD 1000000007

using namespace std;

ifstream fi("pastile.in");
ofstream fo("pastile.out");

int ciur[NMAX+5];
int comp[NMAX+5];
int nrp[NMAX+5];
int cnt2;
int cnt;
int fv[NMAX+5];
int a[NMAX+5],n;
long long calcul[NMAX+5];
long long sol;
long long prod;
int vmin,vmax;
int egale;

long long lgput(long long a,int b){
    long long ret=1;
    while(b){
        if(b%2==0){
            b/=2;
            a=(1LL*a*a)%MOD;
        }else{
            b--;
            ret=(1LL*ret*a)%MOD;
        }
    }
    return ret;
}

long long calc(int p){
    if(egale){
        return lgput(vmin/p,n);
    }else{
        long long ret=1;
        for(int i=0;i<=vmax;i+=p){
            if(i!=0){
                ret=(1LL*ret*lgput(i/p,fv[min(i+p-1,vmax)]-fv[i-1]))%MOD;
            }
        }
        /*
        for(int i=1;i<=n;i++){
            if(a[i]/p==0){
                return 0;
            }
            ret=(1LL*ret*(a[i]/p))%MOD;
        }*/
        calcul[p]=ret;
        return ret;
    }
}

int main(){
    fi>>n;
    vmin=NMAX;
    prod=1;
    for(int i=1;i<=n;i++){
        fi>>a[i];
        vmin=min(a[i],vmin);
        vmax=max(a[i],vmax);
        prod=(prod*a[i])%MOD;
        fv[a[i]]++;
    }
    for(int i=1;i<=vmax;i++){
        fv[i]+=fv[i-1];
    }
    egale=1;
    for(int i=1;i<=n;i++){
        if(vmin!=a[i]){
            egale=0;
        }
    }
    for(int i=1;i<=vmin;i++){
        comp[i]=0;
    }
    for(int i=2;i<=vmin;i++){
        if(!ciur[i]){
            ciur[i]=i;
            nrp[i]=1;
            for(int j=2*i;j<=vmin;j+=i){
                if(!ciur[j]){
                    ciur[j]=i;
                }
            }
        }
    }
    for(int j=2;j<=vmin;j++){
        if((j/ciur[j])%ciur[j]==0){
            comp[j]=1;
        }else{
            comp[j]=comp[j/ciur[j]];
        }
    }
    ciur[1]=1;
    for(int i=1;i<=vmin;i++){
        if(!comp[i]){
            if(i==1){
                nrp[i]=0;
            }else{
                nrp[i]=nrp[i/ciur[i]]+1;
            }
            if(nrp[i]%2==0){
                sol=(sol+calc(i))%MOD;
            }else{
                sol=(sol-calc(i)+MOD)%MOD;
            }
        }
    }
    fo<<sol<<'\n';
    fi.close();
    fo.close();
}
