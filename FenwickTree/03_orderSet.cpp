#include <bits/stdc++.h>
using namespace std;


void updateTree(int i, int val, int *bit, int n)
{
    for(;i<=n;i+= (i & (-i)))
    {
        bit[i]+=val;
    }
}

int queryTree(int i, int *bit, int n)
{
    int count=0;
    
    for(; i>0; i-=(i&(-i)))
    {
        count+=bit[i];
    }
    return count;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    
    int *numbers = new int[n];
    char *query = new char[n];

    set<int>s;

    unordered_map<int , bool>hash;
    for(int i=0;i<n;i++)
    {
        cin>>query[i]>>numbers[i];
        if(query[i]=='I')
        {
            s.insert(numbers[i]);
        }
    }
    
    map<int, int>rank;
    map<int, int>reverseMap;
    int count=1;

    for(auto i : s)
    {
        rank[i] =count;
        reverseMap[count]=i;
        count++; 
    }
    
    // for (auto i : rank)
    // {
    //     cout<<i.first<<" "<<i.second<<"\n";
    // }

    int *bit = new int[n+1];
    memset(bit,0,sizeof(bit));
    

    for(int i=0;i<n;i++)
    {
        if(query[i]=='I') // Insert
        {
            int index = rank[numbers[i]];
            if(hash[index]==false)
            {
            	hash[index]=true;
                updateTree(index, 1, bit, n);
            }
        }
        else if(query[i]=='C') // Count
        {
            auto it = s.lower_bound(numbers[i]);
            if(it==s.end())
            {
                cout<<queryTree(s.size()+1, bit, n);
            }
            else if(it == s.begin() && *it==numbers[i])
            {
                cout<<0;
            }
            else
            {
                cout<<queryTree(rank[*it]-1, bit, n);
            }
            cout<<endl;
        }
        else if(query[i]=='K') // Kth smallest
        {
            int start = 1, end= s.size();
            int ans=0;
            int found=false;
            
            while(start<=end)
            {
                int mid = (start+end)/2;
                int count=queryTree(mid, bit, n);
                if(count==numbers[i])
                {
                    found = true;
                    ans=mid;
                    end= mid-1;
                }
                else if(count < numbers[i])
                {
                    start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }
            if(found==false)
            {
                cout<<"invalid\n";
            }
            else
            {
                cout<<reverseMap[ans]<<"\n";
            }
        }
        else if(query[i]=='D') // Delete
        {
            int index = rank[numbers[i]];
            if(hash[index]==true)
            {
                hash[index]=false;
                updateTree(index, -1, bit, n);
            }
        }
    }
    
    return 0;
}
