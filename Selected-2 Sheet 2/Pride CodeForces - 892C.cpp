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
    int n ;
    cin>> n ;
    vector<ll> values(n);
    int ones = 0;
    for(int i =0 ; i<n ; i++){
        cin>>values[i];
        if (values[i] == 1)
            ones++;
    }
    if (ones)
    {
        cout<<n-ones<<endl;
        return ;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n -1; j++)
        {
            ll gcdValue = __gcd(values[j] , values[j+1]);
            if (gcdValue == 1)
            {
                cout<<n+i<<endl;
                return ;
            }
            values[j] = gcdValue;
        }
    }

    cout<<-1<<endl;
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
