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

int dp[105][100*505];
int n ;
vector<int>items;
int total;

int dpSolve(int i , int first ){
    if (i == n)
        return abs(abs(total - first )- (first)) ;

    int &ret = dp[i][first];

    if( ret != -1)
        return ret;

    ret = 0;

    ll op1 = dpSolve(i+1 , first+items[i]);
    ll op2 = dpSolve(i+1 , first );

    ret = min(op1 , op2);
    return ret;
}

void solve(int t) {
    cin>>n;
    items.resize(n);
    total = 0;
    for(int i = 0 ; i< n ;i++)
    {
        cin>> items[i];
        total += items[i];
    }
    memset(dp , -1 , sizeof dp);
    cout<<dpSolve(0 , 0)<<'\n';

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
