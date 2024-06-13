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

vector<vector<pair<int,int>>>adj;
vector<int>dist(2e5+10);

int dijkstra(int start , int end)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dist[start] = 0;
    q.emplace(start , dist[start]);

    while(!q.empty())
    {
        auto top = q.top();
        q.pop();

        for(auto u : adj[top.first])
        {
            if( dist[u.first] > top.second + u.second)
            {
                dist[u.first] = top.second + u.second;
                q.emplace(u.first , dist[u.first]);
            }
        }
    }

    return dist[end];
}

void init(){
    adj.clear();
    adj.resize(2e5+10);
    fill(dist.begin() , dist.end() , INF);
}

 
void solve() {
    init();
    int n , m; 
    cin>> n >> m;

    for(int i =0 ;i<m ;i++)
    {
        int  x , y , c;
        cin>> x >> y >> c;
        adj[x].emplace_back(y , c);
    }
    int start , end ;
    cin>> start >> end;

    int res = dijkstra(start , end);
    if(res == INF)
        cout<<"NO"<<endl;
    else
        cout<<res<<endl;
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