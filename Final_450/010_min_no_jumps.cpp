int minJumps(int arr[], int n){
    int maxJumps = arr[0], steps = arr[0], jumps=1;
    
    if(arr[0]==0)
    {
        return -1;
    }
    
    for(int i=1;i<n;i++)
    {
        if(i==n-1)
        {
            return jumps;
        }
        steps--;
        maxJumps = max(maxJumps, arr[i]+i);
        
        if(steps == 0)
        {
            steps = maxJumps-i;
            jumps++;
        }
        
        if(steps == 0)
        {
            return -1;
        }
    }
}
