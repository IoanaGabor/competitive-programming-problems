
#include <iostream>
#include <fstream>
#include <cstring>
#define NMAX 1000

using namespace std;

ifstream f("fence.in");
ofstream g("fence.out");

long long cerinta,n,m,mat[NMAX+5][NMAX+5],v,xn,xs,ye,yv,sumatot,aux[NMAX+5][NMAX+5],suma[NMAX+5][NMAX+5],dp[NMAX+5][NMAX+5],na,ma;

void ariemin(){
    for(int i=1;i<yv;i++){
        for(int j=1;j<xn;j++){
            sumatot-=mat[i][j];
        }
    }
    for(int i=1;i<ye;i++){
        for(int j=xn+1;j<=m;j++){
            sumatot-=mat[i][j];
        }
    }
    for(int i=yv+1;i<=n;i++){
        for(int j=1;j<xs;j++){
            sumatot-=mat[i][j];
        }
    }
    for(int i=ye+1;i<=n;i++){
        for(int j=xs+1;j<=m;j++){
            sumatot-=mat[i][j];
        }
    }
}

void rez_submatrice(){
    //cout<<na<<' '<<ma<<'\n';
    for(int i=1;i<=na;i++){
        for(int j=1;j<=ma;j++){
            suma[i][j]=suma[i][j-1]+aux[i][j];
      //      cout<<aux[i][j]<<' ';
        }
        //cout<<'\n';
    }
    //cout<<'\n';
    memset(dp,0,sizeof(dp));
    long long rez=0;
    for(int i=1;i<=na;i++){
        for(int j=ma;j>=1;j--){
            if(j!=ma){
                dp[i][j]=max(dp[i][j+1],suma[i][j]+dp[i-1][j]);
            }else{
                dp[i][j]=suma[i][j]+dp[i-1][j];
            }
            rez=max(rez,dp[i][j]);
        }
    }
    //cout<<rez<<"************"<<'\n';
    sumatot+=rez;
}

void doi(){
    na=yv-1;
    ma=xn-1;
    for(int i=1;i<yv;i++){
        for(int j=1;j<xn;j++){
            aux[ma-j+1][na-i+1]=mat[i][j];
        }
    }
    swap(ma,na);
    rez_submatrice();
    na=ye-1;
    ma=m-xn;
    for(int i=1;i<ye;i++){
        for(int j=xn+1;j<=m;j++){
            aux[na-i+1][j-xn]=mat[i][j];
        }
    }
    rez_submatrice();
    na=n-yv;
    ma=xs-1;
    for(int i=yv+1;i<=n;i++){
        for(int j=1;j<xs;j++){
            aux[i-yv][ma-j+1]=mat[i][j];
        }
    }
    rez_submatrice();
    na=n-ye;
    ma=m-xs;
    for(int i=ye+1;i<=n;i++){
        for(int j=xs+1;j<=m;j++){
            aux[i-ye][j-xs]=mat[i][j];
        }
    }
    rez_submatrice();
}

int main(){
    f>>cerinta>>n>>m>>v>>xn>>xs>>yv>>ye;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>mat[i][j];
            mat[i][j]-=v;
            sumatot+=mat[i][j];
        }
    }
    ariemin();
    if(cerinta==1){
        g<<sumatot;
    }else{
        doi();
        g<<sumatot;
    }
    f.close();
    g.close();
}
