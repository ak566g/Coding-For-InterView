//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

class Base{
    public:
        int f(int a){
            cout<<"int";
            return a;
        }
};

class Child : public Base{
    public :
    int f(double a){
        cout<<"double";
        return a;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Child c;
    cout<<c.f(5);
    cout<<c.f(5.5);
}