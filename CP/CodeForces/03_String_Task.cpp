//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    return (c=='a'||c=='o'||c=='y'||c=='e'||c=='u'||c=='i');
}

int main(){
    string s;
    cin>>s;

    string ans="";

    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            s[i]=s[i]-'A'+'a';
        }
    }

    for(int i=0;i<s.size();i++)
    {
        if(!isVowel(s[i]) && s[i]>='a' && s[i]<='z')
        {
            ans+=".";
            ans+=s[i];
        }
    }

    cout<<ans;
}