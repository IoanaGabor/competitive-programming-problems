
#include <bits/stdc++.h>
#define NMAX 20

using namespace std;

ifstream fi("biti.in");
ofstream fo("biti.out");

int n;
int viz[1<<NMAX];
int st[(1<<NMAX)+2],top,lant[(1<<NMAX)+2],l;

void euler(){
    st[++top]=0;
    int mask=(1<<(n-2))-1,nod;
    while(top){
        nod=st[top];
        if(!viz[nod<<1]){
            viz[nod<<1]=1;
            st[++top]=(nod&mask)<<1;
        }else if(!viz[(nod<<1)+1]){
            viz[(nod<<1)+1]=1;
            st[++top]=((nod&mask)<<1)+1;
        }else{
            top--;
            lant[++l]=nod;
        }
    }
}

int main(){
    fi>>n;
    fo<<(1<<n)+n-1<<'\n';
    if(n==1){
        fo<<"01";
    }else{
        euler();
        for(int i=1;i<n;i++){
            fo<<0;
        }
        for(int i=l-1;i>=1;i--){
            fo<<(lant[i]&1);
        }
    }
    fi.close();
    fo.close();
}