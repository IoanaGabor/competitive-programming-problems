
#include <iostream>
#include <fstream>
#define NMAX 100000
#define MAXVAL (1LL<<29)-1

using namespace std;

ifstream f("sunmihai.in");
ofstream g("sunmihai.out");

int n,a,b,c,dp[3][NMAX+5],ultima[105],ultimaint[105],minim=MAXVAL;
pair<int,int> sir[NMAX+5];

int main(){
    f>>n>>a>>b>>c;
    for(int i=1;i<=n;i++){
        f>>sir[i].first>>sir[i].second;
    }
    dp[1][1]=a;
    ultima[sir[1].second]=1;
    ultimaint[sir[1].first]=1;
    minim=-b;
    for(int i=2;i<=n;i++){
        dp[1][i]=dp[0][i]=MAXVAL;
        ///scot si intorc
        if(ultima[sir[i].first]){
            dp[0][i]=min(dp[0][i],dp[0][ultima[sir[i].first]]+b*(i-ultima[sir[i].first]-1));
        }
        if(ultima[sir[i].second]){
            dp[1][i]=min(dp[1][i],dp[0][ultima[sir[i].second]]+b*(i-ultima[sir[i].second]-1)+a);
        }
        if(ultimaint[sir[i].first]){
            dp[0][i]=min(dp[0][i],dp[1][ultimaint[sir[i].first]]+b*(i-ultimaint[sir[i].first]-1));
        }
        if(ultimaint[sir[i].second]){
            dp[1][i]=min(dp[1][i],dp[1][ultimaint[sir[i].second]]+b*(i-ultimaint[sir[i].second]-1)+a);
        }
        ///adaug
        dp[0][i]=min(dp[0][i],min(dp[0][i-1],dp[1][i-1])+c);
        dp[1][i]=min(dp[1][i],min(dp[0][i-1],dp[1][i-1])+c+a);
        dp[0][i]=min(dp[0][i],minim+(i-1)*b+c);
        dp[1][i]=min(dp[1][i],minim+(i-1)*b+c+a);
        if((!ultima[sir[i].second])||dp[0][i]<=dp[0][ultima[sir[i].second]]+b*(i-ultima[sir[i].second])){
            ultima[sir[i].second]=i;
        }
        if((!ultimaint[sir[i].first])||dp[1][i]<=dp[1][ultimaint[sir[i].first]]+b*(i-ultimaint[sir[i].first])){
            ultimaint[sir[i].first]=i;
        }
        minim=min(minim,dp[0][i]-i*b);
        minim=min(minim,dp[1][i]-i*b);
    }
    g<<min(dp[0][n],dp[1][n]);
    f.close();
    g.close();
}
