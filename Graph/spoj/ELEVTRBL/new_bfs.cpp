 #include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long f, s,g,u, d;
    cin>>f>>s>>g>>u>>d;
 
    queue<long long> floor;
    floor.push(s);
    floor.push(-1);
    long long ans = 0;
    vector<bool> visited(f+1);
    while(!floor.empty()){
        int node = floor.front();
        floor.pop();
        
        if(node == g) {
         cout<<ans<<endl;
          break;
          } 
        else if(node == -1){
            if(!floor.empty()){
                ans++;
                floor.push(-1);
            }else {
                cout<<"use the stairs"<<endl;
                  break;
                  }
        }
        else if(!visited[node]){
             visited[node] = true;
             if(node - d >= 1 )
             floor.push(node-d);
            if(node + u <= f)
            floor.push(node + u);
        }
    }
    return 0;
} 
