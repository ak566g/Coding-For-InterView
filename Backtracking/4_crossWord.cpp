//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

vector<string>grid(10);
vector<string>words;

bool check;

void crossword(int index)
{

    // check is initially true but becomes false when all words are covered
    if(!check){
        return;
    }
    
    
    if(index==words.size())
    {
        if(check){
            for(auto x : grid){
                cout<<x<<"\n";
            }

            // Here if all words are covered then check will become false.
            // and for all calls it will return and will not call further.
            check=false;
            return;
        }
    }
    
    int i,j, p,q, k;
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
           
            p=i, q=j;
            
            // this will find space in right word direction
            for(k=0;k<words[index].size()&&p+k<10;k++)
            {
                if(grid[p+k][q]!='-'&& grid[p+k][q]!=words[index][k]){
                    break;
                }
            }
            
            if(k==words[index].size()){

                // in temp old grid will be stored, after backtracking
                vector<string>temp=grid;
                for(k=0;k<words[index].size();k++)
                {
                    grid[p+k][q]=words[index][k];
                }
                crossword(index+1);

                // after backtracking for previous returning to previous state
                grid=temp;
            }
            
             p=i, q=j;
            
            for(k=0;k<words[index].size()&&q+k<10;k++)
            {
                if(grid[p][q+k]!='-'&& grid[p][q+k]!=words[index][k]){
                    break;
                }
            }
            
            if(k==words[index].size()){
                vector<string>temp=grid;
                for(k=0;k<words[index].size();k++)
                {
                    grid[p][q+k]=words[index][k];
                }
                
                crossword(index+1);
                grid=temp;
            }
            
            
        }
    }
    
}

int main()
{
    check=true;

    for(int i=0;i<10;i++){
        cin>>grid[i];
    }
    
    string sentence;
    cin>>sentence;
    
    string temp="";
    for(auto x:sentence){
        if(x==';'){
            words.push_back(temp);
            temp="";
        }else{
            temp+=x;
        }
    }
    words.push_back(temp);
    
    crossword(0);
    
}