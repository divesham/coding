#include <bits/stdc++.h>
using namespace std;

int tdp[100][100];

// Recursive Into Top Down Dp
int MatrixChain(int m[], int i, int j)
{
    //Base case
    if (i == j)
    {
        tdp[i][j] = 0;
        return 0;
    }
    if (tdp[i][j] != -1)
    {
        return tdp[i][j];
    }

    int ans = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int temp = MatrixChain(m, i, k) + MatrixChain(m, k + 1, j) + m[i - 1] * m[k] * m[j];
        ans = min(ans, temp);
    }
    tdp[i][j] = ans;
    return ans;
}

// buttom up dp
int MatrixChiainButtomUp(int m[], int n)
{
    int dp[100][100];
    //make diagonal Elements zero
    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i <= n - L; i++)
        {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + m[i - 1] * m[k] * m[j]);
            }
        }
    }
    return dp[1][n - 1];
}
int main()
{
    int n;
    cin >> n;
    int matrix[n];
    for (int i = 0; i < n; i++)
        cin >> matrix[i];
    memset(tdp, -1, sizeof(tdp));
    cout << "This is by Top down Dp" << endl;
    cout << MatrixChain(matrix, 1, n - 1) << endl;
    cout << "by Buttom UP DP" << endl;
    cout << MatrixChiainButtomUp(matrix, n);
}
