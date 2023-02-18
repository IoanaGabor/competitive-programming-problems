
#include <bits/stdc++.h>
#define NMAX 10000

using namespace std;

ifstream fi("poligon2.in");
ofstream fo("poligon2.out");

int n;
double xm[NMAX+5],ym[NMAX+5];
double x[NMAX+5],y[NMAX+5];

bool solve(double cm[NMAX+5],double c[NMAX+5]){
    double s=0,s1=0,s2=0,s11=0,s22=0;
    for(int i=1;i<=n;i++){
        s+=cm[i];
        if(i%2==1){
            s1+=cm[i];
        }else{
            s2+=cm[i];
        }
    }
    s=(double)(s/2.0);
    if(n%2==1){
        s1-=cm[1];
        cout<<s<<' '<<s1<<' '<<s2<<' '<<s11<<' '<<s22<<'\n';
        for(int i=1;i<=n;i++){
            if(i%2==1){
                c[i]=s-(s11+s2);
                s11+=cm[i];
                s2-=cm[i+1];
            }else{
                c[i]=s-(s22+s1);
                s22+=cm[i];
                s1-=cm[i+1];
            }
        }
    }else{
        if(s1!=s2){
            return false;
        }
        c[n]=0;
        cm[n-1]=cm[n-1]+cm[n];
        cm[0]=cm[n-1];
        s=s1=s2=s11=s22=0;
        for(int i=1;i<n;i++){
            s+=cm[i];
            if(i%2==1){
                s1+=cm[i];
            }else{
                s2+=cm[i];
            }
        }
        s=(double)(s/2.0);
        s1-=cm[1];
        for(int i=1;i<n;i++){
            if(i%2==1){
                c[i]=s-(s11+s2);
                s11+=cm[i];
                s2-=cm[i+1];
            }else{
                c[i]=s-(s22+s1);
                s22+=cm[i];
                s1-=cm[i+1];
            }
        }    
    }
    return true;
}

int main(){
    fi>>n;
    for(int i=1;i<=n;i++){
        fi>>xm[i]>>ym[i];    
        xm[i]*=2;
        ym[i]*=2;
    }
    if(solve(xm,x)&&solve(ym,y)){
        for(int i=1;i<=n;i++){
            fo<<setprecision(3)<<fixed<<x[i]<<' '<<y[i]<<'\n';
        }
    }else{
        fo<<"fara solutie"<<'\n';
    }
}