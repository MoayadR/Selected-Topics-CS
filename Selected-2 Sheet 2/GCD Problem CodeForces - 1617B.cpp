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
    ll n; 
    cin>> n;

    ll c = 1;

    for(ll i =2 ; i<n;i++)
    {
        ll b = n - i - 1;
        ll res =__gcd(i , b);
        if (res == 1)
        {
            cout<<i<< ' ' << b << ' ' << c <<endl;
            break;
        }
    }
}
 
 
 
int main() {
    katafast
    int t =1;
    cin >> t;
    for(int i =1 ; i<=t ; i++)
    {
        solve();
    }
 
    return 0;
} 