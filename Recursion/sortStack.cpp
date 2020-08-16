#include<bits/stdc++.h>
using namespace std;


void insert(stack<int>&st, int temp)
{
    if(st.size()==0||st.top()>=temp){
        st.push(temp);
        return;
    }

    int val= st.top();
    st.pop();
    insert(st,temp);
    st.push(val);
}

void sort_stack(stack<int>&st){
    if(st.size()==1){
        return;
    }

    int temp= st.top();
    st.pop();
    sort_stack(st);

    insert(st, temp);
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

    sort_stack(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

}