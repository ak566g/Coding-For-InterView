int Solution::romanToInt(string v) {
    unordered_map<char , int>um;
    um['M']=1000;
    um['D']=500;
    um['C']=100;
    um['L']=50;
    um['X']=10;
    um['V']=5;
    um['I']=1;
    
    int ans = 0;
    
    for(int i=0;i<v.size();i++){
        ans += um[v[i]];
        if(i>0 && um[v[i]]>um[v[i-1]]){
            ans -= 2*um[v[i-1]];
        }
    }
    return ans;
}
