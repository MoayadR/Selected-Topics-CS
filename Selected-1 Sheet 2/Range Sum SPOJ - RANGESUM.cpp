#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long



deque<ll> generateSuffix(ll n ,  vector<ll>nums)
{
    deque<ll>suffix(n);
    suffix[n-1] = nums[n-1];
    for(ll i =n-2 ; i>=0 ; i--)
    {
        suffix[i] = (nums[i] +suffix[i+1]);
    }
    return suffix;
}

int main() {
    katafast
    ll n ;
    cin>> n;
    vector<ll>nums(n);
    for(ll i =0 ; i<n ; i++)
    {
        cin>>nums[i];
    }

    deque<ll>suffix = generateSuffix(n , nums);


    ll q;
    cin>> q;
    while(q--)
    {
        ll c;
        cin>> c;
        if(c == 1)
        {
            ll l , r;
            cin>> l >> r;
            l--;r--;
            cout<<(suffix[l] - suffix[r+1])<<endl;
        }
        else
        {
            ll p;
            cin>> p;
            ll value = p+suffix[0];
            suffix.push_front(value);
        }
    }
    return 0;
}