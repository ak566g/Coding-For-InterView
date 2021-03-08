int Solution::solve(vector<int> &A, int B) {
    int count = 0;
    set<int>s;
    
    for(int i=0;i<A.size();i++){
        s.insert(A[i]);
        int toFind = A[i]^B;
        
        if(s.count(toFind)>0){
            count++;
        }
    }
    return count;
}
