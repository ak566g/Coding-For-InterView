class Solution{
    public:
    
    Node* helper(int in[], int pre[], int inStart, int inEnd, int pStart, int pEnd){
        if(inStart>inEnd){
            return NULL;
        }
        
        Node *curNode = new Node(pre[pStart]);
        int inIndex = -1;
        
        for(int i=inStart; i<=inEnd; i++){
            if(pre[pStart]==in[i]){
                inIndex = i;
                break;
            }
        }
        
        
        int lis = inStart;
        int lie = inIndex - 1;
        int ris = inIndex + 1;
        int rie = inEnd;
        
        int lps = pStart+1;
        int lpe = lps + (lie-lis);
        int rps = lpe+1;
        int rpe = pEnd;
        
        
        Node* left = helper(in, pre, lis, lie, lps, lpe);
        Node* right = helper(in, pre, ris, rie, rps, rpe);
        
        curNode->left = left;
        curNode->right = right;
        
        return curNode;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        return helper(in, pre, 0, n-1, 0, n-1);
    }
};