#include <iostream>
#include <fstream>
#include <cstring>
#define NMAX 500000

using namespace std;

ifstream f("palalila2.in");
ofstream g("palalila2.out");

char sir[NMAX+5];
int n,cnt,ok;

int main(){
    f>>sir;
    n=strlen(sir);
    for(int i=0;i<n-1;i++){
        if(ok==0&&sir[i]<sir[i+1]){
            cnt++;
            ok=1;
        }else if(ok==1&&sir[i]>sir[i+1]){
            cnt++;
            ok=0;
        }
    }
    g<<cnt+1;
    f.close();
    g.close();
}
