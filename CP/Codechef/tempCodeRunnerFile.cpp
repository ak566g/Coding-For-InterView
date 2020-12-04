//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

string multiply(string x, string y)
{
    int len1 = x.size();
    int len2 = y.size();

    if(len1==0 || len2 ==0)
    {
        return "0";
    }

    if(len1 == 1 && x[0]=='0')
    {
        return "0";
    }

    if(len2 == 1 && y[0]=='0')
    {
        return "0";
    }

    vector<int> ans (len1+len2, 0);

    int index1 = 0;
    int index2 = 0;

    for(int i=len1-1; i>=0;i--)
    {
        int carry = 0;
        int n1 = x[i]-'0';

        index2 = 0;

        for(int j=len2-1;j>=0;j--)
        {
            int n2 = y[j]-'0';
            int sum = n1 *n2 + ans[index1 + index2] + carry;
            carry = sum/10;
            ans[index1+index2] = sum%10;
            index2++;
        }

        if(carry>0)
        {
            ans[index1+index2]+=carry;
        }
        index1++;
    }

    int i = ans.size()-1;
    while(i>=0 && ans[i]==0)
    i--;

    if(i==-1)
    {
        return "0";
    }

    string s="";
    while (i>=0)
    {
        s+= to_string(ans[i--]);
    }

    return s;
    
}

string add(string a , string b)
{
    string ans = "";

    int i=a.size()-1, j= b.size()-1;
    int carry=0;

    while(i>=0 && j>=0)
    {
        int n1=a[i]-'0';
        int n2=b[j]-'0';
        int sum = n1+n2+carry;
        carry=sum/10;
        sum=sum%10;
        ans = (char)(sum+'0')+ans;
        i--;
        j--;
    }

    while(i>=0)
    {
        int n1=a[i]-'0';
        int sum = n1+carry;
        carry=sum/10;
        sum=sum%10;
        ans = (char)(sum+'0')+ans;
        i--;
    }

    while(j>=0)
    {
        int n2=b[j]-'0';
        int sum = n2+carry;
        carry=sum/10;
        sum=sum%10;
        ans = (char)(sum+'0')+ans;
        j--;
    }

    if(carry>0)
    {
        ans = (char)(carry+'0')+ans;
    }

    return ans;
}

string numToString(int n)
{
    string ans="";
    while(n>9)
    {
        int digit = n%10;
        char ch = digit + '0';
        ans = ch + ans;
        n = n/10;
    }

    int digit = n%10;
    char ch = digit + '0';
    ans = ch + ans;

    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int first, second;
        cin>>first>>second;

        int evenF, oddF, evenS, oddS;
        evenF = first/2;
        oddF = first-evenF;
        evenS = second/2;
        oddS = second - evenS;

        string ef=numToString(evenF); 
        string of=numToString(oddF); 
        string es=numToString(evenS); 
        string os=numToString(oddS); 

        // cout<<ef << " "<<of<<" "<<es<<" "<<os;
        string ee = multiply(ef, ef);
        string oo = multiply(of, os);
        // cout<<ee<<" "<<oo;
        string ans = add(ee, oo);

        cout<<ans;
        cout<<endl;
    }
}