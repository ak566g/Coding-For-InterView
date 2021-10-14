//by Ankita Gupta

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        int a=0, b=0, c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='A')a++;
            if(s[i]=='B')b++;
            if(s[i]=='C')c++;
        }
        bool flag = true;
        if(c>b)flag = false;

        b-=c;

        if(a!=b){
            flag = false;
        }

        if(flag){
            cout<<"YES";
        }else{
            cout<<"NO";
        }

        cout<<"\n";
    }
}