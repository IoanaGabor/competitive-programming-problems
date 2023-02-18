
#include <bits/stdc++.h>
#define NMAX 25000
#define MAXVAL (1LL<<31)-1

using namespace std;

ifstream fi("yamstp.in");
ofstream fo("yamstp.out");

int t,n;
int val[NMAX+5];

struct trie{
    trie *son[2];
    trie(){
        son[0]=son[1]=NULL;
    }
};

trie *root;

void add(trie *where, int nr, int bit){
    if(bit<0){
        return;
    }
    int val=(nr>>bit)&1;
    if(where->son[val]==NULL){
        where->son[val]=new trie;
    }
    add(where->son[val],nr,bit-1);
}

int calc(trie *a, trie *b,int bit){
    if(bit<0){
        return 0;
    }
    int ret=MAXVAL;
    if(a->son[0]!=NULL&&b->son[0]!=NULL){
        ret=min(ret,calc(a->son[0],b->son[0],bit-1));
    }
    if(a->son[1]!=NULL&&b->son[1]!=NULL){
        ret=min(ret,calc(a->son[1],b->son[1],bit-1));
    }
    if(ret!=MAXVAL){
        return ret;
    }
    if(a->son[0]!=NULL&&b->son[1]!=NULL){
        ret=min(ret,(1<<bit)+calc(a->son[0],b->son[1],bit-1));
    }
    if(a->son[1]!=NULL&&b->son[0]!=NULL){
        ret=min(ret,(1<<bit)+calc(a->son[1],b->son[0],bit-1));
    }
    return ret;
}

int solve(trie *where, int l, int r, int bit){
    if(l>=r||bit<0){
        return 0;
    }
    if(((val[l]>>bit)&1)==1||((val[r]>>bit)&1)==0&&where->son[(val[l]>>bit)&1]){
        return solve(where->son[(val[l]>>bit)&1],l,r,bit-1);
    }
    int sep=l;
    while(sep<=r){
        if((val[sep]>>bit)&1){
            break;        
        }
        sep++;
    }
    if(where->son[0]&&where->son[1]){
        return solve(where->son[0],l,sep-1,bit-1)+solve(where->son[1],sep,r,bit-1)+(1<<bit)+calc(where->son[0],where->son[1],bit-1);
    }
    return (1<<bit);
}

void remove(trie *where){
    for(int i=0;i<=1;i++){
        if(where->son[i]!=NULL){
            remove(where->son[i]);
        }
    }
    delete where;
}

int main(){
    fi>>t;
    while(t--){
        fi>>n;
        root=new trie;
        for(int i=1;i<=n;i++){
            fi>>val[i];
            add(root,val[i],19);
        }
        sort(val+1,val+n+1);
        fo<<solve(root,1,n,19)<<'\n';
        remove(root);
    }
    fi.close();
    fo.close();
}