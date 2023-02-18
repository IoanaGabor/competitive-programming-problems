
#include <bits/stdc++.h>
#define NMAX 1000

using namespace std;

ifstream fi("mapal.in");
ofstream fo("mapal.out");

int n,m,val;
int mat[NMAX+5][NMAX+5];
int linie[NMAX+5],coloana[NMAX+5];
int unu,doi,trei,patru,aux;
int sol;
char ch;

int main(){
    fi>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            fi>>ch;
            mat[i][j]=ch-'0';
        }
    }
    fi>>m;
    for(int i=1;i<=m;i++){
        fi>>val;
        linie[val]=1;
    }
    fi>>m;
    for(int i=1;i<=m;i++){
        fi>>val;
        coloana[val]=1;
    }
    if(n%2==1){
        if(linie[n/2+1]){
            for(int i=1;i<=n/2;i++){
                if(mat[n/2+1][i]!=mat[n/2+1][n-i+1]){
                    mat[n/2+1][i]=1-mat[n/2+1][i];
                    sol++;
                }
            }
        }
        if(coloana[n/2+1]){
            for(int i=1;i<=n/2;i++){
                if(mat[i][n/2+1]!=mat[n-i+1][n/2+1]){
                    mat[i][n/2+1]=1-mat[i][n/2+1];
                    sol++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(linie[i]){
            for(int j=1;j<=n/2 ;j++){
                if(mat[i][j]!=mat[i][n-j+1]&&coloana[j]==0&&coloana[n-j+1]==0){
                    mat[i][j]=1-mat[i][j];
                    sol++;
                }
            }
        }
        if(coloana[i]){
            for(int j=1;j<=n/2;j++){
                if(mat[j][i]!=mat[n-j+1][i]&&linie[j]==0&&linie[n-j+1]==0){
                    mat[j][i]=1-mat[j][i];
                    sol++;
                }
            }
        }
    }
    for(int i=1;i<=n/2;i++){
        for(int j=1;j<=n/2;j++){
            unu=linie[i];
            doi=coloana[n-j+1];
            trei=linie[n-i+1];
            patru=coloana[j];
            if(unu+doi+trei+patru>=3){
                aux=mat[i][j]+mat[i][n-j+1]+mat[n-i+1][j]+mat[n-i+1][n-j+1];
                sol+=min(aux,4-aux);
            }else if(unu&&doi){
                aux=mat[i][j]+mat[i][n-j+1]+mat[n-i+1][n-j+1];
                sol+=min(aux,3-aux);
            }else if(doi&&trei){
                aux=mat[i][n-j+1]+mat[n-i+1][j]+mat[n-i+1][n-j+1];
                sol+=min(aux,3-aux);
            }else if(trei&&patru){
                aux=mat[i][j]+mat[n-i+1][j]+mat[n-i+1][n-j+1];
                sol+=min(aux,3-aux);                
            }else if(patru&&unu){
                aux=mat[i][j]+mat[i][n-j+1]+mat[n-i+1][j];
                sol+=min(aux,3-aux);
            }
        }
    }
    fo<<sol<<'\n';
    fi.close();
    fo.close();
}