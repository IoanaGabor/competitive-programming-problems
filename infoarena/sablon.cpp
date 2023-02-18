
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#define NMAX 1500

using namespace std;

ifstream f("sablon.in");
ofstream g("sablon.out");

int t,n,m,ok;
bool prefix[NMAX+5][NMAX+5],sufix[NMAX+5][NMAX+5],sau[NMAX+5][NMAX+5];
char sablon[NMAX+5],sir[NMAX+5];

bool litera(char ch){
    if(ch!='*'&&ch!='?'){
        return true;
    }
    return false;
}

int main(){
    f>>(sablon+1)>>t;
    n=strlen(sablon+1);
    while(t--){
        f>>(sir+1);
        m=strlen(sir+1);
        memset(sau,0,sizeof(sau));
        memset(prefix,0,sizeof(prefix));
        memset(sufix,0,sizeof(sufix));
        prefix[0][0]=sau[0][0]=1;
        for(int i=0;i<=m;i++){
            sau[0][i]=1;
        }
        for(int i=1;i<=n&&sablon[i]=='*';i++){
            sau[i][0]=prefix[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(sablon[i]==sir[j]){
                    prefix[i][j]=prefix[i-1][j-1];
                   // cout<<'1'<<' ';
                }else if(litera(sablon[i])){
                    prefix[i][j]=0;
                    //cout<<'2'<<' ';
                }else if(sablon[i]=='?'){
                    prefix[i][j]=prefix[i-1][j-1];
                    //cout<<'3'<<' ';
                }else{
                    prefix[i][j]=sau[i-1][j];
                    //cout<<'4'<<' ';
                }
                sau[i][j]=(sau[i][j-1]||prefix[i][j]);
            }
            //cout<<'\n';
        }
        memset(sau,0,sizeof(sau));
        sufix[n+1][m+1]=sau[n+1][m+1]=1;
        for(int i=0;i<=m;i++){
            sau[n+1][i]=1;
        }
        for(int i=n;i>=1&&sablon[i]=='*';i--){
            sau[i][m+1]=sufix[i][m+1]=1;
        }
        for(int i=n;i>=1;i--){
            for(int j=m;j>=1;j--){
                if(sablon[i]==sir[j]){
                    sufix[i][j]=sufix[i+1][j+1];
                }else if(litera(sablon[i])){
                    sufix[i][j]=0;
                }else if(sablon[i]=='?'){
                    sufix[i][j]=sufix[i+1][j+1];
                }else{
                    sufix[i][j]=sau[i+1][j];
                }
                sau[i][j]=(sau[i][j+1]||sufix[i][j]);
            }
        }
        if(prefix[n][m]){
            g<<1<<'\n';
        }else{
            ok=0;
            for(int i=1;i<=n&&!ok;i++){
                if(litera(sablon[i])){
                    for(int j=1;j<=m;j++){
                        if((prefix[i-1][j]&&sufix[i+1][j+1])||(i==1&&sufix[i+1][1])||(i==n&&prefix[i-1][m])){
                            g<<1<<'\n';
                            ok=1;
                            break;
                        }
                    }
                }
            }
            if(!ok){
                g<<0<<'\n';
            }
        }
        /*for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout<<sufix[i][j]<<' ';
            }
            cout<<'\n';
        }*/
    }
    f.close();
    g.close();
}

