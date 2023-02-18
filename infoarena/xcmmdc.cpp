
#include <bits/stdc++.h>
#define NMAX 1000

using namespace std;

ifstream fi("xcmmdc.in");
ofstream fo("xcmmdc.out");

int n,m,k,pm,lm;
int mat[NMAX+5][NMAX+5];
int dp[10][NMAX+5][NMAX+5];
int logdoi[NMAX+5];
int q,l;
int d1,d2;
int p1,p2;
int rez[NMAX+5];

int cmmdc(int a,int b){
    int c;
    while(b){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int cmmdc_submat(int x,int y,int l){
    int p=logdoi[l];
    int d1=cmmdc(dp[p][x][y],dp[p][x+l-(1<<p)][y]);
    int d2=cmmdc(dp[p][x+l-(1<<p)][y+l-(1<<p)],dp[p][x][y+l-(1<<p)]);
    return cmmdc(d1,d2);
}

int cauta1(int x,int y){
    int pas=(1<<pm),ret=-1;
    while(pas){
        if(ret+pas<=lm&&x+ret+pas-1<=n&&y+ret+pas-1<=m&&cmmdc_submat(x,y,ret+pas)>k){
            ret+=pas;
        }
        pas>>=1;
    }
    return ret;
}

int cauta2(int x,int y){
    int pas=(1<<pm),ret=0;
    while(pas){
        if(ret+pas<=lm&&x+ret+pas-1<=n&&y+ret+pas-1<=m&&cmmdc_submat(x,y,ret+pas)>=k){
            ret+=pas;
        }
        pas>>=1;
    }
    return ret;
}

int main(){
    fi>>n>>m>>k>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            fi>>mat[i][j];
            dp[0][i][j]=mat[i][j];
        }
    }
    pm=0;
    lm=min(m,n);
    while((1<<pm)<lm){
        pm++;
    }
    pm--;
    for(int p=1;p<=pm;p++){
        for(int i=1;i+(1<<p)-1<=n;i++){
            for(int j=1;j+(1<<p)-1<=m;j++){
                d1=cmmdc(dp[p-1][i][j],dp[p-1][i+(1<<(p-1))][j]);
                d2=cmmdc(dp[p-1][i][j+(1<<(p-1))],dp[p-1][i+(1<<(p-1))][j+(1<<(p-1))]);
                dp[p][i][j]=cmmdc(d1,d2);
            }
        }
    }
    logdoi[1]=0;
    for(int i=2;i<=lm;i++){
        logdoi[i]=logdoi[(i>>1)]+1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mat[i][j]>=k){
                p1=cauta1(i,j);
                p2=cauta2(i,j);
                if(p1+1<=p2){
                    rez[p1+1]+=1;
                    rez[p2+1]-=1;
                }
            }
        }
    }
    for(int i=1;i<=lm;i++){
        rez[i]+=rez[i-1];
    }
    while(q--){
        fi>>l;
        fo<<rez[l]<<'\n';
    }
    fi.close();
    fo.close();
}