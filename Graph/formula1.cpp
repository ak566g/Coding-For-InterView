#include <bits/stdc++.h>
using namespace std;

// n = number of rows
// f = number of fans
 
long getEarnings(long n, long f, vector<long>seats){
    priority_queue<long>pq;

    for(int i=0;i<seats.size();i++){
        pq.push(seats[i]);
    }

    long earnings = 0;

    while (f--){
        earnings += pq.top();
        long cur = pq.top();
        pq.pop();
        cur--;
        pq.push(cur);
    }
    
    return earnings;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n, f;
    cin>>n>>f;

    vector<long>seats(n);

    for(long i=0;i<n;i++){
        cin>>seats[i];
    }

    cout<<getEarnings(n, f, seats);

    return 0;
}






