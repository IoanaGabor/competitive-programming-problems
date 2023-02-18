
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define NMAX 50000

using namespace std;

ifstream f("sortaret.in");
ofstream g("sortaret.out");

int n,m,a,b,ext[NMAX+5],sol[NMAX+5],lsol;
vector <int> ADJ[NMAX+5];
queue <int> q;

void sortare(){
    int aux;
    while(!q.empty()){
        aux=q.front();
        q.pop();
        sol[++lsol]=aux;
        for(int i=0;i<ADJ[aux].size();i++){
            ext[ADJ[aux][i]]--;
            if(ext[ADJ[aux][i]]==0){
                q.push(ADJ[aux][i]);
            }
        }
    }
}

int main(){
    f>>n>>m;
    for(int i=1;i<=m;i++){
        f>>a>>b;
        ADJ[a].push_back(b);
        ext[b]++;
    }
    for(int i=1;i<=n;i++){
        if(ext[i]==0){
            q.push(i);
        }
    }
    sortare();
    for(int i=1;i<=lsol;i++){
        g<<sol[i]<<' ';
    }
    f.close();
    g.close();
}
