
#include <bits/stdc++.h>
#define NMAX 800

using namespace std;

ifstream fi("tris.in");
ofstream fo("tris.out");

int a,b,c,d;
int mat[NMAX+5][NMAX+5];
int cnt;
int l1,l2,c1,c2;

void l_shape(){
    mat[2][1]=mat[2][2]=mat[3][1]=++cnt;
    for(int i=2;i<=(d/2)+(d%2);i++){
        if(i%2==0){
            mat[2*i][1]=mat[2*i+1][1]=mat[2*i+1][2]=++cnt;
        }else{
            mat[2*i][2]=mat[2*i+1][1]=mat[2*i+1][2]=++cnt;
        }
    }
    mat[2][4]=mat[2][5]=mat[3][5]=++cnt;
    for(int i=2;i<=(d/2);i++){
        if(i%2==0){
            mat[2*i][5]=mat[2*i+1][4]=mat[2*i+1][5]=++cnt;
        }else{
            mat[2*i][4]=mat[2*i+1][4]=mat[2*i+1][5]=++cnt;
        }
    }    
    l1=2*((d/2)+(d%2))+1;
    l2=2*(d/2)+1;
    if(d%4==0){
        c1=2,c2=4;
    }else if(d%4==2){
        c1=1,c2=5;
    }else if(d%4==1){
        c1=1,c2=4;                
    }else{
        c1=2,c2=5;
    }
}

void add_abc(){
    for(int i=1;i<=a/2;i++){
        mat[l1+i][c1]=++cnt;
        mat[l2+i][c2]=++cnt;
    }            
    l1+=a/2;
    l2+=a/2;
    for(int i=1;i<=b/2;i++){
        mat[l1+(i-1)*2+1][c1]=mat[l1+i*2][c1]=++cnt;
        mat[l2+(i-1)*2+1][c2]=mat[l2+i*2][c2]=++cnt;
    }
    l1+=b;
    l2+=b;
    for(int i=1;i<=c/2;i++){
        mat[l1+(i-1)*3+1][c1]=mat[l1+(i-1)*3+2][c1]=mat[l1+i*3][c1]=++cnt;
        mat[l2+(i-1)*3+1][c2]=mat[l2+(i-1)*3+2][c2]=mat[l2+i*3][c2]=++cnt;
    }
    l1+=(c/2)*3;
    l2+=(c/2)*3;
}

int main(){
    fi>>a>>b>>c>>d;
    l_shape();
    if(d%2==0){
        if(b%2==1){
            mat[l1+1][c1]=++cnt;
            mat[l1+2][c1]=mat[l1+3][c1]=++cnt;
            mat[l2+1][c2]=mat[l2+2][c2]=mat[l2+3][c2]=++cnt;
            l1+=3,l2+=3;
            a--,b--,c--;
        }
        if(a%2==1&&c%2==1){
            mat[2][3]=++cnt;
            a--;
            add_abc();
        }else{
            mat[1][2]=mat[1][3]=mat[1][4]=++cnt;
            c--;
            add_abc();
        }
        if(c1==2){
            mat[l1+1][c1]=mat[l1+1][c2]=mat[l1+1][3]=++cnt;
        }else{
            mat[l1][c1+1]=mat[l1][c2-1]=mat[l1][3]=++cnt;
        }
    }else{
        mat[l2+1][c2]=mat[l2+2][c2]=++cnt;
        l2+=2;
        b--;
        if(b%2==1){
            mat[l1+1][c1]=++cnt;
            mat[l1+2][c1]=mat[l1+3][c1]=++cnt;
            mat[l2+1][c2]=mat[l2+2][c2]=mat[l2+3][c2]=++cnt;
            l1+=3,l2+=3;
            a--,b--,c--;
        }
        if(a%2==1&&c%2==0){
            mat[1][2]=mat[1][3]=mat[1][4]=++cnt;
            c--;
            add_abc();
        }else{
            mat[2][3]=++cnt;
            a--;
            add_abc();
        }
        mat[l1+1][c1]=++cnt;
        mat[l1+1][c1+1]=mat[l1+1][c1+2]=mat[l1+1][c1+3]=++cnt;
    }
    fo<<800<<' '<<5<<'\n';
    for(int i=1;i<=800;i++){
        for(int j=1;j<=5;j++){
            fo<<mat[i][j]<<" ";
        }
        fo<<'\n';
    }
    fi.close();
    fo.close();
}
