
#include <bits/stdc++.h>
#define NMAX 1000
#define LMAX 100000

using namespace std;

ifstream fi("virus.in");
ofstream fo("virus.out");

struct trie{
    trie *sons[3];
    trie *fail;
    int ap;
    trie(){
        sons[0]=sons[1]=NULL;
        fail=NULL;
        ap=0;
    }
} *root,*final[NMAX+5];

int n,l;
char sir[LMAX+5];
int k;
char vir[LMAX+5];
vector<trie*> q;
int fir,las;

void add_in_trie(int ind,trie *where){
    for(int i=0;i<k;i++){
        if(where->sons[vir[i]-'0']==NULL){
            where->sons[vir[i]-'0']=new trie;
        }
        where=where->sons[vir[i]-'0'];
    }
    final[ind]=where;
}

void add_fail_edges(){
    root->fail=root;
    for(int i=0;i<2;i++){
        if(root->sons[i]){
            root->sons[i]->fail=root;
            q.push_back(root->sons[i]);
            las++;
        }
    }
    trie *where,*nfail;
    while(fir<las){
        where=q[fir++];
        for(int i=0;i<2;i++){
            if(where->sons[i]){
                nfail=where->fail;
                while(1){
                    if(nfail->sons[i]){
                        where->sons[i]->fail=nfail->sons[i];
                        break;
                    }
                    if(nfail==root){
                        where->sons[i]->fail=root;
                        break;
                    }
                    nfail=nfail->fail;
                }
                q.push_back(where->sons[i]);
                las++;
            }
        }
    }
}

void potrivire(){
    int ind=0;
    trie *where=root;
    while(ind<l){
        if(where->sons[sir[ind]-'0']){
            where=where->sons[sir[ind]-'0'];
            where->ap++;
            ind++;
        }else if(where==root){
            ind++;
        }else{
            where=where->fail;
        }
    }
    while(q.size()){
        q.back()->fail->ap+=q.back()->ap;
        q.pop_back();
    }
}

int main(){
    fi>>l>>n;
    fi>>sir;
    root=new trie;
    for(int i=1;i<=n;i++){
        fi>>k;
        fi>>vir;
        add_in_trie(i,root);
    }
    add_fail_edges();
    potrivire();
    for(int i=1;i<=n;i++){
        fo<<final[i]->ap<<'\n';
    }
    fi.close();
    fo.close();
}