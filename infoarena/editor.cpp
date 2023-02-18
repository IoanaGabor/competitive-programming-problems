
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("editor.in");
    ofstream g("editor.out");
    int n,vf_stiva=0,n_paranteze=0;
    char ch,stiva[60001],paranteze[60001];
    bool nuibine=false;
    f>>n;
    for(int i=1;i<=n;i++) {
        f>>ch;
        while(ch!='E'){
            if(ch=='*' && vf_stiva>0) {
                vf_stiva--;
            }else{
                vf_stiva++;
                stiva[vf_stiva]=ch;
            }
            f>>ch;
        }
        for(int j=1;j<=vf_stiva;j++) {
            if(stiva[j]=='(' || stiva[j]=='['){
                n_paranteze++;
                paranteze[n_paranteze]=stiva[j];
            }else{
                if(stiva[j]==')'){
                    if(paranteze[n_paranteze]=='('){
                        n_paranteze--;
                    }else{
                       nuibine=true;
                       break;
                    }
                }
                if(stiva[j]==']'){
                    if(paranteze[n_paranteze]=='['){
                        n_paranteze--;
                    }else{
                       nuibine=true;
                       break;
                    }
                }
            }
        }
        if(nuibine || n_paranteze>0){
            g<<":("<<'\n';
        }else{
            g<<":)"<<'\n';
        }
        n_paranteze=0;
        nuibine=false;
        vf_stiva=0;
    }
    f.close();
    g.close();
}
