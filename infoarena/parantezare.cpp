#include <iostream>
#include <fstream>
#include <cstring>
#define NMAX 100000

using namespace std;

ifstream f("parantezare.in");
ofstream g("parantezare.out");

char sir[NMAX+5];
int q,x,rez[NMAX+5],n;
int stiva[NMAX+5],top;

int main() {
    f.getline(sir,NMAX);
    n=strlen(sir);
    for(int i=0;i<n;i++){
        if(sir[i]=='('){
            stiva[++top]=i;
        }
        if(sir[i]==')'){
            if(top){
                rez[stiva[top]]=i;
                top--;
            }
        }
    }
    f>>q;
    while(q--){
        f>>x;
        g<<rez[x]<<' ';
    }
    f.close();
    g.close();
    return 0;
}
