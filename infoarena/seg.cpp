
#include <bits/stdc++.h>
#define NMAX 17
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream fi("seg.in");
ofstream fo("seg.out");

pair<double,double> sgm[NMAX+1][2];

int n,t,nrst;
double dp[(1<<16)][NMAX][2];
double d[NMAX][NMAX][2][2];
double ret;

void read(){
    fi>>n;
    for(int i=0;i<n;i++){
        fi>>sgm[i][0].first>>sgm[i][0].second>>sgm[i][1].first>>sgm[i][1].second;
    }
}

double dist(pair<double,double> a,pair<double,double> b){
    return (double)sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

double hamilton(){
    if(n==1){
        return 0;
    }
    nrst=(1<<(n-1))-1;
    for(int st=0;st<=nrst;st++){
        for(int i=0;i<n;i++){
            dp[st][i][1]=dp[st][i][0]=MAXVAL;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int c1=0;c1<2;c1++){
                for(int c2=0;c2<2;c2++){
                    d[i][j][c1][c2]=dist(sgm[i][c1],sgm[j][c2]);
                    d[j][i][c2][c1]=d[i][j][c1][c2];
                }
            }
        }
    }
    dp[0][0][0]=0;
    for(int st=0;st<=nrst;st++){
        for(int i=0;i<n;i++){
            if(i==0||(((1<<(i-1))&st)&&dp[st][i][0]!=MAXVAL)){
                for(int k=1;k<n;k++){
                    if(((1<<(k-1))&st)==0){
                        for(int c1=0;c1<2;c1++){
                            if(i==0&&c1==1){
                                break;
                            }
                            for(int c2=0;c2<2;c2++){
                                dp[st+(1<<(k-1))][k][c2]=min(dp[st+(1<<(k-1))][k][c2],dp[st][i][c1]+d[i][k][c1][1-c2]);
                            }
                        }
                    }
                }
            }
        }
    }
    ret=MAXVAL;
    for(int i=1;i<n;i++){
        for(int c1=0;c1<2;c1++){
            ret=min(ret,dp[nrst][i][c1]+d[i][0][c1][1]);
        }
    }
    return ret;
}

int main(){
    fi>>t;
    while(t--){
        read();
        fo<<fixed<<setprecision(7)<<hamilton()<<'\n';
    }
    fi.close();
    fo.close();
}
