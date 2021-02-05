//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int extractTime(string time){
    int hour = (time[0]-'0')*10 + (time[1]-'0');
    int minute = (time[3]-'0')*10 + (time[4]-'0');
    if(time[5]=='P' && hour!=12){
        hour+=12;
    }
    if(time[5]=='A' && hour==12){
        hour-=12;
    }
    int ans = hour*60 + minute;

    return ans;
}

char calculate(string meeting, string start, string end){
    int mTime = extractTime(meeting);
    int startTime = extractTime(start);
    int endTime = extractTime(end);
    
    // cout<<"----"<<"\n";
    // cout<<mTime<<" "<<startTime<<" "<<endTime<<"\n";
    if(startTime<= mTime && mTime <=endTime)
        return '1';

    return '0';
}

int main(){
    int t;
    cin>>t;

    while(t--){
        string meeting, meetingS;
        cin>>meeting>>meetingS;
        string ans = "";
        int n;
        cin>>n;

        for(int i=0;i<n;i++){
            string start, startS, end, endS;
            cin>>start>>startS>>end>>endS;

            ans = ans + calculate(meeting+meetingS, start+startS, end+endS);
        }

        cout<<ans<<endl;
    }
}