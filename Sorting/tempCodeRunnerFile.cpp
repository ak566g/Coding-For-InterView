
#include <bits/stdc++.h>
using namespace std;
 

long find3Numbers(vector<int>& nums) 
{
   
  if (nums.size() < 3){
    return 0;
  }
  long count = 0;
  int seq = 1;        
  reverse(nums.begin(), nums.end());
  int min_num = nums[0];  
   
  int max_seq = INT_MIN;      
   
  int store_min = min_num;   
   
  for (int i = 1; i < nums.size(); i++) 
  {