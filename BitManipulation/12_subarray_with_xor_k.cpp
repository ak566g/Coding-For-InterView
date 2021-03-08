int Solution::solve(vector<int> &A, int B) {
    map<int, int>mp;
    mp[0]=1;
    int count=0;
    int px=0;
    for(int i=0;i<A.size();i++){
        px = px^A[i];
        
        int toFind = px^B;
        
        if(mp.count(toFind)){
            count+=mp[toFind];
        }
        
        mp[px]++;
    }
    
    return count;
}
