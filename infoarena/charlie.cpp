
#include <iostream>
#include <fstream>
#include <string>
#define NMAX 100000

using namespace std;

ifstream f("charlie.in");
ofstream g("charlie.out");

int p,n,ok,rez1,dim,top,rez2;
string sir;
char stiva[NMAX+5];

int main(){
    f>>p;
    f>>sir;
    n=sir.size();
    if(p==1){
        for(int i=0;i<n-1;i++){
            if(i<=n-3&&sir[i]>sir[i+1]&&sir[i+1]<sir[i+2]&&dim==0){
                dim=3;
                rez1=max(rez1,dim);
                ok=-1;
                i++;
            }else{
                if(dim&&sir[i]*ok<sir[i+1]*ok){
                    dim++;
                    if(ok==1){
                        rez1=max(rez1,dim);
                    }
                    ok*=(-1);
                }else{
                    dim=0;
                    if(i<=n-3&&sir[i]>sir[i+1]&&sir[i+1]<sir[i+2]&&dim==0){
                        dim=3;
                        rez1=max(rez1,dim);
                        ok=-1;
                        i++;
                    }
                }
            }
        }
        g<<rez1;
    }else{
        stiva[++top]=sir[0];
        stiva[++top]=sir[1];
        for(int i=2;i<n;i++){
            while(top>=2&&stiva[top]<sir[i]&&stiva[top]<stiva[top-1]){
                rez2+=max(stiva[top-1]-'a'+1,sir[i]-'a'+1);
                top--;
            }
            stiva[++top]=sir[i];
        }
        for(int i=1;i<=top;i++){
            g<<stiva[i];
        }
        g<<'\n';
        g<<rez2;
    }
    f.close();
    g.close();
}
