#include <bits/stdc++.h>

using namespace std;

ifstream f("trie.in");
ofstream g("trie.out");

struct trie{
    int ap;
    int val;
    trie *son[26];
    trie(){
        ap=0;
        val=0;
        memset(son,0,sizeof(son));
    }
};

trie *root=new trie,*where2;
int cerinta,l;
string sir;

bool sterge(trie *where,int poz){
    if(poz==l){
        where->val--;
        where->ap--;
        if(where->ap==0&&where!=root){
            delete where;
            return true;
        }
        return false;
    }
    if(sterge(where->son[sir[poz]-'a'],poz+1)){
        where->son[sir[poz]-'a']=0;
    }
    where->ap--;
    if(where->ap==0&&where!=root){
        delete where;
        return true;
    }
    return false;
}

int numara_val(trie *where,int poz){
    if(poz==l){
        return where->val;
    }
    if(where->son[sir[poz]-'a']==0){
        return 0;
    }
    return numara_val(where->son[sir[poz]-'a'],poz+1);
}

int prefix(trie *where,int poz){
    if(poz==l){
        return 0;
    }
    if(where->son[sir[poz]-'a']==0){
        return 0;
    }
    return 1+prefix(where->son[sir[poz]-'a'],poz+1);
}

int main(){
    while(f>>cerinta>>sir){
        l=sir.size();
        if(cerinta==0){
            trie *where=root;
            for(int i=0;i<l;i++){
                if(where->son[sir[i]-'a']==0){
                    where->son[sir[i]-'a']=new trie;
                }
                where=where->son[sir[i]-'a'];
                where->ap++;
                if(i==l-1){
                    where->val++;
                }
            }
        }else if(cerinta==1){
            sterge(root,0);
        }else if(cerinta==2){
            g<<numara_val(root,0)<<'\n';
        }else if(cerinta==3){
            g<<prefix(root,0)<<'\n';
        }
    }
    f.close();
    g.close();
    return 0;
}
