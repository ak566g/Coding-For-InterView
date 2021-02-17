//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

bool visited[100000];
int dist[100000];
vector<int>graph[100000];   
bool isPrime[100000];
vector<int>primes;

int diff(int a, int b){
    int cnt=0;

    while(a>0){
        if(a%10!=b%10){
            cnt++;
        }
        a=a/10;
        b=b/10;
    }

    return cnt;
}


void init(){
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0]=false;
    isPrime[1]=false;

    for(int i=2;i<=9999;i++){
        if(isPrime[i]==true){
            for(int j=i*2;j<=9999;j+=i){
                isPrime[j]=false;
            }
        }
    }

    for(int i=1000;i<=9999;i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }

    // for(int i=0;i<primes.size();i++){
    //     cout<<primes[i]<<" ";
    // }

    for(int i=0;i<primes.size();i++){
        for(int j=0;j<primes.size();j++){
            if(diff(primes[i], primes[j])==1){
                graph[primes[i]].push_back(primes[j]);
            }
        }
    }
}

void bfs(int node){
    queue<int>q;
    q.push(node);
    visited[node]=true;
    dist[node]=0;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(auto child: graph[current]){
            if(visited[child]==false){
                visited[child]=true;
                dist[child] = dist[current]+1;
                q.push(child);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();

    int t;
    cin>>t;

    while(t--){
        int x, y;
        cin>>x>>y;

        for(int i=1000;i<=9999;i++){
            visited[i]=false;
            dist[i]=-1;
        }

        bfs(x);


        if(visited[y]==true){
            cout<<dist[y];
        }else{
            cout<<"Impossible";
        }

        // cout<<visited[y];
        cout<<"\n";
    }
}