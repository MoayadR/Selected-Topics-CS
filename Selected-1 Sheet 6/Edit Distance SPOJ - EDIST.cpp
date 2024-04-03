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

string s1 , s2;
ll dp [2005][2005];
ll dpSolve( ll sz1 , ll sz2)
{
    if(sz1 == 0)
        return sz2;
    if(sz2 == 0)
        return sz1;

    if(dp[sz1][sz2] != -1)
        return dp[sz1][sz2];

    if(s1[sz1-1] ==s2[sz2-1])
    {
        dp[sz1][sz2] = dpSolve(sz1-1 , sz2-1);
        return dp[sz1][sz2];
    }
    else
    {

        ll op1 = dpSolve(sz1-1 , sz2) +1 ;
        ll op2 = dpSolve(sz1 , sz2-1)+1 ;
        ll replaceFrom2In1 = dpSolve(sz1-1 , sz2-1)+1;
        dp[sz1][sz2] = min(op2 , min(op1 , replaceFrom2In1));
        return dp[sz1][sz2];
    }
}

void solve(int t) {
    cin>> s1 >> s2;
    memset(dp , -1 , sizeof dp);
    cout<<dpSolve((ll)s1.size()  ,(ll)s2.size())<<'\n';
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