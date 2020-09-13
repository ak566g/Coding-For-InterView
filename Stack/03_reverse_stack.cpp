//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
    if(input.size()==0 || input.size()==1)
        return;
    
    int element=input.top();
    input.pop();
    
    reverseStack(input,extra);
    while(input.size()>0)
    {
        int temp=input.top();
        input.pop();
        extra.push(temp);
    }
    input.push(element);
    
    while(extra.size()>0)
    {
        int temp=extra.top();
        extra.pop();
        input.push(temp);
    }
   
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}