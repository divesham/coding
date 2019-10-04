#include <bits/stdc++.h>
using namespace std;
class Graph{
    unordered_map<int, list<int>> adjList;
    public:
    void add_Edge(int src,int de,bool bidir = true){
        adjList[src].push_back(de);
        if(bidir == true){
            adjList[de].push_back(src);
        }
    }
    void dfs_helper(int node,unordered_map<int,bool> &vis){
        vis[node] = true;
        for(auto neighbour:adjList[node]){
            if(!vis[neighbour]){
                dfs_helper(neighbour, vis);
            }
        }
    }
 
    void dfs(){
         unordered_map<int, bool> vis;
        int component = 0;
        for(auto i:adjList){
            if(!vis[i.first]){
                dfs_helper(i.first, vis);
                component++;
            }
        }
         printf("\n%d",component);
    }
};
void find(){
    Graph  g;
    int N, e;
    cin >> N >> e;
    for (int i = 0; i < N;i++){
        g.add_Edge(i, i);
    }
    int a, b;
    for (int i = 0; i < e;i++){
        cin >> a >> b;
        g.add_Edge(a, b);
    }
    g.dfs();
}
int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t;i++){
         
        find();
    }
}  
