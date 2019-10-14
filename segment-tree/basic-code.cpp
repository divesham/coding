#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
void create(int tree[],int arr[],int index,int start,int end){
    //base case
    if(start == end){
        tree[index] = arr[start];
        return;
    }
    if(start > end )
      return;
    //recursive case
    int mid = start + (end - start) / 2;
  
    create(tree, arr, index * 2, start, mid);
    create(tree, arr, index * 2 + 1 , mid+1, end);
     int left = tree[index * 2];
     int right = tree[index * 2 + 1];
     tree[index] = min(left, right);
}

int query(int tree[],int index,int start,int end,int qstart,int qend){
    // 3 case
    //1st - complete overlap i.e start and end is completely inside the query range
    if(start>=qstart && end<=qend)
    return tree[index];
    
    //3rd - no overlap
    else if(qend<start || qstart> end)
    return INT_MAX;
    //2nd - partial overlap i.e some part of between start and end is part of query range
   else{
    int mid = start + (end - start) / 2;
    int left = query(tree, index * 2, start, mid, qstart, qend);
    int right = query(tree, index * 2 + 1, mid + 1, end, qstart, qend);
    return min(left, right);
   }
}
// ==============update by index and value================
void update(int tree[],int index,int start,int end,int i,int value){
    if(i < start|| i> end) 
    return;
    if(start == end)
        tree[index] = value;
    int mid = start + (end - start) / 2;
    update(tree, index * 2, start, mid, i, value);
    update(tree, 2 * index +1, mid + 1, end, i, value);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}

// ==============update in range===============
void updatebyRange(int tree[], int index, int start, int end, int qs,int qe, int value)
{
    if (qe < start || qs > end)
        return;
    if (start == end)
        tree[start] +=value;
    int mid = start + (end - start) / 2;
    updatebyRange(tree, index * 2, start, mid, qs,qe,value);
    updatebyRange(tree, 2 * index + 1, mid + 1, end, qs,qe, value);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++)
        cin >> arr[i];
    int *tree = new int[4 * n + 1];
    int index = 1;
    int start = 0;
    int end = n - 1;
    create(tree, arr, index, start, end);
    for (int i = 0;i<4*n + 1;i++){
        cout << tree[i] << " ";
    }
    int q;
    cin >> q;
    int qs, qe;
    while(q--){
        cin >> qs >> qe;
        query(tree, 1, 0, n - 1, qs, qe);
    }
    int up,i,value;
    cin>>up;
    while(up--){
        cin >> i >> value;
        update(tree, 1, 0, n - 1, i, value);
    }
}
