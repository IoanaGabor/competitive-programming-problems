
#include <iostream>
#include <fstream>
#define nmax 10000

using namespace std;

ifstream f("arc.in");
ofstream g("arc.out");

int n,culori[nmax+1],cerinta,aparitii[nmax+1],l=0;

int afla_inceput_secventa(){
    int maxim=1;
    for(int i=2;i<=l;i++){
        if(aparitii[maxim]<aparitii[i]){
            maxim=i;
        }
    }
    if(aparitii[maxim]<3){
        return -1;
    }
    return maxim;
}

void sterge_secventa(int j,int k){
    if(aparitii[j-1]+aparitii[k+1]<3&&culori[j-1]==culori[k+1]){
        aparitii[j-1]=aparitii[j-1]+aparitii[k+1];
        k++;
    }
    int cl;
    cl=l-(k-j+1);
    for(k=k+1;k<=l;k++){
        culori[j]=culori[k];
        aparitii[j]=aparitii[k];
        j++;
    }
    l=cl;
}

int main(){
    f>>cerinta>>n;
    f>>culori[1];
    aparitii[1]++;
    l=1;
    int x;
    for(int i=2;i<=n;i++){
        f>>x;
        if(x==culori[l]){
            aparitii[l]++;
        }else{
            l++;
            aparitii[l]++;
            culori[l]=x;
        }
    }
    if(cerinta==1){
        g<<l<<'\n';
    }else{
        int i=afla_inceput_secventa(),j,k;
        while(n&& i!=-1){
            j=k=i;
            n=n-aparitii[i];
            while(culori[j-1]==culori[k+1]&&aparitii[j-1]+aparitii[k+1]>=3&&j>1&&k<l){
                j--;
                k++;
                n=n-aparitii[j]-aparitii[k];
            }
            if(k==l){
                l=j-1;
            }else{
                sterge_secventa(j,k);
            }
            i=afla_inceput_secventa();
        }
        if(n){
            g<<n<<'\n';
            for(int q=1;q<=l;q++){
                while(aparitii[q]--){
                    g<<culori[q]<<'\n';
                }
            }
        }else{
            g<<0<<'\n';
        }
    }
    f.close();
    g.close();
}
