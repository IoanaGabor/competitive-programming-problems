
#include <iostream>
#include <fstream>
#define NMAX 1000000

using namespace std;

ifstream f("compact.in");
ofstream g("compact.out");

int n,sir[NMAX+5],stiva1[NMAX+5],stiva2[NMAX+5],top1,top2,ind;
long long rez=0;

int cauta(){
    int pas=1<<20,ret=0;
    while(pas){
        if(ret+pas<=top1&&stiva1[ret+pas]<=stiva2[top2]){
            ret+=pas;
        }
        pas>>=1;
    }
    ret++;
    return ret;
}

int main() {
    f>>n;
    for(int i=1;i<=n;i++){
        f>>sir[i];
    }
    for(int i=1;i<=n;i++){
        while(top1&&sir[stiva1[top1]]>sir[i]){
            top1--;
        }
        while(top2&&sir[stiva2[top2]]<sir[i]){
            top2--;
        }
        //cout<<i<<' '<<sir[i]<<' '<<stiva2[top2]<<"***********"<<' ';
        /*for(int i=1;i<=top1;i++){
            cout<<stiva1[i]<<' ';
        }*/
        if(top2==0&&top1!=0){
            if(stiva1[top1]==i-1){
                rez+=top1-1;
            }else{
                rez+=top1;
            }
        }else{
            if(top1){
                ind=cauta();
                //cout<<"______________"<<ind<<' ';
                rez+=(top1-ind+1);
                if(stiva1[top1]==i-1&&(top1-ind+1)>0){
                    rez--;
                }
            }
        }
        stiva1[++top1]=i;
        stiva2[++top2]=i;
        //cout<<"%%%%%%%%"<<rez<<'\n';
    }
    g<<rez;
    f.close();
    g.close();
    return 0;
}
