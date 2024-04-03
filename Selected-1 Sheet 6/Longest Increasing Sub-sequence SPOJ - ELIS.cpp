#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

bool inbound2D(int i , int j , int is , int js)
{
    if(i>=0 && i <is && j>=0 && j<js)
        return true;
    return false;
}

bool inbound(int i , int is)
{
    if(i>=0 && i <is)
        return true;
    return false;
}


vector<int>items;
int n ;
int dp[21][21];
int dpSolve(int i , int last)
{
    if(i == n+1)
        return 0;
    if(dp[i][last] != -1)
        return dp[i][last];

    dp[i][last] = 0;
    if(items[i] > last)
        dp[i][last] = max(1 + dpSolve(i+1 , items[i]) , dpSolve(i+1 , last));
    else
        dp[i][last] =  dpSolve(i+1 , last);

    return dp[i][last];
}

void solve(int t) {
    cin>> n;
    items.resize(n+1);
    for(int i = 1 ; i<=n ; i++)
        cin>> items[i];
    memset(dp , -1 , sizeof dp);
    cout<<dpSolve(1 , 0)<<'\n';
}


int main() {
    katafast
    int t =1;
//    cin>> t;
    for(int i =1 ; i<=t ; i++)
    {
        solve(t);
    }

    return 0;
}