#include <bits/stdc++.h>
 
using namespace std;
 
#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define endl '\n'
#define INF 1e9
const int MOD = 1000000000;


// vector<pair<int,int>>moves = {
//     {-1 , -1}, {+1 , +1},
//     {-1 , +1} , {+1 , -1},
//     {+1 , 0} , {-1 , 0},
//     {0 , +1} , {0 , -1}
// };
 
// bool inbound2D(int i , int j , int is , int js)
// {
//     if(i>=0 && i <is && j>=0 && j<js)
//         return true;
//     return false;
// }
 
// bool inbound(int i , int is)
// {
//     if(i>=0 && i <is)
//         return true;
//     return false;
// }

void init(){
}
void solve() {
    ll n;
    cin >> n;
    if(n == 1)
        cout<<1<<endl;
    else if(n == 2)
        cout<<2<<endl;
    else if(n == 3)
        cout<<6<<endl;
    else if (n%2==0)
    {
        if(n%3==0)
            cout<<(ll)(n-1)*(n-2)*(n-3)<<endl;
        else
            cout<<(ll)(n)*(n-1)*(n-3)<<endl;
    }
    else
    {
        ll res = lcm((ll)n, (ll)lcm((ll)n - 2, (ll)n - 1));
        cout << res << endl;
    }
}


int main()
{
    katafast
    int t =1;
    // cin >> t;
    for(int i =1 ; i<=t ; i++)
    {
        solve();
    }
 
    return 0;
}
