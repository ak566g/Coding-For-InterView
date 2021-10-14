#include <iostream>
using namespace std;

class A
{
    public:
    virtual void show()
    {
        cout << "Base class\n";
    }
};

class B: public A
{
    private:
    virtual void show()
    {
        cout << "Derived class\n";
    }
};

int main()
{
    A *a;
    A obj;
    B b;
    // obj.show();
    a = &b;
    a->show(); 

    // A a;
    // A obj;
    // B b;
    // // obj.show();
    // a = b;
    // a.show(); 
}
