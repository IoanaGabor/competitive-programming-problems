
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("expresie3.in");
ofstream g("expresie3.out");

int aparitii[26];
struct sir{
    int v[26];
};
char ch;
int rez[26];

void calc(bool inmultire){
    bool inmultire2=true;
    f.get(ch);
    while(ch!='\n'&&ch!=')'){
        if(ch=='*'){
            inmultire2=true;
        }else if(ch=='/'){
            inmultire2=false;
        }else if(ch=='('){
            if((inmultire==true&&inmultire2==false)||(inmultire==false&&inmultire2==true)){
                calc(false);
            }else{
                calc(true);
            }
        }else if('a'<=ch&&ch<='z'){
            aparitii[ch-'a']=1;
            if((inmultire==true&&inmultire2==false)||(inmultire==false&&inmultire2==true)){
                rez[ch-'a']--;
            }else{
                rez[ch-'a']++;
            }
        }
        f.get(ch);
    }

}

int main(){
    calc(true);
    for(int i=0;i<26;i++){
        if(aparitii[i]){
            g<<char('a'+i)<<' '<<rez[i]<<'\n';
        }
    }
    f.close();
    g.close();
}
