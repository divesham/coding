#include<iostream>
 #include<queue> 
 #include<algorithm>
 using namespace std;
  
int main(){
    int n,e,src,des;
    cin>>n>>e;
    vector<vector<int> > adj(20001);
    for(int i = 0;i<e;i++){
        cin>>src>>des;
        adj[src].push_back(des);
    }
    queue<int> q;
    vector<bool> visited(20001);
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(visited[node]) {
        cout<<"NO";
        return 0;
        }
        if(!visited[node]){
           visited[node] = true;
           for(auto element:adj[node]){
               q.push(element);
           }
        }
    }
    int siz  = 0;
    for(int i = 0;i<n;i++){
      siz +=adj[i].size();
    }
    if(siz == n-1)
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
} 
