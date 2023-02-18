#include <bits/stdc++.h>

using namespace std;

ifstream fi("secv8.in");
ofstream fo("secv8.out");

mt19937 rng(time(0));

struct nod{
    nod *l,*r;
    bool rev;
    int val;
    int priorit;
    int we;
    nod(int x): rev(0),val(x),priorit(rand()),we(1),l(NULL),r(NULL){}
    void update();
};

nod *root=NULL;

int wei(nod* t){
    if(t){
        return t->we;
    }
    return 0;
}

void nod::update(){
        we=wei(l)+wei(r)+1;
        if(rev==1){
            swap(l,r);
            if(l){
                l->rev^=1;
            }
            if(r){
                r->rev^=1;
            }
            rev=0;
        }
}

nod* merge(nod *a,nod *b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    a->update();
    b->update();
    if(a->priorit>b->priorit){
        a->r=merge(a->r,b);
        a->update();
        return a;
    }else{
        b->l=merge(a,b->l);
        b->update();
        return b;
    }
}

pair<nod*,nod*> split(nod *a,int poz){
    if(a==NULL){
        return {NULL,NULL};
    }
    a->update();
    if(poz<=wei(a->l)){
        pair<nod*,nod*> tmp=split(a->l,poz);
        a->l=tmp.second;
        a->update();
        return {tmp.first,a};
    }
    pair<nod*,nod*> tmp=split(a->r,poz-(wei(a->l)+1));
    a->r=tmp.first;
    a->update();
    return {a,tmp.second};
}

void insert(int val,int poz){
    pair<nod*,nod*> tmp=split(root,poz-1);
    root=merge(merge(tmp.first,new nod(val)),tmp.second);
}

int access(nod* a,int poz){
    a->update();
    if(wei(a->l)==poz-1){
        return a->val;
    }
    if(poz<=wei(a->l)){
        return access(a->l,poz);
    }
    return access(a->r,poz-(wei(a->l)+1));
}

void reverse_range(int p1,int p2){
    pair<nod*,nod*> tmp=split(root,p2);
    pair<nod*,nod*> tmp2=split(tmp.first,p1-1);
    tmp2.second->rev^=1;
    root=merge(merge(tmp2.first,tmp2.second),tmp.second);
}

void delete_node(nod *a){
    if(a->l){
        delete_node(a->l);
    }
    if(a->r){
        delete_node(a->r);
    }
    delete(a);
}

void delete_range(int p1,int p2){
    pair<nod*,nod*> tmp=split(root,p2);
    pair<nod*,nod*> tmp2=split(tmp.first,p1-1);
    delete_node(tmp2.second);
    root=merge(tmp2.first,tmp.second);
}

void output_all(nod *a){
    if(a==NULL){
        return;
    }
    a->update();
    output_all(a->l);
    fo<<a->val<<' ';
    output_all(a->r);
}

int main(){
    int t,x,y;
    char op;

    fi>>t>>x;
    while(t--){
        fi>>op;
        if(op=='I'){
            fi>>x>>y;
            insert(y,x);
        }else if(op=='A'){
            fi>>x;
            fo<<access(root,x)<<'\n';
        }else if(op=='R'){
            fi>>x>>y;
            reverse_range(x,y);
        }else if(op=='D'){
            fi>>x>>y;
            delete_range(x,y);
        }
    }
    output_all(root);
    fi.close();
    fo.close();
}