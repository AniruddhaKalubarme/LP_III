#include<bits/stdc++.h>
using namespace std;

int solve(int val[], int wt[], int weight, int n, vector<vector<int>> &dp)
{
    if(weight<0)
    {
        return INT_MIN;
    }

    if(n < 0)
    {
        return 0;
    }

    if(dp[n][weight] != -1)
        return dp[n][weight];

    int include = solve(val, wt, weight-wt[n], n-1, dp);
    if(include!=INT_MIN)
    {
        include+=val[n];
    }

    int exclude = solve(val, wt, weight, n-1, dp);

    dp[n][weight] = max(include, exclude);
    return dp[n][weight];
}

int main()
{
    int W = 10;
    int val[] = {1, 2, 3}; 
    int wt[] = {4, 5, 6};
    int n = 3;
    vector<vector<int>> dp(n, vector<int> (W+1, -1));
    cout<<solve(val, wt, W, n-1, dp)<<endl;
    return 0;
}