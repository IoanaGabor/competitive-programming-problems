
#include <bits/stdc++.h>
#define MOD 9973
#define MAXVAL 9000

using namespace std;

ifstream fi("numere6.in");
ofstream fo("numere6.out");

int a,b,sol;
int fact[MAXVAL+5],invfact[MAXVAL+5],fr[11];
int desc[5],cf[5]={2,3,5,7};

int putere(int b,int e){
    int ret=1;
    while(e){
        if(e%2==1){
            ret=(ret*b)%MOD;
            e--;
        }else{
            b=(b*b)%MOD;
            e/=2;
        }
    }
    return ret;
}

void numara(){
    int aux=1;
    for(int i=1;i<=9;i++){
        aux=(aux*fact[fr[i]])%MOD;
    }
    sol+=(fact[a]*putere(aux,MOD-2))%MOD;
    sol%=MOD;
}

void bkt(int k,int ramase[5],int nrtot){
    if(k>9){
        if(nrtot<=a&&ramase[0]+ramase[1]+ramase[2]+ramase[3]==0){
            fr[1]=a-nrtot;
            numara();
        }
        return;
    }
    for(int d=0;d<4;d++){
        if(k==cf[d]){
            for(int i=0;i<=ramase[d]&&nrtot+i<=a;i++){
                ramase[d]-=i;
                fr[k]=i;
                bkt(k+1,ramase,nrtot+i);
                ramase[d]+=i;
            }
            break;
        }
    }
    if(k==4){
        for(int i=0;i<=ramase[0]/2&&nrtot+i<=a;i++){
            ramase[0]-=2*i;
            fr[k]=i;
            bkt(k+1,ramase,nrtot+i);
            ramase[0]+=2*i;
        }
    }
    if(k==6){
        for(int i=0;i<=min(ramase[0],ramase[1])&&nrtot+i<=a;i++){
            ramase[0]-=i;
            ramase[1]-=i;
            fr[k]=i;
            bkt(k+1,ramase,nrtot+i);
            ramase[0]+=i;
            ramase[1]+=i;
        }
    }
    if(k==8){
        for(int i=0;i<=ramase[0]/3&&nrtot+i<=a;i++){
            ramase[0]-=3*i;
            fr[k]=i;
            bkt(k+1,ramase,nrtot+i);
            ramase[0]+=3*i;
        }
    }
    if(k==9){
        for(int i=0;i<=ramase[1]/2&&nrtot+i<=a;i++){
            ramase[1]-=2*i;
            fr[k]=i;
            bkt(k+1,ramase,nrtot+i);
            ramase[1]+=2*i;
        }
    }
}

int main(){
    fi>>a>>b;
    fact[0]=1;
    for(int i=1;i<=a;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
    for(int i=0;i<4;i++){
        while(b%cf[i]==0){
            desc[i]++;
            b/=cf[i];
        }
    }
    bkt(2,desc,0);
    fo<<sol<<'\n';
    fi.close();
    fo.close();
}
