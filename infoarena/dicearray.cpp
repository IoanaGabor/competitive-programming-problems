#include <bits/stdc++.h>
#define NMAX 70000

using namespace std;

ifstream fi("dicearray.in");
ofstream fo("dicearray.out");

struct tri{
    int d[4];
} sir[NMAX+5];

tri zero;
tri aint[NMAX*4+5];
tri lazy[NMAX*4+5];
tri act;

int n,q,le,ri;
char op;
int aux[NMAX+5];

int semn(int val){
    if(val<0){
        return -1;
    }
    if(val>0){
        return 1;
    }
    return 0;
}

void afis_zar(tri a){
    cout<<a.d[1]<<' '<<a.d[2]<<' '<<a.d[3]<<'\n';
}

tri comp(tri a,tri b){
    tri ret;
    for(int i=1;i<=3;i++){
        ret.d[i]=a.d[abs(b.d[i])]*semn(b.d[i]);
    }
    return ret;
}


void constr_aint(int nod,int st,int dr){
    aint[nod]=zero;
    lazy[nod]=zero;
    if(st==dr){
        return;
    }
    int mij=(st+dr)/2;
    constr_aint(nod*2,st,mij);
    constr_aint(nod*2+1,mij+1,dr);
}

bool diferit(tri a,tri b){
    for(int i=1;i<=3;i++){
        if(a.d[i]!=b.d[i]){
            return true;
        }
    }
    return false;
}

void propagate_lazy(int nod,int st,int dr){
    if(diferit(lazy[nod],zero)){
        aint[nod]=comp(aint[nod],lazy[nod]);

        if(st!=dr){
            lazy[nod*2]=comp(lazy[nod*2],lazy[nod]);
            lazy[nod*2+1]=comp(lazy[nod*2+1],lazy[nod]);
        }
        lazy[nod]=zero;
    }
}

void update_aint(int nod,int st,int dr){
    propagate_lazy(nod,st, dr);
    if(le<=st&&dr<=ri){
        aint[nod]=comp(aint[nod],act);
        if(st!=dr){
            lazy[nod*2]=comp(lazy[nod*2],act);
            lazy[nod*2+1]=comp(lazy[nod*2+1],act);
        }        
        return;
    }
    int mij=(st+dr)/2;
    if(le<=mij){
        update_aint(nod*2,st,mij);
    }
    if(mij<ri){
        update_aint(nod*2+1,mij+1,dr);
    }
}

int solve(int nod,int st,int dr){
    propagate_lazy(nod,st, dr);
    if(st==dr){
        //afis_zar(aint[nod]);
        if(aint[nod].d[1]<0){
            return 7-sir[st].d[-aint[nod].d[1]];
        }else{
            return sir[st].d[aint[nod].d[1]];
        }
    }
    int mij=(st+dr)/2;
    return solve(nod*2,st,mij)+solve(nod*2+1,mij+1,dr);    
}

int main(){
    fi>>n>>q;
    for(int i=1;i<=n;i++){
        fi>>sir[i].d[1]>>sir[i].d[2]>>sir[i].d[3];
    }
    zero.d[1]=1,zero.d[2]=2,zero.d[3]=3;
    constr_aint(1,1,n);
    while(q--){
        fi>>le>>ri>>op;
        if(op=='x'){
            act.d[1]=-3;
            act.d[2]=2;
            act.d[3]=1;
        }
        if(op=='y'){
            act.d[1]=1;
            act.d[2]=3;
            act.d[3]=-2;
        }
        if(op=='z'){
            act.d[1]=2;
            act.d[2]=-1;
            act.d[3]=3;
        }
        update_aint(1,1,n);
    }
    fo<<solve(1,1,n);
    fi.close();
    fo.close();
}