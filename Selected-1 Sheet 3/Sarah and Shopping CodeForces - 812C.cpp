#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

ll valid(ll p , vector<ll>items , ll k){
    ll cost = 0;

    for(int i =0 ; i<items.size() ; i++)
        items[i] += ((i+1) * p);

    sort(items.begin() , items.end());

    for(ll i =0 ; i<p && i<items.size() ; i++)
    {
        cost += items[i] ;
    }

    if (cost > k)
        return -1;

    return cost;
}

void solve() {
    ll n ; ll k;
    cin>> n >> k;
    vector<ll> items(n);
    for(int i =0 ;i < n ;i++)
        cin>>items[i];


    ll left =0 , right = (ll)items.size();
    ll ans = 1e9+1 , cost = 0;
    while(left <= right)
    {
        ll mid = left + (right-left)/2;
        ll temp = valid(mid , items , k);
        if(temp != -1)
        {
            ans = mid;
            cost = temp;
            left = mid +1;
        }
        else
        {
            right = mid -1;
        }
    }

    cout<<ans << ' ' << cost<<endl;
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


