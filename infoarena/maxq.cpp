
#include <bits/stdc++.h>
#define NMAX 200000

using namespace std;

ifstream fi("maxq.in");
ofstream fo("maxq.out");

struct nod{
    long long sufix,prefix,best,tot;
};

int n,m,op,a,b;
int sir[NMAX+5];
nod arb[4*NMAX+5];
long long rez,oldsuf;

void update(int nod,int st,int dr){
    if(st==dr){
        arb[nod].tot=arb[nod].prefix=arb[nod].sufix=arb[nod].best=b;
        return;
    }
    int mij=(st+dr)/2;
    if(a<=mij){
        update(2*nod,st,mij);
    }else{
        update(2*nod+1,mij+1,dr);
    }
    arb[nod].tot=arb[2*nod].tot+arb[2*nod+1].tot;
    arb[nod].prefix=max(arb[2*nod].prefix,arb[2*nod].tot+arb[2*nod+1].prefix);
    arb[nod].sufix=max(arb[2*nod+1].sufix,arb[2*nod+1].tot+arb[2*nod].sufix);
    arb[nod].best=max(arb[2*nod].best,arb[2*nod+1].best);
    arb[nod].best=max(arb[nod].best,arb[2*nod].sufix+arb[2*nod+1].prefix);
}

void query(int nod,int st,int dr){
    if(a<=st&&dr<=b){
        rez=max(rez,arb[nod].best);
        rez=max(rez,oldsuf+arb[nod].prefix);
        oldsuf=max(oldsuf+arb[nod].tot,arb[nod].sufix);
        oldsuf=max(oldsuf,0LL);
        return;
    }
    int mij=(st+dr)/2;
    if(a<=mij){
        query(2*nod,st,mij);
    }
    if(mij<b){
        query(2*nod+1,mij+1,dr);
    }
}

void create(int nod,int st,int dr){
    if(st==dr){
        arb[nod].tot=arb[nod].prefix=arb[nod].sufix=arb[nod].best=sir[st];
        return;
    }
    int mij=(st+dr)/2;
    create(2*nod,st,mij);
    create(2*nod+1,mij+1,dr);
    arb[nod].tot=arb[2*nod].tot+arb[2*nod+1].tot;
    arb[nod].prefix=max(arb[2*nod].prefix,arb[2*nod].tot+arb[2*nod+1].prefix);
    arb[nod].sufix=max(arb[2*nod+1].sufix,arb[2*nod+1].tot+arb[2*nod].sufix);
    arb[nod].best=max(arb[2*nod].best,arb[2*nod+1].best);
    arb[nod].best=max(arb[nod].best,arb[2*nod].sufix+arb[2*nod+1].prefix);
}

int main(){
    fi>>n;
    for(int i=1;i<=n;i++){
        fi>>sir[i];
    }
    create(1,1,n);
    fi>>m;
    while(m--){
        fi>>op>>a>>b;
        a++;
        if(op==0){
            sir[a]=b;
            update(1,1,n);
        }else{
            b++;
            rez=sir[a];
            oldsuf=0;
            query(1,1,n);
            if(rez<0){
                rez=0;
            }
            fo<<rez<<'\n';
        }
    }
    fi.close();
    fo.close();
}