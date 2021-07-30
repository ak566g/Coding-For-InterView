#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll helper(int l, int h, int sum, int k){

   if(k==0){
      if(sum%2==0)
         return 1;
      return 0;
   }

   if(l>h){
      return 0;
   }

   int ans1 = helper(l, h, sum+l, k-1);
   int ans2 = helper(l+1, h, sum, k);

   return ans1+ans2;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout<<helper(1, 2, 0, 3);
   return 0;
}