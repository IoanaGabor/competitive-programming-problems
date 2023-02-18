
#include <iostream>
#include <fstream>
#include <cstring>
#define NMAX 1000

using namespace std;

ifstream f("bool.in");
ofstream g("bool.out");

int t,n;
bool variabile[30];
char expresie[NMAX+5],ch;
bool adevarat(int &i);
bool fals(int &i);
bool termen(int &i);
bool si(int &i);
bool sau(int &i);
bool eval(int &i);

bool adevarat(int &i){
    if(i+3<n&&expresie[i]=='T'&&expresie[i+1]=='R'){
        i+=3;
        return true;
    }
    return false;
}

bool fals(int &i){
    if(i+4<n&&expresie[i]=='F'&&expresie[i+1]=='A'){
        i+=4;
        return true;
    }
    return false;
}

bool termen(int &i){
    int cnt=0;
    while(i+4<n&&expresie[i]=='N'&&expresie[i+1]=='O'){
        i+=4;
        cnt++;
    }
    if(cnt%2==1){
        if(expresie[i]=='('){
            i++;
            bool aux=eval(i);
            i++;
            return (!aux);
        }
        if(adevarat(i)){
            return false;
        }
        if(fals(i)){
            return true;
        }
        return (!variabile[expresie[i]-'A']);
    }else{
        if(expresie[i]=='('){
            i++;
            bool aux=eval(i);
            i++;
            return aux;
        }
        if(adevarat(i)){
            return true;
        }
        if(fals(i)){
            return false;
        }
        return (variabile[expresie[i]-'A']);
    }
}

bool si(int &i){
    bool ret=termen(i);
    if(i+6<n&&expresie[i+2]=='A'&&expresie[i+3]=='N'){
        i+=2;
    }
    while(i+4<n&&expresie[i]=='A'&&expresie[i+1]=='N'){
        i+=4;
        bool aux=termen(i);
        ret=(ret&&aux);
        if(i+6<n&&expresie[i+2]=='A'&&expresie[i+3]=='N'){
            i+=2;
        }
    }
    return ret;
}

bool sau(int &i){
    bool ret=si(i);
    if(i+5<n&&expresie[i+2]=='O'&&expresie[i+3]=='R'){
        i+=2;
    }
    while(i+3<n&&expresie[i]=='O'&&expresie[i+1]=='R'){
        i+=3;
        bool aux=si(i);
        ret=(ret||aux);
        if(i+5<n&&expresie[i+2]=='O'&&expresie[i+3]=='R'){
            i+=2;
        }
    }
    return ret;
}

bool eval(int& i){
    return sau(i);
}

int main(){
    f.getline(expresie,NMAX+5);
    n=strlen(expresie);
    f>>t;
    while(t--){
        f>>ch;
        variabile[ch-'A']^=1;
        int poz=0;
        g<<eval(poz);
    }
    f.close();
    g.close();
}
