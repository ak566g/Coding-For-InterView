#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *p1= new int [n];
	int *p2= new int [n];
	int winner=1;
	int lead=0;

	// it can be done without array too..
	
	for(int i=0;i<n;i++){
		cin>>p1[i]>>p2[i];

		if(i){
			p1[i]=p1[i]+p1[i-1];
			p2[i]=p2[i]+p2[i-1];
		}
		int tempLead;
		if(p2[i]>p1[i]){
			tempLead=p2[i]-p1[i];
			if(tempLead>lead){
				lead=tempLead;
				winner=2;
			}
		}else{
			tempLead=p1[i]-p2[i];
			if(tempLead>lead){
				lead=tempLead;
				winner=1;
			}
		}
	}

	cout<<winner<<" "<<lead;


	return 0;
}