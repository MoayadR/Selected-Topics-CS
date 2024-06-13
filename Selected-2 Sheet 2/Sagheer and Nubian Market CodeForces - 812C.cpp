#include <bits/stdc++.h>
 
using namespace std;
 
#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define endl '\n'
#define INF 1e6
int const MOD = 1e9+7;
 
vector<pair<int,int>>moves = {
    {-1 , -1}, {+1 , +1},
    {-1 , +1} , {+1 , -1},
    {+1 , 0} , {-1 , 0},
    {0 , +1} , {0 , -1}
};
 
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

ll findAns(vector<ll>items,ll k , ll budget)
{
    ll cost = 0;
    for(int i =0 ; i<items.size() ; i++)
    {
        items[i] += (k*(i+1));
    }

    sort(items.begin() , items.end());

    for(int i =0 ; i< items.size() && i< k  ; i++)
    {
        cost += items[i];
    }

    if (cost > budget)
        return -1;
    
    return cost;
}
 
void solve() {
    ll n ;
    ll s;
    cin>> n>> s;

    vector<ll>items;
    items.resize(n);

    for(int i =0 ;i < n; i++)
        cin>> items[i];

    int l =0 , r = n;
    int mid;

    int maxK = 0;
    ll maxS = 0; 

    while(l <=r)
    {
        mid = l + (r - l) / 2;
        
        ll res = findAns(items , mid , s);
        if(res ==-1)
        {
            r = mid-1;
        }
        else
        {
            maxK = mid;
            maxS = res;
            l = mid+1;
        }
    }

    cout<< maxK << ' '<< maxS<<endl;

}
 
 
 
int main() {
    katafast
    int t =1;
    // cin >> t;
    for(int i =1 ; i<=t ; i++)
    {
        solve();
    }
 
    return 0;
} 