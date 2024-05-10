#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define endl '\n'
int const MOD = 1e9+7;


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

ll n ;
unordered_map<ll , ll>DP;
ll solveDP(ll value)
{
    if (value == 0)
        return 0;
    
    if(DP.find(value) != DP.end())
        return DP[value];

    ll op1 = solveDP(value/2); 
    ll op2 = solveDP(value/3); 
    ll op3 = solveDP(value/4); 
    return DP[value] = max( value , op1 + op2 + op3);
}

void init(){
}

void solve() {
    init();
    while (cin>> n )
    {
        cout<<solveDP(n)<<endl;
    }
}



int main() {
    katafast
    int t =1;
    // cin >> t;
    for(int i =1 ; i<=t ; i++)
    {
        solve();
    }

    return 0;
}