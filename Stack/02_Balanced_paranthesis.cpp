//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;


bool isBalanced(string exp) 
{
    stack<char>st;
    
    for(int i=0;i<exp.size();i++)
    {
        if(exp[i]=='['||exp[i]=='{'||exp[i]=='(')
            st.push(exp[i]);
        else
        {
            if(st.size()==0)
                return false;
            
            if(st.top()=='['&&exp[i]==']')
                st.pop();
            else  
            if(st.top()=='('&&exp[i]==')')
                st.pop();
            
            else  
            if(st.top()=='{'&&exp[i]=='}')
                st.pop();
        }
    }
    
    if(st.size()==0)
        return true;
    
    return false;
}


int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}