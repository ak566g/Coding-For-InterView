//by Ankita Gupta

// There are two assembly lines. Each assembly line has n stations.
// Every station has some dedicated job that needs to done. For a station number i, you can get the job done on station number i of any assembly line.
// You can go to station i only when you have been through station i-1.
// From a station i, you can either go to the next station on the same line or you can transfer assebly line.
// For moving in same assembly line no extra charges will be taken
// For moving from assembly line 1 to assembly line 2 or vice versa from i-1 to i, transfer charge will be caused

// Information provided –
// time to enter station 1 on both assembly lines
// time to exit last station on both lines
// job processing time for every station
// The time to transfer from each station of assembly line 1 to next station of assembly line 2 is given
// The time to transfer from each station of assembly line 2 to next station of assembly line 1

// Objective of the problem is to finish all the jobs in minimum time.

#include<bits/stdc++.h>
using namespace std;


int assemblyLineScheduling(int n, vector<int>entry, vector<int>exit, vector<vector<int>>process, vector<vector<int>>transfer)
{
    vector<vector<int>>dp(2,vector<int>(n));
    dp[0][0]=entry[0]+process[0][0];
    dp[1][0]=entry[0]+process[1][0];

    for(int i=1;i<n-1;i++){
        //selecting minimum cost till i in line 1
        dp[0][i]=min(dp[0][i-1]+process[0][i], dp[1][i-1]+process[0][i]+transfer[1][i-1]);
        //selecting minimum cost till i in line 2
        dp[1][i]=min(dp[1][i-1]+process[1][i], dp[0][i-1]+process[1][i]+transfer[0][i-1]);
    }

    dp[0][n]=dp[0][n-1]+exit[0];
    dp[1][n]=dp[1][n-1]+exit[1];

    return min(dp[0][n],dp[1][n]);
}

int main(){

    int n;
    cout<<"Enter number of stations\t";
    cin>>n;

    vector<vector<int>>process(2,vector<int>(n));
    vector<vector<int>>transfer(2,vector<int>(n-1));
    vector<int>entry(2);
    vector<int>exit(2);
    
    cout<<"Enter the entry time for assebly line 1 and 2 respectively\n";
    cin>>entry[0]>>entry[1];

    cout<<"Enter the exit time for assebly line 1 and 2 respectively\n";
    cin>>exit[0]>>exit[1];

    cout<<"Enter process costs for stations in assembly line 1\n";
    for(int i=0;i<n;i++){
        cin>>process[0][i];
    }

    cout<<"Enter process costs for stations in assembly line 2\n";
    for(int i=0;i<n;i++){
        cin>>process[1][i];
    }

    cout<<"Enter transfer costs for line 1\n";
    for(int i=0;i<n-1;i++){
        cin>>transfer[0][i];
    }

    cout<<"Enter transfer costs for line 2\n";
    for(int i=0;i<n-1;i++){
        cin>>transfer[1][i];
    }
    
    cout<<"The minimum time required to get all the jobs done is\t";
    cout<<assemblyLineScheduling(n, entry, exit, process, transfer);

}   