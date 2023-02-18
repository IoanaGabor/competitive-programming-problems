
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#define VALMIN -(1<<30)

using namespace std;

ifstream f("expresie2.in");
ofstream g("expresie2.out");

int n,cntnumere,rez;
string sir;

int eval_rotunde(int &i);
int eval_patrate(int &i);

int getnumber(int &i){
    int nr=0,semn=1;
    if(sir[i]=='-'){
        semn*=(-1);
        i++;
    }
    while(sir[i]<='9'&&sir[i]>='0'){
        nr=nr*10+(sir[i]-'0');
        i++;
    }
    i--;
    nr=nr*semn;
    cntnumere++;
    return nr;
}

int eval_rotunde(int &i){
    int nr=0,s=0,r=VALMIN;
    i++;
    while(sir[i]!=')'){
        if((sir[i]<='9'&&sir[i]>='0')||sir[i]=='-'){
            nr=getnumber(i);
        }else if(sir[i]=='('){
            nr=eval_rotunde(i);
        }else if(sir[i]=='['){
            nr=eval_patrate(i);
        }
        s=max(nr+s,nr);
        r=max(r,s);
        i++;
        if(sir[i]==','){
            i++;
        }
    }
    return r;
}

int eval_patrate(int &i){
    int nr=0,l=0;
    vector <int> aux;
    i++;
    while(sir[i]!=']'){
        if((sir[i]<='9'&&sir[i]>='0')||sir[i]=='-'){
            nr=getnumber(i);
        }else if(sir[i]=='('){
            nr=eval_rotunde(i);
        }else if(sir[i]=='['){
            nr=eval_patrate(i);
        }
        aux.push_back(nr);
        l++;
        i++;
        if(sir[i]==','){
            i++;
        }
    }
    nth_element(aux.begin(),aux.begin()+((l+1)/2)-1,aux.end());
    return aux[((l+1)/2)-1];
}

void suma(){
    int nr=0;
    for(int i=0;i<n;i++){
        if(sir[i]==','){
            i++;
        }
        if((sir[i]<='9'&&sir[i]>='0')||sir[i]=='-'){
            nr=getnumber(i);
        }else if(sir[i]=='('){
            nr=eval_rotunde(i);
        }else if(sir[i]=='['){
            nr=eval_patrate(i);
        }
        rez=rez+nr;
    }
}

int main(){
    f>>sir;
    n=sir.size();
    suma();
    g<<cntnumere<<'\n'<<rez<<'\n';
    f.close();
    g.close();
}
