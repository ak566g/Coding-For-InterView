
    }

    for(int i=2;i<MAX;i++){
        if(seive[i]==true && seive[i-2]==true)
        {
            count[i]=count[i-1]+1;
        }
        else{
            count[i]=count[i-1];
        }
    }

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
