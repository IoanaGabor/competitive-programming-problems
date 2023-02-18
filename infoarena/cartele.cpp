
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cartele.in");
ofstream g("cartele.out");

int n,sablon[51][51],cartela[51][51],t;

void citeste_matrice(int matrice[][51]){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f>>matrice[i][j];
        }
    }
}

bool verifica(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(sablon[i][j]!=cartela[i][j]){
                return false;
            }
        }
    }
    return true;
}

void intoarce(){
    int aux[51][51];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            aux[i][j]=cartela[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cartela[i][j]=aux[n-j+1][i];
        }
    }

}

void inverseaza(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n/2;j++){
            swap(cartela[i][j],cartela[i][n-j+1]);
        }
    }
}

int main(){
    f>>n>>t;
    citeste_matrice(sablon);
    bool aux,ok;
    while(t--){
        citeste_matrice(cartela);
        ok=false;
        for(int i=1;i<=4;i++){
            intoarce();
            aux=verifica();
            if(aux){
                g<<1<<'\n';
                ok=true;
                break;
            }
        }
        if(ok==true){
            continue;
        }
        inverseaza();
        for(int i=1;i<=4;i++){
            intoarce();
            aux=verifica();
            if(aux){
                g<<1<<'\n';
                ok=true;
                break;
            }
        }
        if(ok==true){
            continue;
        }
        g<<0<<'\n';
    }
    f.close();
    g.close();
}
