    #include<iostream>
 #include<list>
 #include<map>
 #include<queue>
 using namespace std;
 template<typename T>
 class Graph{
     map<T,list<T> > adjList;
     public:
     Graph(){
         
     }
     void addEdge(T s,T e,bool bidir=true){
         adjList[s].push_back(e);
         if(bidir){
             adjList[e].push_back(s);
         }
     }
     
     void print(){
         for(auto i:adjList){
             cout<<i.first<<"->";
             for(T entry:i.second){
                 cout<<entry<<",";
             }
             cout<<endl;
         }
     }

     //  ================check cycle for undirected praphs==================
     bool Iscyclic_BFS(T src){
         map<T, bool> visited;
         map<T, T> parent;
         queue<T> q;
         q.push(src);
         visited[src] = true;
         parent[src] = src;
         while(!q.empty()){
             T node = q.front();
             q.pop();
             for(T neighbour:adjList[node]){
                 if(visited[neighbour] == true &&parent[node] != neighbour){
                     return true;
                 }
                 else if(!visited[neighbour]){
                     visited[neighbour] = true;
                     parent[neighbour] = node;
                     q.push(neighbour);
                 }
             }
         }
         return false;
     }
     //  ================END "check cycle for undirected praphs"==================
     //=============================== Cycle Detection in Directed Graph using DFS=============
     bool iscycleHelper(T node,map<T,bool> &visited,map<T,bool> &Instack){
         // processing the current node - visited, Instack
         visited[node] = true;
         Instack[node] = true;
         // explore the neighbour of the node
         for(T neighbour:adjList[node]){
             //Two things can happen 
             // the current node is not visited but it's further branch is leading in a cycle or it it is in Instack I.e Back Edge
             if((!visited[neighbour] && iscycleHelper(neighbour,visited,Instack))|| Instack[neighbour]){
                 return true;
             }
         }
         //Going to pop out the node and Instack[node] = false
         Instack[node] = false;
        //  and finally return false if till now cycle is not detected
         return false;
     }
     bool IsCyclic(){
         map<T,bool> visited;
         map<T, bool> Instack;
         // To check for cycle in each dfs tree
         for(auto i:adjList){
             T node = i.first;
             if(!visited[node]){
                 bool cyclePresent = iscycleHelper(node, visited, Instack);
                 if(cyclePresent){
                     return true;
                 }
             }
         }
         return false;
     }
     //=============================== END OF "Cycle Detection in Directed Graph using DFS"=============
 };
  
 
 int main(){
//  	Graph g(5);
    Graph<int> g;
 	g.addEdge(0,1);
 	g.addEdge(0,4);
 	g.addEdge(4,3);
 	g.addEdge(1,4);
 	g.addEdge(1,2);
 	g.addEdge(2,3);
 	g.addEdge(1,3);
    if(g.Iscyclic_BFS(0)){
        cout << "cycle is present" << endl;
    }else
        cout << "cycle is not present" << endl;
    // g.print();
    // g.addEdge(0, 2, false);
    // g.addEdge(0, 1, false);
    // g.addEdge(2, 3, false);
    // g.addEdge(2, 4, false);
    // // g.addEdge(3, 0, false);
    // g.addEdge(4, 5, false);
    // g.addEdge(1, 5, false);
    // if(g.IsCyclic())
    //     cout << "CYCLE is present";
    // else
    //         cout<<"cycle is not present";

 }
 
 
