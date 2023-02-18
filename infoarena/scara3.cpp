
#include <bits/stdc++.h>
#define NMAX 1200
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream f("scara3.in");
ofstream g("scara3.out");

int n,k,l,t,c;
int gratis[NMAX+5];
int cost[NMAX+5];
pair<int,int> dp[NMAX+5];

bool comp(pair <int,int> a, pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}

int main(){
    f>>n>>k;
    for(int i=1;i<=k;i++){
        f>>t>>c;
        gratis[t]=max(gratis[t],c);
    }
    f>>l;
    for(int i=1;i<=l;i++){
        f>>t>>c;
        cost[t]=max(cost[t],c);
    }
    for(int i=1;i<=n;i++){
        dp[i]=make_pair(MAXVAL,MAXVAL);
    }
    for(int i=0;i<n;i++){
        if(comp(make_pair(dp[i].first+1,dp[i].second),dp[i+1])){
            dp[i+1]=make_pair(dp[i].first+1,dp[i].second);
        }
        if(gratis[i]&&(cost[i]==0||(cost[i]*2<=gratis[i]))){
            for(int j=i+1;j<=n&&j-i<=gratis[i];j++){
                if(comp(make_pair(dp[i].first+1,dp[i].second),dp[j])){
                    dp[j]=make_pair(dp[i].first+1,dp[i].second);
                }
            }
        }else if(gratis[i]&&cost[i]){
            for(int j=i+1;j<=n&&j-i<=gratis[i];j++){
                if(comp(make_pair(dp[i].first+1,dp[i].second),dp[j])){
                    dp[j]=make_pair(dp[i].first+1,dp[i].second);
                }
            }
            for(int j=i+gratis[i]+1;j<=n&&j<=i+2*cost[i];j++){
                if(comp(make_pair(dp[i].first+1,dp[i].second+(j-i+1)/2),dp[j])){
                    dp[j]=make_pair(dp[i].first+1,dp[i].second+(j-i+1)/2);
                }
            }
        }else if(cost[i]){
            for(int j=i+1;j<=n&&j-i<=2*cost[i];j++){
                if(comp(make_pair(dp[i].first+1,dp[i].second+(j-i+1)/2),dp[j])){
                    dp[j]=make_pair(dp[i].first+1,dp[i].second+(j-i+1)/2);
                }
            }
        }
    }
    g<<dp[n].first<<' '<<dp[n].second<<'\n';
    f.close();
    g.close();
}


































