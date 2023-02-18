
#include <bits/stdc++.h>

using namespace std;

ifstream f("rk.in");
ofstream g("rk.out");

struct trie{
    int ap,val;
    trie *son[2];
    trie(){
        ap=0;
        son[0]=son[1]=0;
    }
};

trie *root=new trie;
int n,x,q,r,k;

void adauga(){
    trie *where=root;
    where->ap++;
    do{
        if(where->son[x%2]==0){
            where->son[x%2]=new trie;
        }
        where=where->son[x%2];
        where->ap++;
        x/=2;
    }while(x);
    where->val++;
}

int numara(){
    trie *where=root;
    int cnt=0;
    while(k){
        if(where->son[r%2]==0){
            return cnt;
        }
        where=where->son[r%2];
        r/=2;
        k--;
        if(r==0){
            cnt+=where->val;
        }
    }
    cnt+=where->ap-where->val;
    return cnt;
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>x;
        adauga();
    }
    f>>q;
    while(q--){
        f>>r>>k;
        g<<numara()<<'\n';
    }
    f.close();
    g.close();
}
