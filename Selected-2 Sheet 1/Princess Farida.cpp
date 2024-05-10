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

int n;
ll values[(int)1e4+1];
ll DP[(int)1e4+1][1];
ll solveDP(int i , bool take){
    if (i>=n)
        return 0;
    if(DP[i][take] != -1)
        return DP[i][take];    
    
    if(take)
        return DP[i][take] = max(solveDP(i+1 , false) + values[i] , solveDP(i+1 , true));
    
    return DP[i][take] = solveDP(i+1 , true);
}

void init(){
    memset(DP , -1 , sizeof DP);
}

void solve() {
    init();
    cin>> n;
    for ( int i =0 ; i< n ; i++ )
        cin>> values[i];

    cout<<max(solveDP(0 , true) , solveDP(0 , false))<<endl;
}



int main() {
    katafast
    int t =1;
    cin >> t;
    for(int i =1 ; i<=t ; i++)
    {
        cout<<"Case "<<i<<": ";
        solve();
    }

    return 0;
}