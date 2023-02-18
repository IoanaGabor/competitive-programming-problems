#include <bits/stdc++.h>
#define NMAX 50

using namespace std;

ifstream fi("aleatoare.in");
ofstream fo("aleatoare.out");

int c,t;
int n;
int mat[NMAX*2+5][NMAX+5];
int inters[NMAX*2+5][NMAX*2+5];
int sol[NMAX+5][NMAX+5];
pair<int,int> per[NMAX*NMAX+5];

int choose_first(int a,int b){
    for(int i=1;i<=n;i++){
        if(mat[a][i]<mat[b][i]){
            return a;
        }else if(mat[a][i]>mat[b][i]){
            return b;
        }
    }
}

int the_other_one(int val,pair<int,int> a){
    if(a.first==val){
        return a.second;
    }
    return a.first;
}

void init(){
    for(int i=1;i<=n*n;i++){
        per[i]={0,0};
    }
}

int main(){
    fi>>c>>t;
    if(c==1){
        while(t--){
            fi>>n;
            init();
            for(int i=1;i<=2*n;i++){
                for(int j=1;j<=n;j++){
                    fi>>mat[i][j];
                    if(per[mat[i][j]].first){
                        per[mat[i][j]].second=i;
                    }else{
                        per[mat[i][j]].first=i;
                    }
                }
            }
            for(int i=1;i<=n*n;i++){
                inters[per[i].first][per[i].second]=inters[per[i].second][per[i].first]=i;
            }
            sort(mat[per[1].first]+1,mat[per[1].first]+n+1);
            sort(mat[per[1].second]+1,mat[per[1].second]+n+1);
            int ind1=choose_first(per[1].first,per[1].second);
            int ind2=the_other_one(ind1,per[1]);
            for(int i=1;i<=n;i++){
                sol[1][i]=mat[ind1][i];
            }
            for(int i=1;i<=n;i++){
                sol[i][1]=mat[ind2][i];
            }
            for(int i=2;i<=n;i++){
                for(int j=2;j<=n;j++){
                    sol[i][j]=inters[the_other_one(ind1,per[sol[1][j]])][the_other_one(ind2,per[sol[i][1]])];
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    fo<<sol[i][j]<<' ';
                }
                fo<<'\n';
            }
        }
    }else{
        while(t--){
            fi>>n;
            sol[1][1]=1;
            sol[1][2]=n*n-2*n+3;
            for(int i=n;i>=3;i--){
                sol[1][i]=n*n-(n-i);
            }
            for(int j=n;j>=2;j--){
                sol[j][1]=n*n-n+2-(n-j);
            }
            int cnt=n*n-2*n+2;
            for(int i=2;i<=n;i++){
                for(int j=2;j<=n;j++){
                    sol[i][j]=cnt;
                    cnt--;
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    fo<<sol[i][j]<<' ';
                }
                fo<<'\n';
            }
        }
    }
    fi.close();
    fo.close();
}