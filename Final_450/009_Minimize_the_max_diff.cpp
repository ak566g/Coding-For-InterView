#define pi pair<int , int >

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        vector<pi>v;
        vector<int>visited(n);
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]-k>=0)
            {
                v.push_back({arr[i]-k, i});
            }
            
            if(arr[i]+k>=0)
            {
                v.push_back({arr[i]+k, i});
            }
            visited[i]=0;
        }
        
        sort(v.begin(), v.end());
        
        int start = 0, end = 0;
        int count = 0;
        
        while(count<n && end<v.size())
        {
            if(visited[v[end].second]==0)
            {
                count++;
            }
            visited[v[end].second]++;
            end++;
        }
        int ans = v[end-1].first - v[start].first;
        
        while(end<v.size())
        {
            if(visited[v[start].second]==1)
            {
                count--;
            }
            visited[v[start].second]--;
            start++;
            
            while(count<n && end<v.size())
            {
                if(visited[v[end].second]==0)
                {
                    count++;
                }
                visited[v[end].second]++;
                end++;
            }
            if(count==n)
            {
                ans = min(ans, v[end-1].first - v[start].first);
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};