
#include <iostream>
#include <fstream>
#define MAXVAL 100001
#define NMAX 800

using namespace std;

ifstream f("amedie.in");
ofstream g("amedie.out");

int n,m,matrice[NMAX+5][NMAX+5],q,fr[MAXVAL+5],nr,cnt,s;
char ch;

int main(){
    f>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f>>matrice[i][j];
            fr[matrice[i][j]]++;
        }
    }
    while(q--){
        f>>ch;
        if(ch!='Q'){
            f>>nr;
            if(ch=='L'){
                for(int i=1;i<=m;i++){
                    if(matrice[nr][i]&&fr[matrice[nr][i]]){
                        fr[matrice[nr][i]]--;
                        cnt++;
                        matrice[nr][i]=0;
                    }
                }
            }else{
                for(int i=1;i<=n;i++){
                    if(matrice[i][nr]&&fr[matrice[i][nr]]){
                        fr[matrice[i][nr]]--;
                        cnt++;
                        matrice[i][nr]=0;
                    }
                }
            }
        }else{
            s=0;
            for(int r=1;r<=MAXVAL;r++){
                s+=fr[r];
                if(s>=(n*m-cnt)/2+(n*m-cnt)%2){
                    g<<r<<'\n';
                    break;
                }
            }
        }
    }
    f.close();
    g.close();
}
