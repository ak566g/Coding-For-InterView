#include<bits/stdc++.h>
using namespace std;

void delete_middle(stack<int>&st, int k)
{
    if(k==1){
        st.pop();
        return;
    }

    int temp= st.top();
    st.pop();
    delete_middle(st,k-1);
    st.push(temp);
}

int main()
{
    int n;
    stack<int>st;
    cin>>n;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        st.push(x);
    }

    delete_middle(st, n/2+1);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

}