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
    int a, b;
    cin>> a>> b;

    int gcd = __gcd(a, b);

    vector <int> F;

    for(int i = 1; i*i <= gcd; i++)
    {
        if(gcd%i == 0)
        {
            if(i*i == gcd)
            {
                F.push_back(i);
            }
            else
            {
                F.push_back(i);
                F.push_back(gcd/i);
            }
        }
    }

    sort(F.begin() , F.end());

    int q;
    cin>> q;

    for(int i = 1; i <= q; i++)
    {
        int low, high, ans;
        cin>> low >> high;

        int index = upper_bound(F.begin(), F.end(), high) - F.begin();
        index--;

        if(F[index] < low)
            ans = -1;
        else
            ans = F[index];

        cout<< ans << endl;
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
