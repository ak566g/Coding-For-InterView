//by Ankita Gupta

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Vehicle{
    public:
    Vehicle(){
        cout<<"Vehicle\n";
    }
    virtual ~Vehicle(){
        cout<<"dv\n";
    }
};

class Car : public Vehicle{
    public:
    Car(){
        cout<<"Car\n";
    }
    ~Car(){
        cout<<"dc\n";
    }
};

int main() {
    // Car *car = new Car();
    Vehicle *car = new Car();
    // Car car;
    delete car;
}