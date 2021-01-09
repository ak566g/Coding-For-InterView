
// here random pivoting has been used.

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int j=l-1;
    for(int i=l; i<=r-1;i++)
    {
        if(arr[i]<=pivot)
        {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[j+1], arr[r]);
    
    return j+1;
}

int randomPart(int arr[], int l, int r)
{
    
    int num = rand();
    int random = l + num % (r - l + 1);
    swap(arr[random], arr[r]);
    
    return partition(arr, l, r);
    
}

int kthSmallest(int arr[], int l, int r, int k) {
    if(k>0 && k<=r-l+1)
    {
        int pivot = randomPart(arr, l, r);
        
        if(pivot-l==k-1)
        {
            return arr[pivot];
        }
        
        if(pivot-l > k-1)
        {
            return kthSmallest(arr, l, pivot-1, k);
        }
        
        return kthSmallest(arr, pivot+1, r, k-(pivot-l)-1);
    }
    
    return INT_MAX;
}