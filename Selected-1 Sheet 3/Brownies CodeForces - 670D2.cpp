#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

bool valid(ll k , vector<ll>need ,vector<ll>gram , ll special ){
    ll needed = 0 ;
    for(int i =0 ; i<need.size() ; i++)
    {
        if((need[i] * k) > gram[i])
            needed += ((need[i] * k) - gram[i]);
    }

    if(needed <= special)
        return true;
    return false;
}

void solve() {
    int n ;
    ll special ;
    cin>> n >> special;
    vector<ll> need(n);
    vector<ll> gram(n);
    for(int i =0 ; i<n ; i++)
        cin>> need[i];
    for(int i =0 ; i<n ; i++)
        cin>> gram[i];

//    if(!valid(1 , need , gram,special))
//    {
//        cout<<0<<endl;
//        return;
//    }

    ll left = 0 , right =1e5;
    ll ans = 1e5;
    while(left <= right)
    {
        ll mid = left + (right-left)/2;
        if(valid(mid , need , gram , special))
        {
            ans = mid;
            left = mid+1;
            right *=1e2;
        }
        else
            right = mid-1;
    }

    cout<<ans<<endl;
}


int main() {
    katafast

    int t = 1;
//    cin>> t;

    while(t--)
    {
        solve();
    }

    return 0;
}


