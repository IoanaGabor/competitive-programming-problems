#include <bits/stdc++.h>
#define NMAX 1000000
#define NRALPH 26

using namespace std;

ifstream fi("domenii.in");
ofstream fo("domenii.out");

int n;
long long cnt,rez;
char sir[NMAX+5];
int fr[NMAX+5][NRALPH+5];

int main(){
    fi>>n;
    fi>>(sir+1);
    for(int i=n;i>=1;i--){
        for(int j=0;j<NRALPH;j++){
            fr[i][j]=fr[i+1][j];
        }
        if(sir[i]!='.'){
            fr[i][sir[i]-'a']++;
            cnt++;
        }else{
            rez+=1LL*cnt*(cnt-1)/2;
            for(int j=0;j<NRALPH;j++){
                rez-=1LL*fr[i][j]*(fr[i][j]-1)/2;
            }
        }
    }
    fo<<rez<<'\n';
    fi.close();
    fo.close();
}