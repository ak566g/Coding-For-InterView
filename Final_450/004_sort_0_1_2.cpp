void sort012(int a[], int n)
{
    int start =0, mid =0 ,end = n-1;
    
    
    while(mid <= end)
    {
        if(a[mid]==0)
        {
            swap(a[mid], a[start]);
            start++;
            mid++;
        }
        else if(a[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(a[mid], a[end]);
            end--;
        }
    }
}