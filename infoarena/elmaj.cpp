
#include <iostream>
#include <fstream>
#include <stack>
#define nmax 1000001
using namespace std;

ifstream f("elmaj.in");
ofstream g("elmaj.out");

stack <int> stiva;
int sir[nmax],n,contor=0;

int main() {
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
        if(stiva.empty() || sir[i]==stiva.top()){
            stiva.push(sir[i]);
        }else if(sir[i]!=stiva.top() && !stiva.empty()){
            stiva.pop();
        }
    }
    if(stiva.empty()){
        g<<-1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(sir[i]==stiva.top()){
            contor++;
        }
    }
    if(contor>=n/2+1){
        g<<stiva.top()<<' '<<contor;
    }else{
        g<<-1;
    }
    f.close();
    g.close();
}
