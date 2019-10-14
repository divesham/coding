#include<iostream>
#include<math.h>
#include<stdio.h>
#define s(x) scanf("%d",&x)
#define LL long long int
using namespace std;
struct sega
{
    LL p_sum,s_sum,t_sum,max1;
};
void seg_t(int l,int h,int a[],sega seg[],int p)
{
    if(l==h)
    {
        seg[p].p_sum=a[l];
        seg[p].s_sum=a[l];
        seg[p].t_sum=a[l];
        seg[p].max1=a[l];
    }
    else
    {
        int mid=(l+h)/2;
        seg_t(l,mid,a,seg,2*p+1);
        seg_t(mid+1,h,a,seg,2*p+2);
        seg[p].p_sum=max(seg[2*p+1].p_sum,seg[2*p+1].t_sum+seg[2*p+2].p_sum);
        seg[p].s_sum=max(seg[2*p+2].s_sum,seg[2*p+2].t_sum+seg[2*p+1].s_sum);
        seg[p].t_sum=seg[2*p+1].t_sum+seg[2*p+2].t_sum;
        seg[p].max1=max(seg[2*p+1].max1,max(seg[2*p+2].max1,seg[2*p+1].s_sum+seg[2*p+2].p_sum));
    }
}
void update(int l,int h, sega seg[],int p,int i,int value){
     if(i<l || i>h)
     return;
     if(l == h){
         seg[p].max1 = value;
         seg[p].p_sum = value;
         seg[p].s_sum = value;
         seg[p].t_sum = value;
        //  cout<<seg[i].p_sum<<" "<<seg[i].s_sum<<" "<<seg[i].t_sum<<" "<<seg[i].max1<<" "<<endl; 
         return;
     }
     
     int mid = (l+h)/2;
     //left child
     update(l,mid,seg,2*p+1,i,value);
     // right child
     update(mid+1,h,seg,2*p+2,i,value);
     seg[p].p_sum = max(seg[2*p + 1].p_sum,seg[2*p+1].t_sum+seg[2*p+2].p_sum);
     seg[p].s_sum = max(seg[2*p+2].s_sum,seg[2*p+2].t_sum+seg[2*p+1].s_sum);
     seg[p].t_sum = seg[2*p+1].t_sum + seg[2*p+2].t_sum;
     seg[p].max1 = max(seg[2*p + 1].max1,max(seg[2*p + 2].max1,seg[2*p +1].s_sum+seg[2*p+2].p_sum));
    
    
     
    //  cout<<"update is called"<<endl;
    //   cout<<seg[p].p_sum<<" "<<seg[p].s_sum<<" "<<seg[p].t_sum<<" "<<seg[p].max1<<" "<<endl; 
    //   cout<<seg[2*p +1].p_sum<<" "<<seg[2*p +1].s_sum<<" "<<seg[2*p +1].t_sum<<" "<<seg[2*p +1].max1<<" "<<endl; 
    //   cout<<seg[2*p +2].p_sum<<" "<<seg[2*p +2].s_sum<<" "<<seg[2*p +2].t_sum<<" "<<seg[2*p +2].max1<<" "<<endl; 
       
     return;
     
}
sega query(int l,int h,int ql,int qh,sega seg[],int p)
{
    if(l>=ql && h<=qh)
    {
        return seg[p];
    }
    else if(h<ql || l>qh)
    {
        sega xy;
        xy.max1=0;
        xy.p_sum=0;
        xy.s_sum=0;
        xy.t_sum=0;
        return xy;
    }
    else
    {
        int mid=(l+h)/2;
        sega s1=query(l,mid,ql,qh,seg,2*p+1);
        sega s2=query(mid+1,h,ql,qh,seg,2*p+2);
        sega s3;
        if(s1.p_sum==0 && s1.s_sum==0 && s1.max1==0 && s1.t_sum==0)
            s3=s2;
        else if(s2.p_sum==0 && s2.s_sum==0 && s2.max1==0 && s2.t_sum==0)
            s3=s1;
        else{
        s3.p_sum=max(s1.p_sum,s1.t_sum+s2.p_sum);
        s3.s_sum=max(s2.s_sum,s2.t_sum+s1.s_sum);
        s3.t_sum=s1.t_sum+s2.t_sum;
        s3.max1=max(s1.max1,max(s2.max1,s1.s_sum+s2.p_sum));
        }
        return s3;
    }
}
int main()
{
   // ios_base::sync_with_stdio(false);
    int n,nn=0;;
    s(n);
    //cin>>n;
   // cout<<"n="<<n<<endl;
    int a[n],i;
    for(i=0;i<n;i++){
        s(a[i]);
        //cin>>a[i];
    }
 
        int sz;
    if((n & (n-1))==0)
        sz=2*n-1;
    else{
        int y=log2(n)+1;
        sz=(2*pow(2,y))-1;
    }
    sega seg[sz];
    seg_t(0,n-1,a,seg,0);
    int m;
    s(m);
   // cout<<" m="<<m<<endl;
    //cin>>m;
    int ch;
    for(i=0;i<m;i++)
    {   s(ch);
    //   cout<<ch;
        int x,y;
       s(x);s(y);
      // cout<<"n="<<n<<" m="<<m<<" x="<<x<<" y="<<y<<endl;
       // cin>>x>>y;
       if(ch == 1){
        sega ss;
        ss=query(0,n-1,x-1,y-1,seg,0);
      //  cout<<"
       // cout<<ss.p_sum<<" "<<ss.s_sum<<" "<<ss.t_sum<<" "<<ss.max1<<"\n";
        //  printf("%lld\n",max(ss.max1,max(ss.p_sum,max(ss.s_sum,ss.t_sum))));
        cout<<max(ss.max1,max(ss.p_sum,max(ss.s_sum,ss.t_sum)))<<endl;
        //cout<<<<"\n";
       }
        if(ch == 0){
          update(0,n-1,seg,0,x-1,y);
      }
    }
    // for(int i = 0;i<sz;i++)
    // cout<<seg[i].p_sum<<" "<<seg[i].s_sum<<" "<<seg[i].t_sum<<" "<<seg[i].max1<<" "<<endl; 
} 
