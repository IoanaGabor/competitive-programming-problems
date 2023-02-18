
#include <iostream>
#include <fstream>
#include <queue>
#define NMAX 1000000

using namespace std;

ifstream f("knumere.in");
ofstream g("knumere.out");

int n,k,sir[NMAX+5],dif[NMAX+5],rez=(1LL<<31)-1;
deque<int> dq;

int main(){
    f>>n>>k;
    for(int i=1;i<=n;i++){
        f>>sir[i];
        if(i!=1){
            dif[i-1]=sir[i]-sir[i-1];
        }
    }
    for(int i=1;i<=n-1;i++){
        while(!dq.empty()&&dif[dq.back()]<=dif[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        while(!dq.empty()&&dq.front()<i-(n-k)+2){
            dq.pop_front();
        }
        if(i>=(n-k-1)){
            rez=min(rez,dif[dq.front()]);
        }
    }
    g<<rez;
    f.close();
    g.close();
}
