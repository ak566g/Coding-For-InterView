#include<iostream>
using namespace std;
class B {
   public:
      virtual void s() {
         cout<<" In Base \n";
      }
};

class D: public B {
   public:
      void s() {
         cout<<"In Derived \n";
      }
};

int main(void) {
   B b;
   D d; // An object of class D
   B *bptr = &d;// A pointer of type B* pointing to d
   b.s();//Can be inlined as s() is called through object of class
   bptr->s();// prints"D::s() called"
   //cannot be inlined, as virtualfunction is called through pointer.
   return 0;
}