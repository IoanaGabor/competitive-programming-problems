
#include <bits/stdc++.h>
#define NMAX 100
#define LMAX 5000

using namespace std;

ifstream fi("search.in");
ofstream fo("search.out");

int n,t,lst;
char word[NMAX+5][LMAX+5],c;
int dp[NMAX+5][LMAX+5][30];
vector <pair<int,int>> st[LMAX+5];

void init_dp(){
    int k;
    for(int i=1;i<=n;i++){
        k=strlen((word[i]+1));
        for(int lt=0;lt<26;lt++){
            dp[i][k][lt]=-1;
        }
        for(int j=k-1;j>=0;j--){
            for(int lt=0;lt<26;lt++){
                dp[i][j][lt]=dp[i][j+1][lt];
            }
            dp[i][j][word[i][j+1]-'a']=j+1;
        }
    }
}

void search(){
    int w,p;
    for(int i=0;i<st[lst].size();i++){
        w=st[lst][i].first;
        p=st[lst][i].second;
        if(dp[w][p][c-'a']!=-1){
            st[lst+1].push_back(make_pair(w,dp[w][p][c-'a']));
        }
    }
}

int main(){
    fi>>n>>t;
    for(int i=1;i<=n;i++){
        fi>>(word[i]+1);
    }
    init_dp();
    for(int i=1;i<=n;i++){
        st[0].push_back(make_pair(i,0));
    }
    while(t--){
        fi>>c;
        if(c!='-'){
            search();
            lst++;
        }else{
            st[lst].clear();
            lst--;
        }
        fo<<st[lst].size()<<'\n';
    }
    fi.close();
    fo.close();
}