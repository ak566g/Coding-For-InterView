//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
	char str[100];
	cin>>str;
	char hashmap[256];
	for(int i=0;i<256;i++)
		hashmap[i]=0;

	for(int i=0;str[i]!='\0';i++)
	hashmap[str[i]]++;

	int k=0;

	for(int i=0;str[i]!='\0';i++)
	{
		if(hashmap[str[i]]!=0)
		{
			str[k]=str[i];
			k++;
			hashmap[str[i]]=0;
		}
	}
	str[k]='\0';

	cout<<str;
}