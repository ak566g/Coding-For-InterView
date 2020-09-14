//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int* stockSpan(int *price, int size)  {
	stack<int>st;
    int *ans= new int[size];
    
    for(int i=0;i<size;i++)
    {
        while(!st.empty()&&price[st.top()]<price[i])
            st.pop();
        
        if(st.empty())
        {
            ans[i]=i+1;
        }
        else
        {
            ans[i]=i-st.top();
        }
        
        st.push(i);
    }
    
    return ans;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}