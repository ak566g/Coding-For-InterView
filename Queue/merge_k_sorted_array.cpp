#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Triplet			//Implementation of triplet class
{
    public:
    int element;
    int aI;
    int eI;
};

class cmp{				//Comparator
    public:
  	bool operator()(Triplet &t1, Triplet &t2)
    {
        return t1.element>t2.element;
    }
  
};

vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    priority_queue<Triplet,vector<Triplet>,cmp> pq;	//We want to store 3 items in the pq
    
    int k=input.size();				//Size of vector containing the vector pointers
    vector<int>ans;
    
    for(int i=0;i<k;i++)
    {
        Triplet temp;
        temp.element=input[i]->at(0);
        temp.aI=i;
        temp.eI=0;
        pq.push(temp);
    }									//Pushing the initial values of each vector in the PQ
    
    while(pq.size()!=0)					//Performing the task till the pq isn't empty
    {
        Triplet temp=pq.top();
        pq.pop();
        int arrayIndex=temp.aI;
        int elementIndex=temp.eI;
        int elem=temp.element;
        ans.push_back(elem);
        
        if(elementIndex<input[arrayIndex]->size()-1)			//If the elementIndex is within the size of the vector[arrayIndex]
        {
            elementIndex++;
            temp.element=input[arrayIndex]->at(elementIndex);
            temp.aI=arrayIndex;
            temp.eI=elementIndex;								//Find all the values i.e. element value, aI, eI
            pq.push(temp);
        }
    }
    
    return ans;
    
}


int main() {
	
	int k;
	cin >> k;
    vector<vector<int>*> input;
    for(int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;
        
        for(int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current -> push_back(a);
        }
        input.push_back(current);
    }
	
	
	vector<int> output = mergeKSortedArrays(input);

	for(int i = 0; i < output.size(); i++)
		cout << output[i] << " ";
	
	return 0;
}
