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

ll neededCalc(char c , int n , ll mid , string s){
    ll count = 0;

    for (int i = 0 ; i < s.size() ; i++)
        if(s[i] == c)
            count++;

    ll val = max( (ll)0 , (count * mid) - n);
    return val;
}

void solve() {
    string s;
    cin >> s;

    int nb, ns, nc;
    cin >> nb >> ns >> nc;

    int pb, ps, pc;
    cin >> pb >> ps >> pc;

    ll r;
    cin >> r;

    long long left = 0, right = 1e15, ans = 0;

    while (left <= right) {
        ll mid = (left + right) / 2;
        
        ll bCount = neededCalc('B' , nb , mid , s);
        ll sCount = neededCalc('S' , ns , mid , s);
        ll cCount = neededCalc('C' , nc , mid , s);

        ll cost = bCount * pb + sCount * ps + cCount * pc;

        if (cost <= r) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << endl;

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
