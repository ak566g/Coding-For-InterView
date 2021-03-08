//by Ankita Gupta

#include<bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

bool onSegment(pi p, pi q, pi r){

    return 
    (
        q.first <= max(p.first, r.first)&&
        q.first >= min(p.first, r.first)&&
        q.second <= max(p.second, r.second)&&
        q.second >= min(p.second, r.second)
    );
}

int orientation(pi p, pi q, pi r){
    int val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first)*(r.second - q.second);

    if(val == 0){
        return 0;
    }

    if(val > 0 ){
        return 1;
    }

    return 2;
}

bool isInterecting(pi p1, pi q1, pi p2, pi q2){
    int o1 = orientation(p1,q1,p2);
    int o2 = orientation(p1,q1,q2);
    int o3 = orientation(p2,q2,p1);
    int o4 = orientation(p2,q2,q1);

    // if lines are not collinear

    if(o2 == 0 && onSegment(p1,q2,q1)){
        return false;
    }

    if(o1!=o2 && o3!=o4){
        return true;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while (t--)
    {
        int n;
        cin>>n;

        int a[n];

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int maxAns = 1;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool cut = false;
                for(int k=j;k>=i;k--){
                    pi p1 = {i, a[i]};
                    pi p2 = {j, a[j]};
                    pi p3 = {k, 0};
                    pi p4 = {k, a[k]};

                    cut = isInterecting(p1, p2, p3, p4);
                    if(cut){
                        break;
                    }
                }

                if(!cut){
                    // cout<<"Here";
                    maxAns = max(maxAns, j-i);
                }
            }
        }
        
        cout<<maxAns<<"\n";
    }
    
}