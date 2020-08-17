#include<bits/stdc++.h>
using namespace std;

void insert_stack(stack<int>&st, int n)
{
    if(st.size()==0)
    {
        st.push(n);
        return;
    }

    int a=st.top();
    st.pop();
    insert_stack(st,n);
    st.push(a);
}

void reverse_stack(stack<int>&st)
{
    if(st.size()==0)
    return;

    int temp=st.top();
    st.pop();
    reverse_stack(st);
    insert_stack(st,temp);
}

int main()
{
    stack<int>st;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        st.push(x);
    }

    reverse_stack(st);

    cout<<endl;
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

}