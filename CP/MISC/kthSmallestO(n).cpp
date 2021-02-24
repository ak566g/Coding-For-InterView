#include<bits/stdc++.h>
using namespace std;

//random partioning

int partition(int *a, in)

int find_pivot(int *a, int start, int end){

    srand(time(NULL));
    int random=start+rand()%(end-start);

    swap(a[end],a[ranom]);

    return partition(a,start,end);
}

int kthSmallest(int *a, int k,int start, int end){

        if(k>0&&k<=end-start+1){
            int pos=find_pivot(a,start,end);

            if(pos-start==k-1){
                return a[pos];
            }

            //if position is more then find in left subarray
            if(pos-l>k-1){
              return  kthSmallest(a,k,start,pos-1,n);
            }
            

            return kthSmallest(a,k-pos+1,pos+1,end);
        }

    return INT_MAX;
}

int main()
{
    int n;
    cin>>n;
    int *a= new int[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<kthSmallest(a,k,0,n-1);

}