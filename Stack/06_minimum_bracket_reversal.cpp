//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int countBracketReversals(string input) {
	if(input.size()%2==1)
        return -1;
    
    stack<char>st;
    
    for(int i=0;i<input.size();i++)
    {
       if(!st.empty() && st.top()=='{' && input[i]=='}')
                st.pop();
       else st.push(input[i]);
    }
    
    int count=0;
    
    while(!st.empty())
    {
        char ch1= st.top();
        st.pop();
        char ch2=st.top();
        st.pop();
        
        if(ch1==ch2)
            count+=1;
        else 
            count+=2;
    }
    
    return count;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}