//by Ankita Gupta

// 3
// 2
// suf mas
// 3
// good game guys
// 4
// hell bell best test

#include<bits/stdc++.h>
using namespace std;

int common(vector <string> v1, vector <string> v2){
    int intersection = 0;
    int n1 = v1.size(), n2 = v2.size();

    int i =0, j = 0;

    while(i<n1 && j<n2){
        if(v1[i]==v2[j]){
            intersection++;
            i++;
            j++;
        }
        else if(v1[i]<v2[j]){
            i++;
        }
        else{
            j++;
        }
    }

    return intersection;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<string>v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        
        unordered_map<char, vector<string> >um;
        for(int i = 0; i<26; i++){
            vector<string>temp;
            um[i+'a'] = temp;
        }

        for(int i = 0; i<n ;i++){
            char ch = v[i][0];
            string s = v[i].substr(1);
            um[ch].push_back(s);
        }
        for(int i = 0 ;i < 26; i++){
            sort(um[i+'a'].begin(), um[i+'a'].end());
        }
        int ans = 0;
        for(int i = 0; i<26; i++){
            for(int j = 0; j <26 ; j++){
                char index1 = i+'a';
                char index2 = j+'a';
                int intersection = common(um[index1], um[index2]);

                int n1 = um[index1].size()-intersection;
                int n2 = um[index2].size()-intersection;

                ans += (n1*n2);
            }
        }

        cout<<ans<<"\n";
    }
}