#include <bits/stdc++.h>
using namespace std;
class Rectangle
    {
        int L,B;
 
        public:
        Rectangle(int a,int b)
        {
            L=a;
            B=b;
        }
        int area(int l,int b)
        {
            return l*b;
        }
        friend class Square;        //Statement 1
    };
 
    class Square
    {
        int S;
 
        public:
        Square(int s)
        {
            S=s;
        }
 
        void Display(Rectangle Rect)
        {
            cout<<"\n\n\tLength : "<<Rect.L;
            cout<<"\n\n\tBreadth : "<<Rect.B;
            cout<<"\n\n\tArea : "<<Rect.area(S,S);
        }
    };
 
    int main()
    {
 
        Rectangle R(5,10);
        Square S(5);
 
        S.Display(R);       //Statement 2
        return 0;
    }

