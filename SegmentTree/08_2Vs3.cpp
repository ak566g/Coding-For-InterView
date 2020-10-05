// Vasya vs Rhezo

// Queen Vasya is preparing for a war against Rhezo. 
// She has N warriors in total arranged in a line. 
// Let us number the warriors by numbers from 1 to N. 
// She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
// For each warrior, we know 2 values associated with him, let us call these A and B. 
// Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. 
// If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. 
// If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.
// You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.



#include<bits/stdc++.h>
using namespace std;
class Warrior{
    public:
    int a;
    int b;
    int index;
};

Warrior compareValue(Warrior t1, Warrior t2)
{
    if(t1.a==t2.a)
    {
        if(t1.b==t2.b)
        {
            if(t1.index<t2.index)
                return t1;
            return t2;
        }
        
        if(t1.b<t2.b)
            return t1;
        return t2;
    }
    
    if(t1.a>t2.a)
        return t1;
    return t2;
}



void buildTree(Warrior *war, int start, int end, Warrior *tree, int ti)
{
    if(start>end)
        return;
    
    if(start==end)
    {
        tree[ti].a=war[start].a;
        tree[ti].b=war[start].b;
        tree[ti].index=war[start].index;
        return;
    }
    
    int mid= (start + end)/2;
    
    buildTree(war, start, mid, tree, 2*ti);
    buildTree(war, mid+1, end, tree, 2*ti+1);
    
    tree[ti]=compareValue(tree[2*ti], tree[2*ti+1]);
    
}

Warrior queryTree(Warrior *tree, int start , int end, int l, int r, int ti)
{
    if(start>end)
    {
        return {0,0,0};
    }
    
    if(start > r || end < l)
    {
        return {0,0,0};
    }
    
    if(start>=l && end<=r)
    {
        return tree[ti];
    }
    
    int mid = (start+end)/2;
    
    Warrior left=queryTree(tree, start, mid, l, r, 2*ti);
    Warrior right=queryTree(tree, mid+1, end,l, r, 2*ti+1);
    
    Warrior ans;
    
    ans=compareValue(left,right);
    
    return ans;
    
    
}

int main() {
	int n;
    cin>>n;
    
    Warrior *war= new Warrior[n];
    
    for(int i=0;i<n;i++)
        cin>>war[i].a;
    
    for(int i=0;i<n;i++)
        cin>>war[i].b;
	
    for(int i=0;i<n;i++)
        war[i].index=i+1;
    
    Warrior *tree= new Warrior[4*n];
    
    buildTree(war,0,n-1,tree,1);
    int q;
    cin>>q;
    
    while(q--)
    {
    	int start , end;
        cin>>start>>end;
        cout<<queryTree(tree, 0, n-1, start-1, end-1, 1).index;
        cout<<endl;
    }
    
}