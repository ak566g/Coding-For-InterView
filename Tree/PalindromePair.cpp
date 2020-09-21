#include<bits/stdc++.h>

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    // For user
    void add(string word)
    {
        if (add(root, word))
        {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */
    
    bool isWordPalindrome(string word)
    {
        int start=0;
        int end=word.size()-1;

        while(start<end)
        {
            if(word[start]!=word[end])
            return false;
            start++;
            end--;
        }
        
        return true;
    }

    bool checkBranches(TrieNode *root, string word)
    {
        if(root->isTerminal)
        {
            if(isWordPalindrome(word))
            return true;
        }

        for(int i=0;i<26;i++)
        {
            TrieNode *child = root->children[i];
            if(child==NULL)
            continue;

            string fwd= word+child->data;

            if(checkBranches(child,fwd))
            return true;
        }

        return false;
    }

    bool palindromeExist(TrieNode *root, string word, int startIndex)
    {
        if(word.size()==0)
        {
            return true;
        }

        if(startIndex==word.size())
        {
            if(root->isTerminal)
            return true;

            return checkBranches(root, "");
        }

        int index=word[startIndex]-'a';
        TrieNode *child = root->children[index];

        if(child==NULL)
        {
            if(root->isTerminal)
            {
                return isWordPalindrome(word.substr(startIndex));
            }
            return false;
        }

        return palindromeExist(child, word, startIndex+1);
    }

    bool isPalindromePair(TrieNode* root, vector<string>words)
    {
        if(words.size()==0)
        return false;

        for(int i=0;i<words.size();i++)
        {
            if(palindromeExist(root, words[i], 0))
            return true;
        }

        return false;
    }

    bool isPalindromePair(vector<string> words)
    {
		for(int i=0;i<words.size();i++)
        {
            reverse(words[i].begin(),words[i].end());
            this->add(words[i]);
            reverse(words[i].begin(),words[i].end());
        }

        return isPalindromePair(this->root, words);
    }

};