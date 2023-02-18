
#include <bits/stdc++.h>
#define NMAX 100000
#define BITS 20

using namespace std;

ifstream fi("xormax.in");
ofstream fo("xormax.out");

struct trie{
    int ind;
    trie *son[2];
    trie(){
        ind=0;
        son[1]=son[0]=NULL;
    }    
};
trie *root,*where;
int n,sir[NMAX+5];
int smaxi,sstart,sstop;
int maxi,start;

void add(int val,int idx){
    where=root;
    for(int i=BITS;i>=0;i--){
        if(val&(1<<i)){
            if(where->son[1]==NULL){
                where->son[1]=new trie;
            }
            where=where->son[1];
        }else{
            if(where->son[0]==NULL){
                where->son[0]=new trie;
            }
            where=where->son[0];
        }
    }
    where->ind=max(where->ind,idx);
}

void calc(int val){
    where=root;
    int bit;
    maxi=0;
    for(int i=BITS;i>=0;i--){
        bit=((val>>i)&1);
        if(where->son[1-bit]!=NULL){
            where=where->son[1-bit];
            maxi+=(1<<i);
        }else{
            where=where->son[bit];
        }
    }    
    start=where->ind;
}

int main(){
    fi>>n;
    root=new trie;
    add(0,0);
    smaxi=-1;
    for(int i=1;i<=n;i++){
        fi>>sir[i];
        sir[i]=sir[i]^sir[i-1];
        calc(sir[i]);
        if(maxi>smaxi){
            smaxi=maxi;
            sstart=start+1;
            sstop=i;
        }
        add(sir[i],i);
    }
    fo<<smaxi<<' '<<sstart<<' '<<sstop<<'\n';
    fi.close();
    fo.close();
}
