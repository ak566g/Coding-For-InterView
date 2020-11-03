// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/hey-please-help-me/

#include <bits/stdc++.h>
using namespace std;

class trieNode{
    public:
    bool isTerminal;
    trieNode **children;
    
    trieNode()
    {
        isTerminal=false;
        children = new trieNode*[26];
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
    }
};


void insertWord(trieNode *root, string s)
{
    if(s.size()==0)
    {
        root->isTerminal = true;
        return;
    }  

    int index = s[0]-'a';
    trieNode *child;
    if(root->children[index]!=NULL)
    {
        child= root->children[index];
    }
    else
    {
        child = new trieNode();
        root->children[index]=child;
    }
    
    insertWord(child, s.substr(1));
}



trieNode* findPrefix(trieNode *root, string prefix)
{
    if(prefix.size()==1)
    {
        int index= prefix[0]-'a';
        return root->children[index];
    }

    int index = prefix[0]-'a';

    if(root->children[index]==NULL)
    {
        return NULL;
    }
    else
    {
        return findPrefix(root->children[index], prefix.substr(1));
    }
}

void autoComplete(trieNode *root, string word)
{
    if(root->isTerminal)
    {
        cout<<word<<"\n";
        //return;
    }

    for(int i=0;i<26;i++)
    {
        if(root->children[i]!=NULL)
        {
            char ch= i+'a';
            autoComplete(root->children[i], word+ch);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    
    trieNode *trie = new trieNode();
    
    while(n--)
    {
        string s;
        cin>>s;
        insertWord(trie, s);
    }
    
    int q;
    cin>>q;

    while(q--)
    {
        string s;
        cin>>s;
        
        trieNode* newroot= findPrefix(trie, s);
        if(newroot==NULL)
        {
            cout<<"No suggestions\n";
            insertWord(trie, s);
        }
        else
        {
            autoComplete(newroot, s);
        }
    }

    return 0;
}