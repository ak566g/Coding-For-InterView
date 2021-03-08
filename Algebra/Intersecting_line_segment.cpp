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

    if(o1!=o2 && o3!=o4){
        return true;
    }

    if(o1==0 && onSegment(p1,p2,q1)){
        return true;
    }

    if(o2==0 && onSegment(p1,q2,q1)){
        return true;
    }

    if(o3==0 && onSegment(p2, p1, q2)){
        return true;
    }

    if(o4==0 && onSegment(p2, q1, q2)){
        return true;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, int>p1, q1, p2, q2;
    cin>>p1.first>>p1.second;
    cin>>q1.first>>q1.second;
    cin>>p2.first>>p2.second;
    cin>>q2.first>>q2.second;

    isInterecting(p1, q1, p2, q2)?cout<<"Yes":cout<<"No";
}