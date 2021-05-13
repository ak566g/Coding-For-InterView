void helper(Node* root, int curSum, int curLen, int &maxLen, int &maxSum){
    if(root==NULL){
        if(curLen>=maxLen){
            maxLen = curLen;
            maxSum = max(maxSum, curSum);
        }
        return;
    }
    
    curSum += root->data;
    curLen += 1;
    helper(root->left, curSum, curLen, maxLen, maxSum);
    helper(root->right, curSum, curLen, maxLen, maxSum);
}

int sumOfLongRootToLeafPath(Node* root)
{
	int maxSum = 0;
	int maxLen = 0;
	helper(root, 0, 0, maxLen, maxSum);
	return maxSum;
}