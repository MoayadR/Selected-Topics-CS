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
    ll a , b;
    cin>> a >> b;

    ll lc = lcm(a,  b);

    ll dasha = lc/a - 1;
    ll masha = lc/b - 1;

    if (dasha<masha)
        dasha++;
    else
        masha++;
    
    if(dasha == masha)
        cout<<"Equal"<<endl;
    if(dasha> masha)
        cout<<"Dasha"<<endl;
    if(masha>dasha)
        cout<<"Masha"<<endl;
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
