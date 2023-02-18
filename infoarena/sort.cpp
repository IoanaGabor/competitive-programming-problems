
#include <iostream>
#include <fstream>
#define NMAX 1000

using namespace std;

ifstream f("sort.in");
ofstream g("sort.out");

int n,sir[NMAX+1],fr[4],cnt;

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
        fr[sir[i]]++;
    }
    for(int i=1;i<=fr[1];i++){
        if(sir[i]==2){
            int j=fr[1]+1;
            while(sir[j]!=1){
                j++;
            }
            swap(sir[i],sir[j]);
            cnt++;
        }else if(sir[i]==3){
            int j=n;
            while(sir[j]!=1){
                j--;
            }
            swap(sir[i],sir[j]);
            cnt++;
        }
    }
    for(int i=fr[1]+1;i<=fr[1]+fr[2];i++){
        if(sir[i]==3){
            cnt++;
        }
    }
    g<<cnt;
    f.close();
    g.close();
}
