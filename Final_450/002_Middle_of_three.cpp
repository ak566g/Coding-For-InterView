class Solution{
  public:
    int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        if(A>B)
        {
            swap(A,B);
        }
        
        if(A>C)
        {
            swap(A, C);
        }
        
        if(B>C)
        {
            swap(B, C);
        }
        
        return B;
    }
};