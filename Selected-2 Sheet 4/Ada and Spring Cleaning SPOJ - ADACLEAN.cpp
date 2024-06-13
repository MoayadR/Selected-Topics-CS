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
//

ll power(ll b, ll p, ll mod){
    ll ret = 1;
    while(p){
        if(p%2)
            ret = (ret*b)%mod;
        b = (b*b)%mod;
        p/=2;
    }
    return ret;
}

void init(){
}
void solve() {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        set<pair<ll,ll>> pairSet;

        ll var1 = 0, var2 = 0, term1 = 1, term2 = 1;

        for(int i = 0; i < k; i++)
        {
            var1 = (var1 + term1 * s[i]) % 1000000007;
            term1 = (term1 * 31) % 1000000007;

            var2 = (var2 + term2 * s[i]) % 1000000009;
            term2 = (term2 * 37) % 1000000009;
        }
        pairSet.insert({var1, var2});
        ll first_inverse = power(31, 1000000007 - 2, 1000000007);
        ll second_inverse = power(37, 1000000009 - 2, 1000000009);
        for(int i = k, j = 0; i < n; i++, j++)
        {
            var1 -= s[j];
            if(var1 < 0) var1 += 1000000007;
            var1 = (var1 + term1 * s[i]) % 1000000007;
            var1 = (var1 * first_inverse) % 1000000007;

            var2 -= s[j];
            if(var2 < 0) var2 += 1000000009;
            var2 = (var2 + term2 * s[i]) % 1000000009;
            var2 = (var2 * second_inverse) % 1000000009;
            pairSet.insert({var1, var2}); //cout << var1 << " " << var2 << endl;
        }
        cout << pairSet.size() << endl;
}


int main()
{
    katafast
    int t =1;
    cin >> t;
    for(int i =1 ; i<=t ; i++)
    {
        solve();
    }

    return 0;
}
