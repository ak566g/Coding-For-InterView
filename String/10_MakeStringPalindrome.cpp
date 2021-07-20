// https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

int Solution::solve(string s) {
    int start = 0, end = s.size()-1;
    int ans = 0;
    while(start<=end){
        if(s[start]!=s[end]){
            if(start==0)
                end--;
            else{
                start = 0;
            }
            
            ans = s.size()-end - 1;
        }else{
            start++;
            end--;
        }
    }
    return ans;
}