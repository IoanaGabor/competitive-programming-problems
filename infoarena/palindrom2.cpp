
#include<iostream>
#include<fstream>

using namespace std;

ofstream g("palindrom2.out");

char rez[2000001];
int l_rez;

bool palindrom(char sir[1000001],int l_vector) {
    int k,s;
    for(int i=0;i<=l_vector/2-1;i++) {
        k=l_vector/2 -i;
        s=l_vector-k+1;
        if(sir[k]!=sir[s]) {
            return false;
        }
    }
    return true;
}
void modifica_sir(int lungime,char sir[100001],int i) {
    l_rez=lungime+i;
    for(int k=1;k<=lungime;k++) {
        rez[k]=sir[k];
    }
    for(int j=1;j<=i;j++) {
        rez[l_rez-j +1]=sir[j];
    }
}
void tipareste_sir(char sir[100001],int lungime) {
    for(int i=1;i<=lungime;i++) {
        g<<sir[i];
    }
}
int main() {
    ifstream f("palindrom2.in");
    char c;
    char date[1000001];
    int l_date=0;
    while(f>>c) {
        l_date++;
        date[l_date]=c;
    }
    if(palindrom(date,l_date)) {
        tipareste_sir(date,l_date);
    }else{
        for(int i=1;i<l_date;i++) {
            modifica_sir(l_date,date,i);
            if(palindrom(rez,l_rez)) {
                tipareste_sir(rez,l_rez);
                break;
            }
        }
    }
    f.close();
    g.close();
}
