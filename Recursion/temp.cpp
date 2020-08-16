#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    int ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
    }

    return ans;
}


int count_sum(int l, int r, int n,vector<int>&v, int sum){

    if(l>r){
        return 0;
    }

    if(n==0){

        if(sum%2==0){
            int count =1;
            
            vector<int>temp;
            temp=v;
            sort(temp.begin(),temp.end());

            while(next_permutation(temp.begin(),temp.end())){
                count++;
            }

            return count;
        }
        else{

            return 0;
        }
    }
    v.push_back(l);
    int ans1=count_sum(l,r,n-1,v,sum+l);
    v.pop_back();
    int ans2=count_sum(l+1,r,n,v,sum);

    return ans1+ans2;
}


int main()
{
    int l, r, n;
    cin>>l>>r>>n;
    vector<int>v;
    cout<<count_sum(l,r,n,v ,0)<<"\n";
}