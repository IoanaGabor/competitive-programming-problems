
#include <iostream>
#include <fstream>
#include <deque>
#include <stack>

using namespace std;

ifstream f("permuta.in");
ofstream g("permuta.out");

deque <int> a;
stack <int> b;
int n;

int main(){
    f>>n;
    int x;
    for(int i=1;i<=n;i++){
        f>>x;
        b.push(x);
    }
    while(!b.empty()){
        if(!a.empty()){
            x=a.back();
            a.pop_back();
            a.push_front(x);
        }
        x=b.top();
        b.pop();
        a.push_front(x);
    }
    while(!a.empty()){
        x=a.front();
        g<<x<<' ';
        a.pop_front();
    }
    f.close();
    g.close();
}
