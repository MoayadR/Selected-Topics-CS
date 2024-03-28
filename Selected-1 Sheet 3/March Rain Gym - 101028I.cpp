#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

bool valid(ll l , vector<ll>nums , ll k)
{
    ll currentWindow = 0;
    ll used = 0;
    for(int i =0 ; i<nums.size() ;i++)
    {
        used++;
        currentWindow = nums[i] + l;

        int j;
        for(j =i ; j<nums.size() && nums[j] < currentWindow ; j++)
        i = j;
    }

    if(used> k )
        return false;
    return true;
}


void solve() {
    int n , k;
    cin>> n >> k;
    vector<ll>nums(n);
    for(int i =0 ; i<n ; i++)
        cin>>nums[i];

    ll left = 1 , right = nums[nums.size()-1]+1;
    ll res = 1;
    while(left <= right)
    {
        ll mid = left + (right-left) /2;
        if(valid(mid , nums , k))
        {
            res = mid;
            right = mid-1;
        }
        else
            left = mid+1;
    }

    cout<<res<<endl;
}


int main() {
    katafast

    int t = 1;
    cin>> t;

    while(t--)
    {
        solve();
    }

    return 0;
}


