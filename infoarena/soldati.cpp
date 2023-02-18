
#include <iostream>
#include <fstream>
#include <cstring>
#define NMAX 100000

using namespace std;

ifstream f("soldati.in");
ofstream g("soldati.out");

int t,n,delay[NMAX+1],nr_0,gasit1,gasit0;
char sir[NMAX+1];

int main(){
    f>>t;
    while(t--){
        f>>sir;
        n=strlen(sir);
        delay[n]=0;
        gasit0=0;
        for(int i=n-1;i>=0;i--){
            if(!gasit0){
                delay[i]=0;
            }else{
                if(sir[i+1]=='<'){
                    delay[i]=max(delay[i+1]-1,0);
                }else{
                    delay[i]=delay[i+1]+1;
                }
            }
            if(sir[i+1]=='<'){
                gasit0=1;
            }
        }
        gasit1=-1;
        nr_0=0;
        for(int i=0;i<n;i++){
            if(sir[i]=='>'&&gasit1==-1){
                gasit1=i;
            }
            if(sir[i]=='<'&&gasit1!=-1){
                nr_0++;
            }
        }
        g<<delay[gasit1]+nr_0<<'\n';
    }
    f.close();
    g.close();
}
