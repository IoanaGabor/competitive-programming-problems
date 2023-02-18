
#include <bits/stdc++.h>
#define NMAX 100000

using namespace std;

ifstream fi("baruri.in");
ofstream fo("baruri.out");

int t,n,sir[NMAX+5],aib[NMAX+5];
int m,op,a,b,c;

void add(int ind,int x){
    sir[ind]+=x;
    while(ind<=n){
        aib[ind]+=x;
        ind+=(((ind-1)&ind)^ind);
    }
}

int query(int ind){
    int ret=0;
    while(ind>0){
        ret+=aib[ind];
        ind-=(((ind-1)&ind)^ind);
    }
    return ret;
}

void init(){
    for(int i=1;i<=n;i++){
        sir[i]=aib[i]=0;
    }
}

int zero(){
    int ret=0;
    ret+=query(min(a+b,n));
    ret-=query(max(a-b-1,0));
    ret-=sir[a];
    return ret;
}

int main(){
    fi>>t;
    while(t--){
        fi>>n;
        init();
        for(int i=1;i<=n;i++){
            fi>>sir[i];
            add(i,sir[i]);
            sir[i]/=2;
        }
        fi>>m;
        while(m--){
            fi>>op;
            if(op==0){
                fi>>a>>b;
                fo<<zero()<<'\n';
            }else if(op==1){
                fi>>a>>b;
                add(b,a);
            }else if(op==2){
                fi>>a>>b;
                add(b,-a);
            }else if(op==3){
                fi>>a>>b>>c;
                add(b,-a);
                add(c,a);
            }
        }
    }
    fi.close();
    fo.close();
}