
#include <iostream>
#include <fstream>
#include <string>
#define NMAX 100000
#define MOD 1000000007

using namespace std;

ifstream f("calc.in");
ofstream g("calc.out");

int cerinta,n,dp[NMAX+5],urm1=-1,urm0=-1;
string config;

int main(){
    f>>cerinta>>n>>config;
    if(cerinta==1){
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])%MOD;
        }
        g<<dp[n];
    }else{
        if(n==1){
            g<<-1<<'\n'<<-1<<'\n';
        }else if(config[n-1]=='1'&&config[n-2]=='0'){
            for(int i=n-3;i>=0;i--){
                if(config[i]=='1'){
                    urm1=i;
                    break;
                }
            }
            if(urm1==-1){
                g<<-1<<'\n';
                config[n-1]='0';
                config[n-2]='0';
                config[n-3]='1';
                g<<config<<'\n';
            }else{
                config[urm1]='0';
                for(int i=urm1+2;i<=n-1;i++){
                    config[i]='1';
                }
                g<<config<<'\n';
                for(int i=urm1+2;i<=n-1;i++){
                    config[i]='0';
                }
                config[urm1]='1';
                config[n-2]='0';
                config[n-1]='0';
                config[n-3]='1';
                g<<config<<'\n';
            }
        }else if(config[n-1]=='1'){
            for(int i=n-2;i>=0;i--){
                if(config[i]=='0'){
                    urm0=i;
                    break;
                }
            }
            if(urm0==-1){
                config[n-1]=config[n-2]='0';
                g<<config<<'\n';
                g<<-1<<'\n';
            }else if((n-1-urm0)%2==0){
                config[n-1]=config[n-2]='0';
                g<<config<<'\n';
                config[n-1]=config[n-2]='1';
                for(int i=urm0+1;i<=n-1;i++){
                    config[i]='0';
                }
                config[urm0-1]='1';
                config[n-1]='1';
                g<<config<<'\n';
            }else if((n-1-urm0)%2==1){
                config[n-1]=config[n-2]='0';
                g<<config<<'\n';
                config[n-1]=config[n-2]='1';
                for(int i=urm0+1;i<=n-1;i++){
                    config[i]='0';
                }
                config[urm0-1]='1';
                config[n-1]='0';
                g<<config<<'\n';
            }
        }else{
            for(int i=n-3;i>=0;i--){
                if(config[i]=='1'){
                    urm1=i;
                    break;
                }
            }
            if(urm1==-1){
                g<<-1<<'\n';
                config[n-1]=config[n-2]='1';
                g<<config<<'\n';
            }else{
                config[urm1]='0';
                config[n-1]='1';
                for(int i=urm1+2;i<=n-1;i++){
                    config[i]='1';
                }
                g<<config<<'\n';
                for(int i=urm1+2;i<=n-1;i++){
                    config[i]='0';
                }
                config[urm1]='1';
                config[n-1]=config[n-2]='1';
                g<<config<<'\n';
            }
        }
    }
    f.close();
    g.close();
}
