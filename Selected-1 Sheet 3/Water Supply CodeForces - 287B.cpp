#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

ll n , k;

ll generateSum (ll num)
{
    return (num*(num+1))/2;
}

void solve() {
    cin>> n>> k;


    if(n == 1)
    {
        cout<< 0 <<endl;
        return;
    }
    if(n <= k)
    {
        cout<< 1 <<endl;
        return;
    }
    n--;
    ll Ksum = generateSum(k-1);
    if(Ksum < n)
    {
        cout<<-1<<endl;
        return ;
    }

    ll left =0 , right =k-1;
    ll ans = -1;
    while(left <= right)
    {
        ll mid = left + (right-left)/2;
        if(Ksum - generateSum(mid) >= n)
        {
            ans = mid;
            left = mid+1;
        }
        else
            right = mid -1;
    }
    cout<<k-1-right<<endl;

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


