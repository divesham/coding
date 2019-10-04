#include<iostream>
 #include<queue> 
 #include<algorithm>
 using namespace std;
 
 int main(){
     int fl,src,goal,up,dn;
     cin>>fl>>src>>goal>>up>>dn;
     queue<int> q;
     std::vector<bool> visited(fl+1);
     q.push(src);
    //  visited[src] = true;
     int ans = 0;
     int siz ;
     while(!q.empty()){
         siz = q.size();
         for(int i = 0;i<siz;i++){
         int node = q.front();
         q.pop();
        //  cout<<node<<endl;
         if(node == goal){
             cout<<ans;
             return 0;
         }
         if(!visited[node]){
             visited[node] = true;
             if(node + up <=fl){
                 q.push(node+up);
             }
             if(node - dn>=0){
                 q.push(node - dn);
             }
         }
     }
     ans++;
     }
     cout<<"use the stairs";
     return 0;
 } 
Source code | Plain text | Copy to submit
