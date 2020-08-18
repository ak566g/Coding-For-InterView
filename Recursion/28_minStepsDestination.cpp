// Given a number-line from -infinity to +infinity. You start at 0 and can go either to the left or to the right. The condition is that in ith move, you take i steps. 
// You are given a Destination , you have to print the minimum number of steps required to reach that destination.

#include<bits/stdc++.h>
using namespace std;

int minStepsToReach(int source, int dest, int i)
{
    if(source==dest)
    return i;

    if(abs(source)>dest)
    return INT_MAX;

    int ans1= minStepsToReach(source+i+1, dest, i+1);
    int ans2= minStepsToReach(source-1-1, dest, i+1);

    return min(ans1,ans2);
}

int minStepsToReach_Optimized(int dest)
{
    dest = abs(dest);
    int step=0;
    int count=0;
    int i=1;
    while(count<dest||(count-dest)%2==1){
        count+=i;
        i++;
        step++;
    }

    return step;
}

int main()
{
    int dest;
    cin>>dest;

    //cout<<minStepsToReach(0,dest,0);   
    cout<<minStepsToReach_Optimized(dest);
}