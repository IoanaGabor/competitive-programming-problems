
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream f("emm.in");
ofstream g("emm.out");

int l;
string expresie;

int getnumber(int& i){
    int nr=0;
    for(;expresie[i]>='0'&&expresie[i]<='9';i++){
        nr=nr*10+(expresie[i]-'0');
    }
    i--;
    return nr;
}

int minsaumax(int a,int b,int m){
    if(m==0){
        return min(a,b);
    }else{
        return max(a,b);
    }
}

int evaluare(int& i){
    int rez,t,maxim=-1;
    for(;expresie[i]!=')';i++){
        if(maxim==-1){
            if(expresie[i]=='('){
                i++;
                rez=evaluare(i);
                i++;
            }else{
                rez=getnumber(i);
            }
            i++;
            if(expresie[i]=='m'){
                maxim=0;
            }else if(expresie[i]=='M'){
                maxim=1;
            }else{
                i--;
            }
        }else{
            if(expresie[i]=='('){
                i++;
                t=evaluare(i);
                i++;
            }else{
                t=getnumber(i);
            }
            rez=minsaumax(rez,t,maxim);
            i++;
            if(expresie[i]=='m'){
                maxim=0;
            }else if(expresie[i]=='M'){
                maxim=1;
            }else{
                i--;
            }
        }
    }
    i--;
    return rez;
}

int main(){
    f>>expresie;
    expresie.push_back(')');
    l=expresie.size();
    int poz=0;
    g<<evaluare(poz);
    f.close();
    g.close();
}
