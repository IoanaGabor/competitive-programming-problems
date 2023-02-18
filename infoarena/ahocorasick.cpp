#include <bits/stdc++.h>
#define AMAX 1000000
#define CMAX 10000
#define ALFA 26
#define NMAX 100

using namespace std;

ifstream fi("ahocorasick.in");
ofstream fo("ahocorasick.out");

struct trie{
    trie *son[ALFA+1];
    trie *fail;
    int ap;
    int nrord;
    trie(){
        for(int i=0;i<ALFA;i++){
            son[i]=NULL;
        }
        fail=NULL;
        ap=0;
    }    
} *root, *final[NMAX+5];

vector<trie*> q;
char a[AMAX+5];
char cuv[CMAX+5];
int n,fir,las;
int l[NMAX+5];
int cnt;

void add(int i,int j,trie *where){
    if(i==l[j]){
        final[j]=where;
        return;
    }
    if(where->son[cuv[i]-'a']==NULL){
        where->son[cuv[i]-'a']= new trie;
        where->son[cuv[i]-'a']->nrord=++cnt;
    }
    add(i+1,j,where->son[cuv[i]-'a']);
}

void add_fail_edges(){
    root->fail=root;
    fir=las=0;
    for(int i=0;i<ALFA;i++){
        if(root->son[i]){
            root->son[i]->fail=root;
            q.push_back(root->son[i]);
            las++;
        }
    }
    trie *where,*nfail;
    while(fir<las){
        where=q[fir++];
        for(int i=0;i<ALFA;i++){
            if(where->son[i]){
                nfail=where->fail;
                do{
                    if(nfail->son[i]){
                        where->son[i]->fail=nfail->son[i];
                        break;
                    }            
                    if(nfail==root){
                        where->son[i]->fail=root;
                        break;
                    }
                    nfail=nfail->fail;        
                }while(1);
                q.push_back(where->son[i]);
                las++;
            }
        }    
    }
}

void potrivire(){
    int ind=0,k;
    int m=strlen(a);
    trie *where=root;
    while(ind<m){
        k=a[ind]-'a';
        if(where->son[k]){
            where=where->son[k];
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
    root = new trie;
    root->nrord=++cnt;
    fi>>a;
    fi>>n;
    for(int i=1;i<=n;i++){
        fi>>cuv;
        l[i]=strlen(cuv);
        trie* p= root;
        add(0,i,p);
    }
    add_fail_edges();
    potrivire();
    for(int i=1;i<=n;i++){
        fo<<final[i]->ap<<'\n';
    }
    fi.close();
    fo.close();
}