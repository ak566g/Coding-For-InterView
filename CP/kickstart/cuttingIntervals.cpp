#include <bits/stdc++.h>
#define ff first
#define ss second
#define ppi pair<int, pair<int, int>>
#define pi pair<int, int>
using namespace std;


int helper(vector<ppi>v, int c){
    priority_queue<ppi, vector<ppi>, greater<ppi>>pq;
    for(int i=0;i<v.size();i++){
        pq.push(v[i]);
    }

    while (c--)
    {
        auto temp = pq.top();
        pq.pop();
        int cutPostion = (temp.ss.ff + temp.ss.ss)/2;
        ppi temp1, temp2;
        temp1.ss.ff = temp.ss.ff;
        temp1.ss.ss = cutPostion;

        temp2.ss.ff = cutPostion;
        temp2.ss.ss = temp.ss.ss;

        temp1.ff = temp1.ss.ss - temp1.ss.ff;
        temp2.ff = temp2.ss.ss - temp2.ss.ff;

        pq.push(temp1);
        pq.push(temp2);
    }
    

    return pq.size();
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while (t--)
    {
        int n, c;
        cin>>n>>c;

        vector<ppi>v;
        for(int i=0;i<n;i++){
            ppi temp;
            cin>>temp.ss.ff>>temp.ss.ss;
            temp.ff = temp.ss.ss - temp.ss.ff;
            v.push_back(temp);
        }

        cout<<helper(v,c)<<"\n";

    }
    

    return 0;
}