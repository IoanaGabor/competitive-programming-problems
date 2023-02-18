
#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

ifstream f("cub2.in");
ofstream g("cub2.out");

int cerinta,n,v,cub[205][205][2],k,xrez,yrez,zrez,rest,unu,doi,trei,patru;
bitset <8000005> ciur;

void construieste_ciur(){
    ciur[0]=ciur[1]=1;
    for(int i=2;i<=n*n*n;i++){
        if(ciur[i]==0){
            for(int j=2*i;j<=n*n*n;j+=i){
                ciur[j]=1;
            }
        }
    }
}

int main(){
    f>>cerinta>>n>>v;
    if(cerinta==1){
        if(v%(n*n)==0){
            zrez=v/(n*n);
        }else{
            zrez=v/(n*n)+1;
        }
        if(v%(2*n*n)==0){
            rest=2*n*n;
        }else{
            rest=v%(2*n*n);
        }
    }
    for(int i=1;i<=(n+1)/2;i++){
        for(int j=i;j<=n-i+1;j++){
            k++;
            cub[i][j][1]=k;
            cub[i][j][2]=2*n*n+1-k;
            if(cerinta==1){
                if(k==rest){
                    xrez=i;
                    yrez=j;
                }
                if(2*n*n+1-k==rest){
                    xrez=i;
                    yrez=j;
                }
            }
        }
        for(int j=i+1;j<=n-i+1;j++){
            k++;
            cub[j][n-i+1][1]=k;
            cub[j][n-i+1][2]=2*n*n+1-k;
            if(cerinta==1){
                if(k==rest){
                    xrez=j;
                    yrez=n-i+1;
                }
                if(2*n*n+1-k==rest){
                    xrez=j;
                    yrez=n-i+1;
                }
            }
        }
        for(int j=n-i;j>=i;j--){
            k++;
            cub[n-i+1][j][1]=k;
            cub[n-i+1][j][2]=2*n*n+1-k;
            if(cerinta==1){
                if(k==rest){
                    xrez=n-i+1;
                    yrez=j;
                }
                if(2*n*n+1-k==rest){
                    xrez=n-i+1;
                    yrez=j;
                }
            }
        }
        for(int j=n-i;j>=i+1;j--){
            k++;
            cub[j][i][1]=k;
            cub[j][i][2]=2*n*n+1-k;
            if(cerinta==1){
                if(k==rest){
                    xrez=j;
                    yrez=i;
                }
                if(2*n*n+1-k==rest){
                    xrez=j;
                    yrez=i;
                }
            }
        }
    }
    if(cerinta==1){
        g<<xrez<<' '<<yrez<<' '<<zrez<<'\n';
        f.close();
        g.close();
        return 0;
    }
    construieste_ciur();
    for(int i=1;i<=n;i++){
        for(int j=cub[1][i][1];j<=n*n*n;j+=n*n*2){
            if(ciur[j]==0){
                unu++;
            }
        }
        for(int j=cub[1][i][2];j<=n*n*n;j+=n*n*2){
            if(ciur[j]==0){
                unu++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=cub[i][n][1];j<=n*n*n;j+=n*n*2){
            if(ciur[j]==0){
                doi++;
            }
        }
        for(int j=cub[i][n][2];j<=n*n*n;j+=n*n*2){
            if(ciur[j]==0){
                doi++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=cub[n][i][1];j<=n*n*n;j+=n*n*2){
            if(ciur[j]==0){
                trei++;
            }
        }
        for(int j=cub[n][i][2];j<=n*n*n;j+=n*n*2){
            if(ciur[j]==0){
                trei++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=cub[i][1][1];j<=n*n*n;j+=n*n*2){
            if(ciur[j]==0){
                patru++;
            }
        }
        for(int j=cub[i][1][2];j<=n*n*n;j+=n*n*2){
            if(ciur[j]==0){
                patru++;
            }
        }
    }
    g<<unu<<'\n'<<doi<<'\n'<<trei<<'\n'<<patru<<'\n';
    f.close();
    g.close();
}
