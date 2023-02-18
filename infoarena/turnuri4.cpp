
#include <iostream>
#include <fstream>
#include <queue>
#define NMAX 100000

using namespace std;

ifstream f("turnuri4.in");
ofstream g("turnuri4.out");

int n,sir[NMAX+5],st[NMAX+5],dr[NMAX+5],st2[NMAX+5],dr2[NMAX+5],stiva[NMAX+5],stiva2[NMAX+5],top,top2,suma,modif[NMAX+5];
deque <int> dq;

void constr_st_dr(){
    for(int i=1;i<=n;i++){
        f>>sir[i];
        while(!dq.empty()&&sir[dq.front()]<sir[i]){
            dr2[dq.front()]=i-1;
            dq.pop_front();
        }
        while(top&&sir[stiva[top]]<sir[i]){
            dr[stiva[top]]=i-1;
            stiva2[++top2]=stiva[top];
            top--;
        }
        while(top2){
            dq.push_front(stiva2[top2]);
            top2--;
        }
        stiva[++top]=i;
    }
    while(top){
        dq.push_back(stiva[top]);
        dr[stiva[top]]=n;
        top--;
    }
    while(!dq.empty()){
        dr2[dq.front()]=n;
        dq.pop_front();
    }
    for(int i=n;i>=1;i--){
        while(!dq.empty()&&sir[dq.front()]<sir[i]){
            st2[dq.front()]=i+1;
            dq.pop_front();
        }
        while(top&&sir[stiva[top]]<sir[i]){
            st[stiva[top]]=i+1;
            stiva2[++top2]=stiva[top];
            top--;
        }
        while(top2){
            dq.push_front(stiva2[top2]);
            top2--;
        }
        stiva[++top]=i;
    }
    while(top){
        dq.push_back(stiva[top]);
        st[stiva[top]]=1;
        top--;
    }
    while(!dq.empty()){
        st2[dq.front()]=1;
        dq.pop_front();
    }
}

int main(){
    f>>n;
    constr_st_dr();
    for(int i=1;i<=n;i++){
        suma+=(dr[i]-st[i]+1);
    }
    for(int i=1;i<=n;i++){
        modif[dr[i]+1]+=dr2[i]-dr[i];
        modif[st[i]-1]+=st[i]-st2[i];
    }
    for(int i=1;i<=n;i++){
        g<<suma+modif[i]-dr[i]+st[i]<<'\n';
    }
    f.close();
    g.close();
}


