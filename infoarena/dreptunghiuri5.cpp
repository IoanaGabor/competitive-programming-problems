
#include <bits/stdc++.h>
#define NMAX 1000

using namespace std;

ifstream fi("dreptunghiuri5.in");
ofstream fo("dreptunghiuri5.out");

int n,m;
int mat[NMAX+5][NMAX+5];
int he[NMAX+5];
int le[NMAX+5],ri[NMAX+5];
int st[NMAX+5],top;
int jos[NMAX+5];

set<pair<pair<int,int>,pair<int,int> > > s;

void read(){
    fi>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            fi>>mat[i][j];
        }
    }
}

void update_he(int l){
    for(int j=1;j<=m;j++){
        if(mat[l][j]==1){
            he[j]=0;
        }else{
            he[j]++;
        }
        if(l==n){
            jos[j]=j;
        }else{
            jos[j]=jos[j-1]+mat[l+1][j];
        }
    }
}

void get_le_ri(){
    st[++top]=0;
    he[m+1]=he[0]=-1;
    for(int i=1;i<=m;i++){
        while(he[st[top]]>he[i]){
            top--;
        }
        if(he[st[top]]==he[i]){
            le[i]=-1;
        }else{
            le[i]=st[top];
        }
        st[++top]=i;
    }
    top=0;
    st[++top]=m+1;
    for(int i=m;i>=1;i--){
        while(he[st[top]]>=he[i]){
            top--;
        }
        ri[i]=st[top];
        st[++top]=i;
    }
}

void solve(){
    int sol=0;
    for(int i=1;i<=n;i++){
        update_he(i);
        get_le_ri();
        for(int j=1;j<=m;j++){
            if(he[j]>0&&le[j]!=-1&&ri[j]-le[j]-1>0&&jos[ri[j]-1]-jos[le[j]]!=0){
                sol++;
                //cout<<le[j]+1<<' '<<ri[j]-1<<' '<<i<<' '<<he[j]<<'\n';
            }
        }
    }
    fo<<sol;
}

int main(){
    read();
    solve();
    fi.close();
    fo.close();
}