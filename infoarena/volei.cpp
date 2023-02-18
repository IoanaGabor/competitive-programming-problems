
#include <iostream>
#include <fstream>
#include <queue>
#define NMAX 7

using namespace std;

ifstream f("volei.in");
ofstream g("volei.out");

struct jucator{
    int x,y,tip;
} juc[2*NMAX+3];

queue<int> q;
int n,d;
char ch;
int stare_prec[(1<<(2*NMAX+1))+5],nrp[(1<<(2*NMAX+1))+5],init,ssol;

bool sus(int i,int j,int k){
    int xi,yi,xj,yj,xk,yk;
    xi=juc[i].x;
    yi=juc[i].y;
    xj=juc[j].x;
    yj=juc[j].y;
    xk=juc[k].x;
    yk=juc[k].y;
    xj-=xi;
    yj-=yi;
    xk-=xi;
    yk-=yi;
    return (xj*yk-xk*yj>0);
}

bool verif(int st){
    int t1,t2,t3,c1=0,c2=0;
    for(int i=1;i<=2*n;i++){
        for(int j=i+1;j<=2*n;j++){
            t1=((st>>(i-1))&1);
            t2=((st>>(j-1))&1);
            if(t1+t2==1){
                c1=0;
                c2=0;
                for(int k=1;k<=2*n;k++){
                    t3=((st>>(k-1))&1);
                    if(i!=k&&j!=k&&sus(i,j,k)){
                        if(t3){
                            c1++;
                        }else{
                            c2++;
                        }
                    }
                }
                if((c1==n-1&&c2==0)||(c1==0&&c2==n-1)){
                    return true;
                }
            }
        }
    }
    return false;
}

bool distok(int i,int j){
    return ((juc[i].x-juc[j].x)*(juc[i].x-juc[j].x)+(juc[i].y-juc[j].y)*(juc[i].y-juc[j].y)<=d*d);
}

void cauta(){
    init=0;
    for(int i=1;i<=2*n;i++){
        init+=(1<<(i-1))*juc[i].tip;
    }
    stare_prec[init]=-1;
    nrp[init]=0;
    q.push(init);
    int st,st2,t1,t2;
    while(!q.empty()){
        st=q.front();
        q.pop();
        if(verif(st)){
            ssol=st;
            break;
        }
        for(int i=1;i<=2*n;i++){
            for(int j=i+1;j<=2*n;j++){
                t1=((st>>(i-1))&1);
                t2=((st>>(j-1))&1);
                if(t1+t2==1&&distok(i,j)){
                    st2=st;
                    st2=st2^(1<<(i-1));
                    st2=st2^(1<<(j-1));
                    if(nrp[st2]<0){
                        nrp[st2]=1+nrp[st];
                        stare_prec[st2]=st;
                        q.push(st2);
                    }
                }
            }
        }
    }
}

void afis(int stare){
    int t1,t2,ii=0,jj=0;
    if(stare_prec[stare]!=-1){
        afis(stare_prec[stare]);
        for(int i=1;i<=2*n;i++){
            t1=(stare>>(i-1))&1;
            t2=(stare_prec[stare]>>(i-1))&1;
            if(t1!=t2){
                if(!ii){
                    ii=i;
                }else{
                    jj=i;
                }
            }
        }
        g<<juc[ii].x<<' '<<juc[ii].y<<' '<<juc[jj].x<<' '<<juc[jj].y<<'\n';
    }
}

int main(){
    f>>n>>d;
    for(int i=1;i<=2*n;i++){
        f>>juc[i].x>>juc[i].y;
        f>>ch;
        if(ch=='B'){
            juc[i].tip=0;
        }else{
            juc[i].tip=1;
        }
    }
    for(int i=0;i<=(1<<(2*n));i++){
        nrp[i]=-1;
    }
    cauta();
    g<<nrp[ssol]<<'\n';
    afis(ssol);
    f.close();
    g.close();
}
