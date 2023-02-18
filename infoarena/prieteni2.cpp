
#include <bits/stdc++.h>
#define NMAX 200000

using namespace std;

ifstream fi("prieteni2.in");
ofstream fo("prieteni2.out");

struct ceva{
    int prefix=0,sufix=0,cnt=0,best=0;
};

ceva arb[4*NMAX+5];

int n,q,c,a,b;
int rez,oldsuf;

void update(int nod,int st,int dr,int val){
    if(st==dr){
        arb[nod].cnt+=val;
        arb[nod].prefix+=val;
        arb[nod].sufix+=val;
        arb[nod].best+=val;
        return;
    }
    int mij=(st+dr)/2;
    if(a<=mij){
        update(2*nod,st,mij,val);
    }else{
        update(2*nod+1,mij+1,dr,val);
    }
    arb[nod].prefix=arb[2*nod].prefix;
    arb[nod].sufix=arb[2*nod+1].sufix;
    if(arb[2*nod].prefix==(mij-st+1)){
        arb[nod].prefix+=arb[2*nod+1].prefix;
    }
    if(arb[2*nod+1].sufix==(dr-mij)){
        arb[nod].sufix+=arb[2*nod].sufix;   /// am pus 2*nod+1 in loc de 2*nod
    }
    arb[nod].cnt=arb[2*nod].cnt+arb[2*nod+1].cnt;
    arb[nod].best=max(arb[2*nod].best,arb[2*nod+1].best);
    arb[nod].best=max(arb[nod].best,arb[2*nod].sufix+arb[2*nod+1].prefix);
}

void query(int nod,int st,int dr){
    if(a<=st&&dr<=b){
        rez=max(rez,arb[nod].best);
        rez=max(rez,oldsuf+arb[nod].prefix);
        if(arb[nod].cnt==(dr-st+1)){
            oldsuf+=arb[nod].cnt;
        }else{
            oldsuf=arb[nod].sufix;
        }
        return;
    }
    int mij=(st+dr)/2;
    if(a<=mij){
        query(2*nod,st,mij);
    }
    if(b>mij){
        query(2*nod+1,mij+1,dr);
    }
}

int main(){
    fi>>n>>q;
    while(q--){
        fi>>c>>a;
        if(c==1){
            update(1,1,n,1);
        }else if(c==2){
            update(1,1,n,-1);
        }else{
            fi>>b;
            b--;
            if(a>b){
                fo<<1<<'\n';
            }else{
                rez=0;
                oldsuf=0;
                query(1,1,n);
                fo<<rez+1<<'\n';
            }
        }
    }
    fi.close();
    fo.close();
}