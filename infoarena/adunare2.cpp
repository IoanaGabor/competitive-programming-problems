#include <bits/stdc++.h>
#define NMAX 100000
#define MOD 1000000007

using namespace std;

ifstream fi("adunare2.in");
ofstream fo("adunare2.out");

struct ceva{
    long long stari[6];
};
ceva arb[4*NMAX+5];
int n,q;
char ch;
int mat[4][NMAX+5];
int x,y,c;
int tr;
int cnt;

int tip(int a,int b,int c){
    if((a+b+1)%10==c&&(a+b+1)/10==1){
        return 1;
    }
    if((a+b)%10==c&&(a+b)/10==1){
        return 2;
    }
    if((a+b+1)%10==c&&(a+b+1)/10==0){
        return 3;
    }
    if((a+b)%10==c&&(a+b)/10==0){
        return 4;
    }
    return 5;
}

void create(int nod,int st,int dr){
    if(st==dr){
        int t=tip(mat[1][st],mat[2][st],mat[3][st]);
        arb[nod].stari[1]=arb[nod].stari[2]=arb[nod].stari[3]=arb[nod].stari[4]=arb[nod].stari[5]=0;
        arb[nod].stari[t]=1;
        return;
    }
    int mij=(st+dr)/2;
    create(nod*2,st,mij);
    create(nod*2+1,mij+1,dr);
    arb[nod].stari[4]=(arb[nod*2].stari[4]+arb[nod*2+1].stari[4]+1LL*(arb[nod*2+1].stari[4]*arb[nod*2].stari[4])%MOD+1LL*(arb[nod*2+1].stari[2]*arb[nod*2].stari[3])%MOD)%MOD;
    arb[nod].stari[3]=(arb[nod*2].stari[3]+arb[nod*2+1].stari[3]+1LL*(arb[nod*2+1].stari[3]*arb[nod*2].stari[4])%MOD+1LL*(arb[nod*2+1].stari[1]*arb[nod*2].stari[3])%MOD)%MOD;
    arb[nod].stari[2]=(arb[nod*2].stari[2]+arb[nod*2+1].stari[2]+1LL*(arb[nod*2+1].stari[4]*arb[nod*2].stari[2])%MOD+1LL*(arb[nod*2+1].stari[2]*arb[nod*2].stari[1])%MOD)%MOD;
    arb[nod].stari[1]=(arb[nod*2].stari[1]+arb[nod*2+1].stari[1]+1LL*(arb[nod*2+1].stari[3]*arb[nod*2].stari[2])%MOD+1LL*(arb[nod*2+1].stari[1]*arb[nod*2].stari[1])%MOD)%MOD;
}

void update(int nod,int st,int dr){
    if(st==dr){
        int t=tip(mat[1][st],mat[2][st],mat[3][st]);
        arb[nod].stari[1]=arb[nod].stari[2]=arb[nod].stari[3]=arb[nod].stari[4]=arb[nod].stari[5]=0;
        arb[nod].stari[t]=1;
        return;
    }
    int mij=(st+dr)/2;
    if(y<=mij){
        update(nod*2,st,mij);
    }else{
        update(nod*2+1,mij+1,dr);
    }
    arb[nod].stari[4]=(arb[nod*2].stari[4]+arb[nod*2+1].stari[4]+1LL*(arb[nod*2+1].stari[4]*arb[nod*2].stari[4])%MOD+1LL*(arb[nod*2+1].stari[2]*arb[nod*2].stari[3])%MOD)%MOD;
    arb[nod].stari[3]=(arb[nod*2].stari[3]+arb[nod*2+1].stari[3]+1LL*(arb[nod*2+1].stari[3]*arb[nod*2].stari[4])%MOD+1LL*(arb[nod*2+1].stari[1]*arb[nod*2].stari[3])%MOD)%MOD;
    arb[nod].stari[2]=(arb[nod*2].stari[2]+arb[nod*2+1].stari[2]+1LL*(arb[nod*2+1].stari[4]*arb[nod*2].stari[2])%MOD+1LL*(arb[nod*2+1].stari[2]*arb[nod*2].stari[1])%MOD)%MOD;
    arb[nod].stari[1]=(arb[nod*2].stari[1]+arb[nod*2+1].stari[1]+1LL*(arb[nod*2+1].stari[3]*arb[nod*2].stari[2])%MOD+1LL*(arb[nod*2+1].stari[1]*arb[nod*2].stari[1])%MOD)%MOD;    
}

int main(){
    fi>>n>>q;
    for(int i=1;i<=n;i++){
        fi>>ch;
        mat[1][i]=ch-'0';
    }
    for(int i=1;i<=n;i++){
        fi>>ch;
        mat[2][i]=ch-'0';
    }
    for(int i=1;i<=n;i++){
        fi>>ch;
        mat[3][i]=ch-'0';
    }
    create(1,1,n);
    fo<<arb[1].stari[4]+1<<'\n';
    while(q--){
        fi>>x>>y>>c;
        mat[x][y]=c;
        update(1,1,n);
        fo<<arb[1].stari[4]+1<<'\n';
    }
    fi.close();
    fo.close();
}