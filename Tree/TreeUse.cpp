#include <iostream>
#include <queue>
#include "TreeNode.h"
#include "Pair.h"
#include<climits>
using namespace std;

TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;
	
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter num of children of " << front->data << endl;
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++) {
			int childData;
			cout << "Enter " << i << "th child of " << front->data << endl;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}



TreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	int n;
	cout << "Enter num of children of " << rootData << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

void printTree(TreeNode<int>* root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size() ; i++) {
		printTree(root->children[i]);
	}
}

//nodesWithMaxChildSum

MaxNodePair<int>* maxSumNodeHelper(TreeNode<int> *root){
	if(root==NULL){
		MaxNodePair<int> *pair= new MaxNodePair<int>();
		pair->node=NULL;
		pair->sum=INT_MIN;
		return pair;
	}
	int sum=root->data;
	for(int i=0;i<root->children.size();i++){
		sum+=root->children[i]->data;

	}
	MaxNodePair<int> *ans=new  MaxNodePair<int>();
	ans->node=root;
	ans->sum=sum;
	for(int i=0;i<root->children.size();i++){
		MaxNodePair<int> *childAns=maxSumNodeHelper(root->children[i]);
		if(childAns->sum>ans->sum){
			ans=childAns;
		}
	}
	return ans;
}
// TreeNode<int>* maxSumNode(TreeNode<int> *root){
// 	return maxSumNodeHelper(root)->node;
// }   
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main() {
	
	TreeNode<int>* root = takeInputLevelWise();
	//printTree(root);
	
	MaxNodePair<int> *ans = maxSumNodeHelper(root);
    if(ans != NULL) {
        cout <<"Ans==="<< ans ->node-> data <<"Sum"<<ans->sum<< endl;
    }
}
