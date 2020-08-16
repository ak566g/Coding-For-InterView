

#include<bits/stdc++.h>
using namespace std;
int maxProfit(int *a, int start, int end, int year)
{
    if(start>=end){
        return 0;
    }

    int ans1 = a[start]*(year)+ maxProfit(a,start+1, end,year+1);
    int ans2= a[end-1]*(year)+maxProfit(a,start,end-1,year+1);

    return max(ans1,ans2);
}


int main()
{
    int n;
    cin>>n;

    int *a = new int [n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<maxProfit(a, 0, n, 1);
}