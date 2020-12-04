//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    int d1, v1, d2, v2, p;
    cin>>d1>>v1>>d2>>v2>>p;

    if(d1>d2)
    {
        swap(d1,d2);
        swap(v1,v2);
    }

    // cout<<d1<<" "<<d2;

    int dayCount=d1-1;
    int gap= d2-d1;

    if(v1*gap > p)
    {
        dayCount += ceil(p*(1.0)/ v1);
    }

    else{
        dayCount +=  gap;
        p= p - (v1*gap);
        v1 = v1+v2;
        dayCount+= ceil(p*(1.0)/ v1);
    }
    cout<<dayCount;
}   