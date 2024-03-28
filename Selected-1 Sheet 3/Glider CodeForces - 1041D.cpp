#include <bits/stdc++.h>
 
using namespace std;
 
#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define endl '\n'
#define INF 1e6
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

void init(){

}

void solve() {
    init();
    int n; 
    ll h;
    cin>> n>> h;
    vector<pair<ll , ll>> seg(n);

    for(int i =0 ; i<n ; i++)
        cin>> seg[i].first >> seg[i].second;

    ll l =0 , r = 0 , newH =0 ;
    ll ans = 0;
    ll maxAns = 0;

    while(r<n){

        if (r > 0)
        {
            newH += seg[r].first - seg[r-1].second;
            while(newH >= h)
            {
                newH -= seg[l+1].first - seg[l].second;
                ans -= seg[l].second - seg[l].first;
                l++;
            }
        }

        ans += seg[r].second - seg[r].first;
        r++;
        maxAns = max(maxAns , ans);
    }
    cout<< maxAns + h<<endl;

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
 