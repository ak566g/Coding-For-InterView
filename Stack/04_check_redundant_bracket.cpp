//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

bool isSymbol(char c)
{
    if(c=='+'||c=='/'||c=='-'||c=='*'||c=='('||c==')')
        return true;
    
    return false;
}
bool checkRedundantBrackets(string exp) {
	stack<char>st;
    
    for(int i=0;i<exp.size();i++)
    {
        if(exp[i]==')'&&st.top()=='(')
            return true;
        
        else if(exp[i]==')'){
    		while(st.top()!='(')
                st.pop();
            st.pop();
        }
        else if(isSymbol(exp[i]))
            st.push(exp[i]);
    }
    
    return false;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}