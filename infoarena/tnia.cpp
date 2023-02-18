
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("tnia.in");
ofstream g("tnia.out");

long long n,m,sir[100001],sume[100001],a,b,c,d,q;

long long cauta1(){
    long long inceput=a,sfarsit=c,mijloc=(inceput+sfarsit)/2;
    while(inceput<sfarsit){
        if(sir[mijloc]>=d && sir[mijloc-1]>=d){
            sfarsit=mijloc-1;
            mijloc=(inceput+sfarsit)/2;
        }
        if(sir[mijloc]<d){
            inceput=mijloc+1;
            mijloc=(inceput+sfarsit)/2;
        }
        if((sir[mijloc]>=d && sir[mijloc-1]<d)){
            return mijloc;
        }
    }
}

long long cauta2(){
    long long inceput=a,sfarsit=c,mijloc=(inceput+sfarsit)/2;
    while(inceput<sfarsit){
        if(sir[mijloc]<b){
            inceput=mijloc+1;
            mijloc=(inceput+sfarsit)/2;
        }
        if(sir[mijloc]>=b && sir[mijloc-1]>=b){
            sfarsit=mijloc-1;
            mijloc=(inceput+sfarsit)/2;
        }
        if(sir[mijloc]>=b && sir[mijloc-1]<b){
            return mijloc;
        }
    }
}

int main() {
    f>>n>>m;
    for(int i=1;i<=n;i++){
        f>>sir[i];
        sume[i]=sume[i-1]+sir[i];
    }
    f>>q;
    long long suma,x,y;
    for(int i=1;i<=q;i++){
        f>>a>>b>>c>>d;
        if(sir[c]<b){
            g<<0<<'\n';
        }else if(sir[a]>=d){
            g<<(c-a+1)*(d-b+1)<<'\n';
        }else{
            if(sir[a]<b){
                y=cauta2();
            }else{
                y=a;
            }
            if(sir[c]>d){
                x=cauta1()-1;
            }else{
                x=c;
            }
            suma=sume[x]-sume[y-1]-(b-1)*(x-y+1)+(c-x)*(d-b+1);
            g<<suma<<'\n';
        }
    }
    f.close();
    g.close();
}
