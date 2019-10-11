#include <bits/stdc++.h> 
#define ll long long int
using namespace std;
void find(){
     int n;
     cin>>n;
     int a,b;
     std::vector<pair<int,int> > m ;
     for(int i = 0;i<n;i++){
         cin>>a>>b;
         m.push_back(make_pair(b,a));
     }
     sort(m.begin(),m.end());
     auto it = m.begin();
     int work = 1;
     int end = it->first;
    //  cout<<it->second<<" "<<it->first<<endl;
     it++;
     
     while(it != m.end()){
        //   cout<<it->second<<" "<<it->first<<endl;
         if(it->second >= end){
            //  cout<<it->second<<" "<<end<<endl;
            //   cout<<"inside "<<it->second<<" "<<it->first<<endl;
             end = it->first;
             work++;
         }
         it++;
     }
     cout<<work<<endl;
}
 
int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)
    find();
    return 0;
}
  
