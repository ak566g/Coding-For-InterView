#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void deleteString(string s, string p, int x, int y, bool flag){

    if(!flag)return;

    char ch1 = p[0];
    char ch2 = p[1];
    int ans = 0;
    stack<char>st;

    flag = false;

    for(int i=0;i<s.size();i++){
        if(s[i] == ch2){
            if(!st.empty() && st.top()==ch1){
                flag = true;
                st.pop();
                ans+=x;
            }else{
                st.push(s[i]);
            }
        }else{
            st.push(s[i]);
        }
    }

    string remainingS = "";

    while(!st.empty()){
        remainingS += st.top();
        st.pop();
    }

    reverse(remainingS.begin(), remainingS.end());

    if(flag){
        deleteReverseString(remainingS, p, x, y, flag);
    }
}

void deleteReverseString(string s, string p, int x, int y, bool flag){

    if(!flag)return;
    
    char ch1 = p[1];
    char ch2 = p[0];

    int ans = 0;
    stack<char>st;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, p;
    int x, y;
    cin>>s>>p;
    cin>>x>>y;

    
    return 0;
}