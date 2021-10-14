
#include <bits/stdc++.h>
using namespace std;
 

long find3Numbers(vector<int>& nums) 
{
   
  if (nums.size() < 3){
    return 0;
  }
  long count = 0;
  int seq = 1;        

  int max_num = nums[0];  
   
  int min_seq = INT_MAX;      
   
  int store_max = max_num;   
   
  for (int i = 1; i < nums.size(); i++) 
  {
    if (nums[i] == max_num)
      continue;
     
    else if (nums[i] > max_num) 
    {
      max_num = nums[i];
      continue;
    } 
    else if (nums[i] > min_seq) {    
       
      min_seq = nums[i];       
       
      store_max = max_num;            
    } 
     
    else if (nums[i] < min_seq) 
    {    
      seq++;
       
      if (seq == 3) 
      {            
        count++;
      }
      min_seq = nums[i];
    }
  }

  return count;
   
}
 

int main() {
  vector<int> nums {5,3,4,2,1};
   
  
  cout<<find3Numbers(nums);
}