//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int maxSpecialProduct(vector<int> &v) {
    stack<int>st;
    int n=v.size();
    int left[n];
    int right[n];
    left[0]=0;
    right[n-1]=0;
    
    st.push(0);
    
    for(int i=1;i<n-1;i++){
        while(!st.empty() && v[st.top()]<=v[i]){
            st.pop();
        }
        
        if(!st.empty()){
            left[i] = st.top();
        }else{
            left[i] = 0;
        }
        st.push(i);
    }
    
    while(!st.empty())st.pop();
    
    st.push(n-1);
    
    for(int i=n-2;i>0;i--){
        while(!st.empty() && v[st.top()]<=v[i]){
            st.pop();
        }
        
        if(!st.empty()){
            right[i] = st.top();
        }else{
            right[i] = 0;
        }
        
        st.push(i);
    }
    
    int ans = 0;
    
    for(int i=1;i<n-1;i++){
        ans = max(ans, left[i]*right[i]);
    }
    
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<maxSpecialProduct(v);
}

// 11
// 5 9 6 8 6 4 6 9 5 4 9