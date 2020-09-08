//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

void allSubsequence(string s, string output, vector<string>&v)
{
    if(s.size()==0){
        v.push_back(output);
        return;
    }

    allSubsequence(s.substr(1), output, v);
    output+=s[0];
    allSubsequence(s.substr(1),output,v);
   
}

int main(){
    string s;
    cin>>s;

    vector<string>v;

    allSubsequence(s,"",v);

    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
