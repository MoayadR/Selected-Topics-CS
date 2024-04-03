#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define MOD (ll)1000000007

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

int k ;
ll dp[(int)1e5+1];
ll pre[(int)1e5+1];

ll dpSolve(int len){
    if(len == 0)
        return 1;

    if(dp[len] != -1)
        return dp[len];

    ll op1= 0 , op2 = 0;
    op1 = dpSolve(len-1);
    if(len >= k)
        op2 = dpSolve(len-k);

    return dp[len] = (op1+op2) % MOD;
}

void solve(int t) {
    int a , b ;
    cin>> a >> b;

    cout<<(pre[b] - pre[a-1] + MOD) % MOD<<'\n';
}


int main() {
    katafast
    int t =1;
    cin>> t;

    cin>> k;
    pre[0] = 0;
    memset(dp , -1 , sizeof dp);
    for(int i =1 ; i<= 1e5 ; i++)
        pre[i] = pre[i-1] + dpSolve(i);

    for(int i =1 ; i<=t ; i++)
    {
        solve(t);
    }

    return 0;
}

