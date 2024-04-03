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

ll dp[(int)1e5+5][2];
vector<ll> vec1;
vector<ll> vec2;
int n ;

ll dpSolve(int i , bool turn)
{
    if(i == n)
        return 0;

    if(dp[i][turn] !=-1)
        return dp[i][turn];

    if(turn == 0)
    {
        return dp[i][turn] = max(dpSolve(i+1 , 0) , vec1[i] + dpSolve(i+1 , 1));
    }else
    {
        return dp[i][turn] = max(dpSolve(i+1 , 1) , vec2[i] + dpSolve(i+1 , 0));
    }
}

void solve(int t) {
    cin>> n;
    vec1.resize(n);
    vec2.resize(n);
    for(int i =0 ; i<n ; i++)
        cin>>vec1[i];
    for(int i =0 ; i<n ; i++)
        cin>>vec2[i];

    memset(dp , -1 , sizeof dp);

    cout<<max(dpSolve(0 , 0) , dpSolve(0 , 1))<<'\n';
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

