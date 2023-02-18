
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("defrag.in");
ofstream g("defrag.out");

int cerinta,p,s,c,disc[105][725],aux[105][725],contor=0;

void citire(){
    f>>cerinta>>p>>s;
    f>>c;
    int x,y;
    for(int i=1;i<=c;i++){
        f>>x>>y;
        disc[x][y]=1;
        disc[x][s+y]=1;
    }
}

void construieste_aux(){
    for(int i=1;i<=p;i++){
        for(int j=1;j<=2*s;j++){
            aux[i][j]=aux[i][j-1]+disc[i][j];
        }
        if(aux[i][s]==0){
            contor++;
        }
    }
}

void rez2(){
    int n,maxim=0;
    for(int i=1;i<=p;i++){
        maxim=0;
        n=aux[i][s];
        cout<<n<<' ';
        if(n<2){
            g<<0<<' ';
        }else{
            for(int j=n;j<=2*s;j++){
                maxim=max(maxim,aux[i][j]-aux[i][j-n]);
                if(p==2){
                    cout<<maxim<<'\n';
                }
            }
            g<<n-maxim<<' ';
        }
    }
}

int main(){
    citire();
    construieste_aux();
    if(cerinta==1){
        g<<contor<<'\n';
    }else{
        rez2();
    }
    f.close();
    g.close();
}
