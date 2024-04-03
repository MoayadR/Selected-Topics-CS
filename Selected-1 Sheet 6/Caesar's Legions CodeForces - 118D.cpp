#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define MOD (int)1e8

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

int n1, n2,  k1 , k2;
int dp[101][101][11][11];
int dpSolve(int n_1 ,int n_2 , int  lim1 , int lim2)
{
    if(n_1 == 0 && n_2 == 0)
        return 1;

    if(dp[n_1][n_2][lim1][lim2] != -1)
        return dp[n_1][n_2][lim1][lim2];

    int op1 = 0, op2 = 0;
    if(lim1 && n_1)
        op1 = dpSolve(n_1 -1 , n_2 , lim1-1 , k2);
    if(lim2 && n_2)
        op2 = dpSolve(n_1 , n_2 -1 , k1 , lim2-1);

    return dp[n_1][n_2][lim1][lim2] = ((op1 %MOD)  + (op2%MOD)) % MOD;
}

void solve(int t) {
    cin>> n1 >> n2 >> k1 >> k2;
    memset(dp , -1 , sizeof dp);
    cout<<dpSolve(n1 , n2 , k1 , k2 )<<'\n';
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

