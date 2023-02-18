#include <bits/stdc++.h>
#define NMAX 50211
#define LOG 16

using namespace std;

ifstream fi("ghicit.in");
ofstream fo("ghicit.out");

struct ceva{
    int nr[2],poz;
} L[NMAX+5];
int P[LOG+5][NMAX+5];
int n,cnt;
char sir[NMAX+5];
int ord[NMAX+5];

bool crit(ceva a,ceva b){
    if(a.nr[0]==b.nr[0]){
        return a.nr[1]<b.nr[1];
    }
    return a.nr[0]<b.nr[0];
}

void constr_suffixarray(){
    fi.getline(sir,NMAX+1);
    n=strlen(sir);
    for(int i=0;i<n;i++){
        P[0][i]=sir[i]-'a';
    }
    for(int pas=1;pas/2<n;pas<<=1){
        cnt++;
        for(int i=0;i<n;i++){
            L[i].nr[0]=P[cnt-1][i];
            if(i+pas<n){
                L[i].nr[1]=P[cnt-1][i+pas];
            }else{
                L[i].nr[1]=-1;
            }
            L[i].poz=i;
        }
        sort(L,L+n,crit);
        for(int i=0;i<n;i++){
            if(i>0&&L[i].nr[0]==L[i-1].nr[0]&&L[i].nr[1]==L[i-1].nr[1]){
                P[cnt][L[i].poz]=P[cnt][L[i-1].poz];
            }else{
                P[cnt][L[i].poz]=i;
            }
        }
    }
    for(int i=0;i<n;i++){
        ord[P[cnt][i]]=i;
    }
}

int search_lcp(int x,int y){
    int pas=(1<<(cnt-1)),ret=0,p=cnt-1;
    while(pas&&x<n&&y<n){
        if(P[p][x]==P[p][y]){
            ret+=pas;
            x+=pas,y+=pas;
        }
        pas>>=1;
        p--;
    }
    return ret;
}

int solve(){
    int sol=n-ord[0];
    int aux;
    for(int i=1;i<n;i++){
        aux=search_lcp(ord[i-1],ord[i]);
        sol+=n-ord[i]-aux;
    }
    return sol;
}

int main(){
    constr_suffixarray();
    fo<<solve()<<'\n';
    fi.close();
    fo.close();
}