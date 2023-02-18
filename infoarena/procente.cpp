
#include <iostream>
#include <fstream>
#define NMAX 80

using namespace std;

ifstream f("procente.in");
ofstream g("procente.out");

int n,x,a,b;
char ch;
long long dp[2*NMAX+5][2*NMAX+5][NMAX+5];
int doi[]={0,0,0,0,1,1,1,2,2,2,3,3,3,4,4,5,5,6,7};
int cinci[]={0,1,2,3,0,1,2,0,1,2,0,1,2,0,1,0,1,0,0};

int main(){
    f>>n;
    f>>ch>>x;
    if(ch=='-'){
        x=100-x;
    }else{
        x=100+x;
    }
    while(x%2==0){
        a++;
        x=x/2;
    }
    while(x%5==0){
        b++;
        x=x/5;
    }
    if(x!=1){
        g<<0<<'\n';
        return 0;
    }
    dp[0][0][0]=1;
    for(int ind=0;ind<19;ind++){
        for(int i=0;i<=2*n-a&&i+doi[ind]<=2*n-a;i++){
            for(int j=0;j<=2*n-b&&j+cinci[ind]<=2*n-b;j++){
                for(int k=0;k<n;k++){
                    if(i+doi[ind]<=2*n&&j+cinci[ind]<=2*n){
                        dp[i+doi[ind]][j+cinci[ind]][k+1]+=dp[i][j][k];
                    }
                }
            }
        }
    }
    g<<dp[2*n-a][2*n-b][n-1];
    f.close();
    g.close();
}
