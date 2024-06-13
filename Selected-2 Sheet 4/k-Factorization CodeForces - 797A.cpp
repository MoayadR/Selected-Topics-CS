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
    ll k, n;

    ll cnt = -1;
    cin >> n >> k;
    vector<ll> res;

    for (int i = 2; i <= n;)
    {
        if (res.size() == k - 1)
        {
            res.push_back(n);
            break;
        }
        if (n % i == 0)
        {
            res.push_back(i);
            n /= i;
        }
        else
            i++;
    }
    if (res.size() == k)
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
    else
        cout << cnt << endl;
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
