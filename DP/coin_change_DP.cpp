 #include<bits/stdc++.h>
using namespace std;

int find(int arr[], int coins[], int x, int n)
{
    if (arr[n] != 0)
        return arr[n];
    int min1 = INT_MAX;
    for (int i = 0; i < x; i++)
    {
        int min2 = 1 + find(arr, coins, x, n - coins[i]);
        if (min2 < min1)
        {
            min1 = min2;
        }
    }
    arr[n] = min1;
    return arr[n];
}

int main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    int coin[x];
    for (int i = 0; i < x; i++)
    {
        cin>>coin[i];
    }
    int arr[n + 1];
    // memset(arr, 0,n+1);
    for (int i = 0;i<n+1;i++){
        arr[i] = 0;
    }
        for (int i = 0; i < x; i++)
            arr[coin[i]] = 1;
    cout << find(arr, coin, x, n)<<endl;
    for (int i = 0; i< n + 1;i++){
        cout << arr[i] << " ";
    }
}
