#include <iostream>
#include <map>
#include <vector>
using namespace std;

string ans = "";

bool parseInputs(string input, map<char, vector<char>>& adjList, map<char, int>& numParents, char& root) {
    char parent;
    int index = 0;
    bool E5Error = false;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] != '(' && input[i] != ')' && input[i] != ',' && input[i] != ' ') {
            index++;
            if (index % 2 == 1) {
                if (i - 1 >= 0 && input[i-1] != '(') {
                    ans = "E1";
                    return false;
                } else if (i + 1 < input.length() && input[i+1] != ',') {
                    ans = "E1";
                    return false;
                } 
                
                parent = input[i];
                
            } else {
                if (i - 1 >= 0 && input[i-1] != ',') {
                    ans = "E1";
                    return false;
                } else if (i + 1 < input.length() && input[i+1] != ')') {
                    ans = "E1";
                    return false;
                } 
                
                for (int j = 0; j < adjList[parent].size(); j++) {
                    if (adjList[parent][j] == input[i]) {
                        ans = "E2";
                        return false;
                    }
                } 
                if (adjList[parent].size() == 2) {
                    ans = "E3";
                    return false;
                }
                
                numParents[input[i]]++;
                numParents[parent];
                if (numParents[input[i]] == 2) {
                    E5Error = true;
                }
                
                adjList[parent].push_back(input[i]);
                index = 0;
            }
        } else if (i - 1 <= 0 && input[i] == ' ') {
            if (input[i] == ' ') {
                ans = "E1";
                return false;
            }
        }
    }
    
    
    int numRoots = 0;
    for (auto kv : numParents) {
        if (kv.second == 0) {
            root = kv.first; 
            numRoots++;
            if (numRoots == 2) {
                ans = "E4";
                return false;
            }
        }
    }
    if (E5Error == true) {
        ans = "E5";
        return false;
    }
    return true;
}

void lexiSExpressionPrint(map<char, vector<char>> adjList, char current) {
   
    ans = ans + "(" + current;
    int numChild = adjList[current].size();
    if (numChild == 1) {
        lexiSExpressionPrint(adjList, adjList[current][0]);
    } else if (numChild == 2) { 
        
        if (adjList[current][0] < adjList[current][1]) { 
            lexiSExpressionPrint(adjList, adjList[current][0]);
            lexiSExpressionPrint(adjList, adjList[current][1]);
        } else {
            lexiSExpressionPrint(adjList, adjList[current][1]);
            lexiSExpressionPrint(adjList, adjList[current][0]);
        }
    }
    ans += ")";

}

string sExpression(string input){
    char root;
    map<char, vector<char>> adjList;
    map<char, int> numParents; 
    if (!parseInputs(input, adjList, numParents, root)) {
        return ""; 
    }
    lexiSExpressionPrint(adjList, root);    
    
    return ans;
}

int main() {
    
    string input;
    getline(cin, input);
    cout<<sExpression(input);
    return 0;
}

