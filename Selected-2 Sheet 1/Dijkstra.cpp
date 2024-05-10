#include <bits/stdc++.h>
 
using namespace std;
 
#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define endl '\n'

const ll inf = 1e18;
vector<pair<ll, ll>> adj[(int)1e5+5];

void dijkstra(ll source, ll node)
{
  map<ll, ll> parent;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  vector<ll> dist(node + 10, inf);

  dist[source] = 0;
  pq.push({0, source});

  while (!pq.empty())
  {
    ll parent_weight = pq.top().first;
    ll parent_node = pq.top().second;
    pq.pop();
    for (auto it : adj[parent_node])
    {
      ll child_node = it.first;
      ll child_weight = it.second;
      if (parent_weight > dist[parent_node])
        continue;
      if (dist[child_node] > child_weight + parent_weight) 
      {
        parent[child_node] = parent_node;
        dist[child_node] = child_weight + parent_weight;
        pq.push({dist[child_node], child_node});
      }
    }
  }

  ll n = node;
  if (parent[n] == 0)
    cout << -1 << endl;
  else
  {
    vector<ll> final;
    parent[1] = -1;
    while (n != -1)
    {
      final.push_back(n);
      n = parent[n];
    }
    reverse(final.begin(), final.end());
    for (auto it : final)
      cout << it << " ";
    cout << endl;
  }
}
 
 
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


void solve() {
    // init();
    int n , m ;
    cin>> n >> m;

    for(int i =0 ; i< m ; i++)
    {
        int x , y ;
        ll c ;
        cin>> x >> y >> c;
        adj[x].emplace_back(y , c);
        adj[y].emplace_back(x , c);
    }

    dijkstra(1 , n);
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