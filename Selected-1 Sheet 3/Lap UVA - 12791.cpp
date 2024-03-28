#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

bool valid(ll mid , int x ,int y)
{
    if(y*mid - x*mid >= y)
        return true;
    return false;
}

void solve() {
    int x , y;
    while(cin>>x>>y)
    {
        int left = 0 , right = 1e9;
        int ans=2;
        while(left <= right)
        {
            ll mid = left + (right - left) /2;
            if (valid(mid , x ,y))
            {
                ans = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        cout<<ans<<endl;
    }

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


