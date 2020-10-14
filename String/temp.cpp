//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

char slowest(vector<vector<int>> keyTimes)
{
    vector<pair <char, int> >ans;

    vector<int>temp= keyTimes[0];

    ans.push_back({temp[0]+'a', temp[1]});


    for(int i=1;i<keyTimes.size();i++)
    {
        vector<int>temp1 = keyTimes[i];
        vector<int>temp2 = keyTimes[i-1];

        pair<char ,int> p= { temp1[0]+'a', temp1[1]-temp2[1] };
        //cout<<p.first <<" "<<p.second<<"\n";

        ans.push_back(p);
    }

    char result = ans[0].first;
    int val =0;

    for(int i=1; i< ans.size();i++)
    {
        if(ans[i].second > val)
        {
            val = ans[i].second;
            result = ans[i].first;
        }
    }
    
    return result;
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>>v;

    for(int i=0;i<n;i++)
    {
        vector<int>temp;
        int x, y;

        cin>>x>>y;
        temp.push_back(x);
        temp.push_back(y);

        v.push_back(temp);
    }

    cout<<slowest(v);

}