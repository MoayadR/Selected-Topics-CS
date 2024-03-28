#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

ll getIth(ll mid , ll n , ll m){
    ll count = 0;
    for(ll i = 1 ; i<=n ; i++)
        count += min((mid/i), m );

    return count;
}


void solve() {
    ll n , m , v;
    cin>> n>> m >> v;
    ll left =1 , right = n*m;
    while(left <= right)
    {
        ll mid = left + (right-left)/2;
        ll value = getIth(mid , n , m);
        if(value < v)
            left = mid+1;
        else
            right = mid-1;
    }
    cout<<left<<endl;
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


