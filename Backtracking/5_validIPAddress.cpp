//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

vector<string>ans;
void helper(string s, int cur, string ip, int part){
    
    if(cur>=s.size()){
        ip.pop_back();
        if(part==4)
    	    ans.push_back(ip);
        return;
    }
    
    int num = 0;
    for(int i=cur;i<s.size();i++){
        if(part<=3){
            ip+=s[i];
            num = num*10 + (s[i]-'0');
            if(num>=256)
                continue;
            helper(s, i+1, ip+'.', part+1);
            if(num==0){
                break;
            }
        }
    }
}

vector<string> generateIPAddress(string s)
{
    ans.clear();
    if(s.size()>12){
        return ans;
    }
    
    helper(s, 0, "", 0);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        vector<string>ans = generateIPAddress(s);

        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }

        cout<<"\n";
    }
}