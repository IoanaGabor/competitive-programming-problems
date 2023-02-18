
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#define NMAX 10000
#define TMAX 10
#define LMAX 2000

using namespace std;

ifstream f("ratina.in");
ofstream g("ratina.out");

struct trie{
    int nrord;
    trie *son[26];
    trie(){
        nrord=0;
        memset(son,0,sizeof(son));
    }
};
int n,m,cnt,ind[TMAX+5],t,mini;
string word[NMAX+5];
trie *root=new trie;
vector <int> cif[NMAX+5];

void adauga(string sir,int poz){
    int l=sir.size();
    trie *where=root;
    for(int i=0;i<l;i++){
        if(where->son[sir[i]-'a']==0){
            where->son[sir[i]-'a']=new trie;
        }
        where=where->son[sir[i]-'a'];
        if(where->nrord==0){
            where->nrord=++cnt;
        }
        cif[poz].push_back(where->nrord);
    }
}

bool verif(int v){
    for(int i=2;i<=t;i++){
        if(cif[ind[i]][v-1]!=cif[ind[1]][v-1]){
            return false;
        }
    }
    return true;
}

int cauta(int poz){
    int pas=1<<11;
    int r=0;
    while(pas){
        if(r+pas<=mini&&verif(r+pas)){
            r+=pas;
        }
        pas>>=1;
    }
    return r;
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        f>>word[i];
        adauga(word[i],i);
    }
    while(m--){
        f>>t;
        mini=LMAX;
        for(int i=1;i<=t;i++){
            f>>ind[i];
            mini=min(mini,(int)word[ind[i]].size());
        }
        g<<cauta(ind[1])<<'\n';
    }
    f.close();
    g.close();
}
