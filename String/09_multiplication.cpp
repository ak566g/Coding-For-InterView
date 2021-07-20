string Solution::multiply(string a, string b) {
    int m = a.size();
    int n = b.size();
    string ans(m+n, '0');
    
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            int num = (a[i]-'0') * (b[j]-'0') + (ans[i+j+1] -'0');
            ans[i+j+1] = num%10 + '0';
            ans[i+j] += num/10;
        }
    }
    int i=0;
    while(ans[i]=='0'){
        i++;
    }
    
    if(i!=ans.size())
    return ans.substr(i);
    
    return "0";
}
