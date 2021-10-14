#include <iostream>  
using namespace std;  

int add(int a , int b)  
{  
    return a+b;  
}  


int test(int (*funptr) (int, int)){
    int sum = funptr(5,5);
    return sum;
}

int main()  
{  
  cout << "Address of a main() function is : " <<(void*)&main<< endl;  
  cout<< "Address of add() is : " <<(void *)&add<<endl;

  // declaring function pointer
  int (*funptr)(int, int);
  // assigning address of function pointer to function pointer
  funptr = add;
  
  // using function pointer in main function
  int sum = funptr(5,5);

  // passing function pointer to another function
  cout<<test(funptr)<<"\n";
  
  return 0;  
}  