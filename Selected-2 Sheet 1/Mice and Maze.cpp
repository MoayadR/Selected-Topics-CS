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
 
vector<vector<pair<ll,ll>>>adj;
vector<ll>dist(101);
 
int djikstra(ll src , ll end)
{
    dist[src] = 0;
    priority_queue<pair<int,int>> q;
    q.emplace(src , 0);

    while(!q.empty())
    {
        auto top = q.top();
        q.pop();

        for (auto u : adj[top.first])
        {
            if (dist[u.first] > u.second + top.second)
            {
                dist[u.first] = u.second + top.second;
                q.emplace(u.first , dist[u.first]);
            }
        }
    }
    return 0;
}
 
void init(){
    adj.clear();
    adj.resize(101);
    fill(dist.begin() , dist.end() , 1e9+1);
}
 
void solve() {
    init();
    int n , end , t;
    cin>> n>> end >> t;

    int m ; 
    cin>> m;
    for(int i =0 ; i<m ; i++)
    {
        int x, y , c;
        cin>> x>> y >> c;
        adj[y].emplace_back(x , c);
    }

    djikstra(end , 0);
    ll res = 0;

    for(int i =1 ; i<=n ; i++)
    {
        if (dist[i] <= t)
            res++;
    }

    cout<<res<<endl;

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