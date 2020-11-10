//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

bool cmp( const pair<int, int>& a, const pair<int, int>& b)
{
     if (a.second == b.second)  
       return a.first < b.first;
 
   return a.second > b.second;
}

vector<int> frequencySort(int *a, int n)
{
    vector<int>ans;

    unordered_map<int, int>m;

    vector<pair<int, int>> v;

    for(int i=0;i<n;i++)
    {
        m[a[i]]++;
    }

    copy(m.begin(), m.end(), back_inserter(v));
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)  
      while(v[i].second--)
      {
              ans.push_back(v[i].first);
      }
 
   return ans;
}

int main(){

    int n;
    cin>>n;

    int *a = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    vector<int> ans = frequencySort(a,n);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

}