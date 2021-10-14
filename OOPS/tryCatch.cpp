//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a = 1, b = 0;
    try{
        if(b==0){
            throw b;
        }
        cout<<a/b;
    }catch(int b){
        cout<<"Exception caught";
    }
}