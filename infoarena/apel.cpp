
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

ifstream f("apel.in");
ofstream g("apel.out");

string apel;
map <char,int> variabile;
map <char,pair<string,int> > functii;
char ch;
string linie;

int rezolva_functie(char fnct,int sir[12],int& i);

int getnumber(string s,int& j){
    int rez=0;
    while(j<s.size()&&'0'<=s[j]&&s[j]<='9'){
        rez=rez*10+(s[j]-'0');
        j++;
    }
    return rez;
}

int aritate(string s){
    int cnt=0;
    for(int i=2;s[i]!=')';i++){
        if('a'<=s[i]&&s[i]<='z'){
            cnt++;
        }
    }
    return cnt;
}

string faraegal(string s){
    string rez;
    int ok=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='='){
            ok=1;
        }else if(ok==1){
            rez.push_back(s[i]);
        }
    }
    return rez;
}

int gettermen(char fnct,string s,int& i,int sir[12]){
    int rez=1,nr;
    for(;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            nr=getnumber(s,i);
            if(s[i]==')'){
                i--;
            }
            rez*=nr;
        }else if('a'<=s[i]&&s[i]<='z'){
            rez*=sir[s[i]-'a'+1];
            if(s[i+1]!=')'){
                i++;
            }
        }else if(s[i]=='('){
            i++;
            rez*=rezolva_functie(fnct,sir,i);
            if(s[i+1]!=')'){
                i++;
            }
        }
        if(i<s.size()&&s[i]!='*'){
            break;
        }
    }
    return rez;
}

int rezolva_functie(char fnct,int sir[12],int& i){
    string s=functii[fnct].first;
    int rez=0,nr=0,sgn=1;
    if(s[i]=='-'){
        sgn=-1;
        i++;
    }
    for(;i<s.size()&&s[i]!=')';i++){
        nr=gettermen(fnct,s,i,sir);
        rez+=nr*sgn;
        if(i<s.size()&&s[i]=='-'){
            sgn=-1;
        }else if(i<s.size()&&s[i]=='+'){
            sgn=1;
        }
    }
    return rez;
}

int apeleaza(int& i){
    char fct=apel[i];
    string s=functii[fct].first;
    i+=2;
    int sir[12],cnt=0;
    for(int j=1;j<=functii[fct].second;j++){
        sir[j]=0;
    }
    for(;apel[i]!=')';i++){
        if('0'<=apel[i]&&apel[i]<='9'){
            sir[++cnt]=getnumber(apel,i);
            i--;
        }else if('a'<=apel[i]&&apel[i]<='z'){
            sir[++cnt]=variabile[apel[i]];
        }else{
            sir[++cnt]=apeleaza(i);
        }
        if(apel[i+1]==','){
            i++;
        }
    }
    int poz=0;
    int rez=rezolva_functie(fct,sir,poz);
    return rez;
}

int main(){
    getline(f,apel);
    while(f>>ch){
        if('a'<=ch&&ch<='z'){
            f.putback(ch);
            getline(f,linie);
            int p=2;
            variabile[linie[0]]=getnumber(linie,p);
        }else{
            f.putback(ch);
            getline(f,linie);
            functii[linie[0]].first=faraegal(linie);
            functii[linie[0]].second=aritate(linie);
        }
    }
    int poz=0;
    g<<apeleaza(poz);
    f.close();
    g.close();
}
