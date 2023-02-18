
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#define NMAX 40

using namespace std;

ifstream f("mxl.in");
ofstream g("mxl.out");

int n,k,x,y;
long long rez[NMAX+5][NMAX+5];
string e;
map<pair<int,int>,string > mp;
map<pair<int,int>,string >::iterator it;

int getnumber(int l,int c,int& i){
    string ex=mp[make_pair(l,c)];
    int d=ex.size();
    long long nr=0;
    while(ex[i]<='9'&&ex[i]>='0'&&i<d){
        nr=nr*10*1LL+(ex[i]-'0');
        i++;
    }
    i--;
    return nr;
}

long long calc(int l,int c){
    string ex=mp[make_pair(l,c)];
    if(ex==""){
        return rez[l][c];
    }
    int d=ex.size(),l1,c1;
    long long nr=0,sol=0;
    for(int i=0;i<d;i++){
        if(ex[i]=='='){
            continue;
        }
        nr=getnumber(l,c,i);
        if(i<d-1&&ex[i+1]==':'){
            l1=nr;
            i+=2;
            c1=getnumber(l,c,i);
            nr=calc(l1,c1);
        }
        if(i+1==d){
            sol+=nr;
            i++;
        }else if(ex[i+1]=='+'){
            sol+=nr;
            i++;
        }
    }
    mp[make_pair(l,c)]="";
    rez[l][c]=sol;
    return sol;
}

int main(){
    f>>n>>k;
    for(int i=1;i<=k;i++){
        f>>x>>y>>e;
        mp[make_pair(x,y)]=e;
    }
    for(it=mp.begin();it!=mp.end();it++){
        x=(*it).first.first;
        y=(*it).first.second;
        calc(x,y);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g<<rez[i][j]<<' ';
        }
        g<<'\n';
    }
    f.close();
    g.close();
}
