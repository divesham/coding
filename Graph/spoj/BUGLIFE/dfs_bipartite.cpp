 #include <bits/stdc++.h> 
#define ll long long int
using namespace std;
 
void addEdge(int src,int des,vector<int > adj[]){
    adj[src].push_back(des);
    adj[des].push_back(src);
}
bool isBipartite(int u,vector<int> adj[],vector<bool> &visited,vector<bool> &color){
    for(auto v:adj[u]){
        if(!visited[v]){
            visited[v] = true;
            color[v] = !color[u];
            if(!isBipartite(v,adj,visited,color))
            return false;
        }
        if(color[v] == color[u])
        return false;
    }
    return true;
}
 
 
int main() {
	 int t,flag = 0;
	 cin>>t;
	 for(int k = 1;k<= t;k++){
	    flag = 0;
	    vector<bool> visited(1000001);
	    vector<int> adj[1000001];
	    vector<bool> color(1000001);
	    int n,e,src,des;
	    cin>>n>>e;
	    for(int i = 0;i<e;i++){
	        cin>>src>>des;
	        addEdge(src,des,adj);
	    }
	    for(int i = 0;i<n;i++){
	        if(!visited[i]){
	             color[i] = true;
	             visited[i] = true;
	             if(!isBipartite(i,adj,visited,color)){
	                 cout<<"Scenario #"<<k<<":"<<endl;
                     cout<<"Suspicious bugs found!"<<endl;
                     flag = 1;
                     break;
	             }
	        }
	    }
	    if(flag == 0){
	    cout<<"Scenario #"<<k<<":"<<endl;
	    cout<<"No suspicious bugs found!"<<endl;
	    }
	   
	    
	    
	 }
	return 0;
} 
