
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#define NMAX 1000

using namespace std;

ifstream f("reteta2.in");
ofstream g("reteta2.out");

char ch;
string sir,aux;
int n,timp;
map <string,int> m;

int main(){
    while(f>>ch&&ch!=0){
        if(ch!=' '){
            sir+=ch;
            n++;
        }
    }
    int numar,prev;
    for(int i=0;i<n;i++){
        if(sir[i]<='9'&&sir[i]>='0'){
            numar=0;
            prev=i-1;
            while(sir[i]<='9'&&sir[i]>='0'){
                numar=numar*10+(sir[i]-'0');
                i++;
            }
            i--;
            if(sir[prev]==')'){
                timp+=numar;
            }else{
                m[aux]+=numar;
            }
        }else if(sir[i]<='z'&&sir[i]>='a'){
            aux="";
            while(sir[i]<='z'&&sir[i]>='a'){
                aux+=sir[i];
                i++;
            }
            i--;
        }
    }
    g<<timp<<'\n';
    for(auto x:m){
        g<<x.first<<' '<<x.second<<'\n';
    }
    f.close();
    g.close();
}
