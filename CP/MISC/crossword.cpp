#include<bits/stdc++.h>
using namespace std;
vector<string>grid;
vector<string>v;
bool isFound = false;

bool isValidRight(int i, int j, string word){
    int wi=0;
    for(int k=j;k<10;k++){
        
        if(wi==word.size()){
            return true;
        }
        
        if(grid[i][k]!='-' && grid[i][k]!=word[wi]){
            return false;
        }
        wi++;
    }
    return wi==word.size();
}

bool isValidDown(int i, int j, string word){
    int wi=0;
    for(int k=i;k<10;k++){
        if(wi==word.size()){
            return true;
        }
        if(grid[k][j]!='-' && grid[k][j]!=word[wi]){
            return false;
        }
        wi++;
    }
    return wi==word.size();
}

void setRight(int i, int j, string word){
    int wi=0;
    for(int k=j;k<10;k++){
        if(wi==word.size()){
            return;
        }
        grid[i][k]=word[wi];
        wi++;
    }
}

void setDown(int i, int j, string word){
    int wi=0;
    for(int k=i;k<10;k++){
        if(wi==word.size()){
            return;
        }
        grid[k][j]=word[wi];
        wi++;
    }
}

void crossword(int index){
    if(index==v.size()){
        isFound = true;
        for(int i=0;i<10;i++){
            cout<<grid[i]<<"\n";
        }
        return;
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(grid[i][j]=='-' || grid[i][j]==v[index][0]){
                vector<string>tempGrid;
                tempGrid = grid;
                if(isValidRight(i,j, v[index])){
                    // insert word at rightword
                    setRight(i,j,v[index]);
                    crossword(index+1);
                    if(isFound){
                        return;
                    }
                }
                grid=tempGrid;
                if(isValidDown(i, j, v[index])){
                    // insert word downword
                    setDown(i,j,v[index]);
                    crossword(index+1);
                    if(isFound){
                        return;
                    }
                }
                grid=tempGrid;
            }
        }
    }
}

int main(){
    for(int i=0;i<10;i++){
        string temp;
        cin>>temp;
        grid.push_back(temp);
    }
    
    string word;
    cin>>word;
    
    
    int i=0;
    while(i<word.size()){
        string temp="";
        while(i<word.size() && word[i]!=';'){
            temp+=word[i];
            i++;
        }   
        v.push_back(temp);
        i++;
    }

    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<"\n";
    // }
    crossword(0);
    // for(int i=0;i<10;i++){
    //     cout<<grid[i]<<"\n";
    // }
    
    // cout<<grid.size();
}