#include<iostream>
using namespace std;

class A{
	public :
	A(){
		cout<<"In A construstor"<<endl;
	}
	virtual ~A(){
		cout<<"A Dis Called"<<endl;
	}
};

class B : public A{
	public :
	B(){
		cout<<"B const called"<<endl;
	}
	~B(){
		cout<<"B dis called"<<endl;
	}
	
};
int main(){

        B b;
        cout<<"\n\n";
        A a;
        cout<<"\n\n";
		return 0; 
}