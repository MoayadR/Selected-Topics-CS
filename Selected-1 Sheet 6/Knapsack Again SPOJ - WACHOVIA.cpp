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


ll dp [1001][1001];
vector<int>values, sizes;

ll kp(int index , int cap)
{
    if(index == -1 || cap == 0)
        return 0;

    if(dp[index][cap] != -1)
        return dp[index][cap];

    dp[index][cap] = 0;
    if(cap >= sizes[index])
        dp[index][cap] = max(values[index] + kp(index-1 , cap-sizes[index]) , kp(index-1 , cap));
    else
        dp[index][cap] = kp(index-1 , cap);

    return dp[index][cap];
}

void solve(int t) {
    int k , n;
    cin>> k >> n;
    values.resize(n);
    sizes.resize(n);
    for(int i =0 ; i<n ;i++)
    {
        cin>>sizes[i]>>values[i];
    }
    memset(dp , -1 , sizeof dp);
    cout<<"Hey stupid robber, you can get "<<kp(n-1 , k)<<".\n";
}


int main() {
    katafast
    int t =1;
    cin>> t;
    for(int i =1 ; i<=t ; i++)
    {
        solve(t);
    }

    return 0;
}
















//vector<int>items;
//int n ;
//int dp[21][21];
//int LIS(int i , int last)
//{
//    if(i == n+1)
//        return 0;
//    if(dp[i][last] != -1)
//        return dp[i][last];
//
//    dp[i][last] = 0;
//    if(items[i] > last)
//        dp[i][last] = max(1 + LIS(i+1 , items[i]) , LIS(i+1 , last));
//    else
//        dp[i][last] =  LIS(i+1 , last);
//
//    return dp[i][last];
//}



