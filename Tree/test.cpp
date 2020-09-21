#include <string>
#include <vector>

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

    
    bool p(string s)
    {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    bool ispallindrome(TrieNode *root, string s)
    {
        if(root->isTerminal)
        {
            if(p(s))
                return true;
        }
        
        for(int i=0;i<26;i++)
        {
            TrieNode *child = root->children[i];
            
            if(child!=NULL)
            {
                string nextString;
                nextString=s+child->data;
                
                if(ispallindrome(child,nextString))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool search(TrieNode *root, string word)
    {
        
        // Base case
        if (word.size() == 0)
        {
            if(root->isTerminal)
                return true;
            else
            {
                if(ispallindrome(root,""))
                    return true;
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
            return false;
        }

        // Recursive call
        return search(child, word.substr(1));
    }
    /*..................... Palindrome Pair................... */
    
bool isPalindromePair(vector<string> words)
{
        //Write your code here
    if(words.size()==0)
        return false;
    for(int i=0;i<words.size();i++)
    {
        add(words[i]);
    }
    for(int i=0;i<words.size();i++)
    {
        string palindrome = string(words[i].rbegin(), words[i].rend());
        if(search(root,palindrome)) {
            return true;
        }
    }
    return false;
}
    













/*bool searchPalindrome(TrieNode *root, string palindrome) {
		if(palindrome.size() == 0) {
			return true;
		}

		int index = palindrome[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}else {
			return false;
		}

		return searchPalindrome(child, palindrome.substr(1));
	}

	bool searchPalindrome(string palindrome) {
		return searchPalindrome(root, palindrome);
	}

    bool isPalindromePair(vector<string> words) {
		for(int i = 0; i < words.size(); i++) {
			add(words[i]);
            for(int j = 1; j < words[i].size(); j++) {
				add(words[i].substr(j));
			}
		}

		for(int i = 0; i < words.size(); i++) {
			string palindrome = string(words[i].rbegin(), words[i].rend());
			if(searchPalindrome(palindrome)) {
				return true;
			}
		}

		return false;
    }*/
};