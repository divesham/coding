#include <bits/stdc++.h> 
#define ll long long int
using namespace std;
 
int main() {
	 ll t,po,ne,sum,pos,neg;
	 sum = neg = pos = 0;
	 po = ne = 1;
	 cin>>t;
	 while(t!= 0){
	     ll zero = 0;
	      po = ne = 1;
	     long long int arr[t+1];
	     for(ll i = 1;i<=t;i++)
	     cin>>arr[i];
	     for(ll i = 1;i<=t;i++){
	         if(arr[i] == 0)
	          zero++;
	     }
	     
	     while(arr[po]<=0 )
	       po++;
	     while(arr[ne]>=0)
	       ne++;
	       //=========main concept========
	       //while(t != 0){
	       while(zero != t){
	       //for(int i = 0;i<3;i++){
	           
	           //cout<<pos<<endl;
	           if(arr[po] > abs(arr[ne])){
	               sum += (abs(arr[ne]))*abs(po - ne);
	               arr[po] += arr[ne];
	               pos += arr[ne];
	               arr[ne] = 0;
	               zero++;
	               while(arr[ne]>=0 )
	                ne++;
	           }
	           
	           else if(arr[po] < abs(arr[ne])){
	               sum += arr[po] * abs(po - ne);
	               //pos += arr[po];
	               arr[ne] = arr[ne] +arr[po];
	               arr[po] = 0;
	               zero++;
	               while(arr[po]<=0)
	               po++;
	           }
	           else{
	               sum += arr[po]* abs(po - ne);
	               pos += arr[ne];
	               //pos += arr[po];
	               
	               zero+=2;
	               arr[po] = arr[ne] = 0;
	               while(arr[ne]>=0&& ne +1 <= t)
	                ne++;
	               while(arr[po]<=0&& po+1 <= t)
	                po++;
	           }
	       }
	       //=========main concept========
	       cout<<sum<<endl;
	       //for(int i = 1;i<=t;i++){
	       //    cout<<arr[i]<<" ";
	       //}
	       //cout<<endl<<po<<" "<<ne;
	       sum = 0;
	       zero  = 0;
	       cin>>t;
	       }
	return 0;
} 
