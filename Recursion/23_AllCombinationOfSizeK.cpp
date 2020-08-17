// Print all possible combinations of r elements in a given array of size n

#include<bits/stdc++.h>
using namespace std;


void printAllCombinationsOfSizeK(vector<int>v, int k, vector<int>output)
{
    if(output.size()==k)
    {
        for(int i=0;i<k;i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }

    if(v.size()==0)
    return;

    output.push_back(v[0]);
    v.erase(v.begin());
    printAllCombinationsOfSizeK(v,k,output);

    output.pop_back();
    printAllCombinationsOfSizeK(v,k,output);

}


int main()
{
    int n,k;
    cin>>n>>k;
 
    vector<int>v(n);

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    vector<int>output;
    printAllCombinationsOfSizeK(v,k,output);

}
