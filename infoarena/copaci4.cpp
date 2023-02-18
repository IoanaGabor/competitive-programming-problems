
#include <iostream>
#include <fstream>
#define NMAX 200005

using namespace std;

ifstream f("copaci4.in");
ofstream g("copaci4.out");

int n,h[NMAX],contor;

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>h[i];
    }
    for(int i=2;i<n;i++){
        int j=i-1;
        while(h[j]<h[i]&& j>0){
            j--;
        }
        if(j==0||h[j]==h[i]){
            continue;
        }
        j=i+1;
        while(h[j]<h[i]&&j<=n){
            j++;
        }
        if(j==n+1|| h[j]==h[i]){
            continue;
        }
        contor++;
    }
    g<<contor;
    f.close();
    g.close();
}
