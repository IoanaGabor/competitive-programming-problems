
#include <iostream>
#include <fstream>
#define NMAX 1000000

using namespace std;

ifstream f("paranteze2.in");
ofstream g("paranteze2.out");

int dp[NMAX+5],stiva[NMAX+5],vf;
long long rez;
char sir[NMAX+5];

int main(){
    f>>sir;
    for(int i=0;sir[i];i++){
        if(sir[i]=='('){
            stiva[++vf]=i;
        }else if(sir[i]==')'){
            if(vf!=0){
                if(stiva[vf]==0){
                    dp[i]=1;
                }else{
                    dp[i]=dp[stiva[vf]-1]+1;
                }
                vf--;
            }
        }
        rez+=1LL*dp[i];
    }
    g<<rez;
    f.close();
    g.close();
}
