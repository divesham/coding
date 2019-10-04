 #include<iostream>
 #include<queue> 
 #include<algorithm>
 using namespace std;
  
    bool dfs(int src,vector<vector<int> > &adj,vector<bool> &visited){
        if(visited[src]){
            return false;
        }
        else{
            visited[src] = true;
            for(auto element: adj[src]){
                if(!dfs(element,adj,visited)) return false;
            }
        }
        return true;
    }
int main(){
    int n,e,src,des;
    cin>>n>>e;
    vector<vector<int> > adj(20001);
    vector<bool> visited(20001);
    for(int i = 0;i<e;i++){
        cin>>src>>des;
        adj[src].push_back(des);
    }
    //  ============dfs===============
    if(dfs(src,adj,visited))  
   {
    //==================dfs_end========================
    int siz  = 0;
    for(int i = 0;i<n;i++){
      siz +=adj[i].size();
    }
    if(siz == n-1)
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
   }
   else{
       cout<<"NO";
   }
    return 0;
} 
