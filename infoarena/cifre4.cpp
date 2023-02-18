
#include <iostream>
#include <fstream>
#include <queue>
#define PMAX 5000000
#define MAXVAL (1ULL<<64)-1

using namespace std;

ifstream f("cifre4.in");
ofstream g("cifre4.out");

int t;
int n,p;
bool viz[PMAX+5];
queue <unsigned long long> q;
unsigned long long val1,val2,rez;
int cifre[]={0,2,3,5,7};

void init(){
    while(!q.empty()){
        q.pop();
    }
    for(int i=0;i<=p;i++){
        viz[i]=false;
    }
}

int main(){
    f>>t;
    while(t--){
        f>>n>>p;
        init();
        q.push(0);
        while(!q.empty()&&!viz[n]){
            val1=q.front();
            q.pop();
            for(int i=1;i<=4;i++){
                if(val1>=(MAXVAL-cifre[i])/10){
                    break;
                }
                val2=val1*1ULL*10+cifre[i];
                if(!viz[val2%p]){
                    viz[val2%p]=true;
                    if(val2%p==n){
                        g<<val2<<'\n';
                        break;
                    }else{
                        q.push(val2);
                    }
                }
            }
        }
        if(!viz[n]){
            g<<-1<<'\n';
        }
    }
}
