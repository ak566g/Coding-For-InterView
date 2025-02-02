//by Ankita Gupta

// Shreya loves to eat momos. Her mother gives her money to buy vegetables but she manages to save some money out of it daily. 
// After buying vegetables, she goes to "Momos Market", where there are ‘n’ number of shops of momos. Each of the shops of momos has a rate per momo. 
// She visits the market and starts buying momos (one from each shop) starting from the first shop. She will visit the market for ‘q’ days. 
// You have to tell that how many momos she can buy each day if she starts buying from the first shop daily. 
// She cannot use the remaining money of one day on some other day. 
// But she will save them for other expenses in the future, so, you also need to tell the sum of money left with her at the end of each day.

// Sample Input
// 6
// 3 3 2 8 5 8 
// 4
// 4
// 2
// 25
// 17


#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    ll momos[n];
    
    for(int i=0;i<n;i++)
        cin>>momos[i];
    
    int q;
    cin>>q;
    ll money[q];
    
    for(int i=0;i<q;i++)
        cin>>money[i];
    
    int numMomos=0, moneySaved=0;
    
    int i=0,j=0;
    
    while(j<q)
    {
        if(money[j]>=momos[i])
        {
            money[j]-=momos[i];
            numMomos++;
            i++;
        }
        else{
            moneySaved+=money[j];
            cout<<numMomos<<" "<<moneySaved<<"\n";
            numMomos=0, moneySaved=0;
            i=0;
            j++;
        }
    }
    
	return 0;
}
