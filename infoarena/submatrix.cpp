
#include <bits/stdc++.h>
#define NMAX 300

using namespace std;

ifstream fi("submatrix.in");
ofstream fo("submatrix.out");

int n,m,k,nrd;
int mat[NMAX+5][NMAX+5];
map<int,int> mp;
int frecv[NMAX*NMAX+5],rez;

void solve(int x,int y){
    for(int i=0;i<=n*m;i++){
        frecv[i]=0;
    }
    int cntd=0,l=0;
    while(x<=n&&y<=m){
        l++;
        for(int i=x-l+1;i<=x;i++){
            frecv[mat[i][y]]++;
            if(frecv[mat[i][y]]==1){
                cntd++;
            }
        }
        for(int i=y-l+1;i<y;i++){
            frecv[mat[x][i]]++;
            if(frecv[mat[x][i]]==1){
                cntd++;
            }
        }
        while(cntd>k){
            for(int i=x-l+1;i<=x;i++){
                frecv[mat[i][y-l+1]]--;
                if(frecv[mat[i][y-l+1]]==0){
                    cntd--;
                }
            }
            for(int i=y-l+2;i<=y;i++){
                frecv[mat[x-l+1][i]]--;
                if(frecv[mat[x-l+1][i]]==0){
                    cntd--;
                }
            }
            l--;   
        }
        rez=max(rez,l);
        x++,y++;
    }
}

int main(){
    fi>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            fi>>mat[i][j];            
            if(mp[mat[i][j]]==0){
                mp[mat[i][j]]=++nrd;
            }
            mat[i][j]=mp[mat[i][j]];
        }
    }    
    for(int i=1;i<=n;i++){
        solve(i,1);
    }
    for(int i=1;i<=m;i++){
        solve(1,i);
    }
    fo<<rez<<'\n';
    fi.close();
    fo.close();
}