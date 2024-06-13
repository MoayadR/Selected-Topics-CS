#include <bits/stdc++.h>
 
using namespace std;
 
#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define endl '\n'
#define INF 1e9
const int MOD = 1000000000;

int n , m; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> V;
vector<int> dist, L;
int timer;
set<int> ans;

void dfs(int v, int parent = -1) {
    V[v] = true;
    dist[v] = L[v] = timer++;
    int childs=0;
    for (int destination : adj[v]) {
        if (destination == parent) continue;
        if (V[destination]) {
            L[v] = min(L[v], dist[destination]);
        } else {
            dfs(destination, v);
            L[v] = min(L[v], L[destination]);
            if (L[destination] >= dist[v] && parent!=-1)
                ans.insert(v);
            ++childs;
        }
    }
    if(parent == -1 && childs > 1)
        ans.insert(v);
}

void init(){
    adj.clear();
    dist.clear();L.clear();
    dist.resize(n , -1);
    L.resize(n , -1);
    adj.resize(n , vector<int>());
    V.clear();
    V.resize(n , false);
    timer=0;
    ans.clear();
}
void cutpoints() {
    for (int i = 0; i < n; ++i) {
        if (!V[i])
            dfs (i);
    }
}

void solve() {
    while(cin>> n>>m && n!= 0 && m!= 0){
        init();

        for (int i = 0; i < m; ++i) {
            int u , v;
            cin>> u>> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cutpoints();
        cout<<ans.size()<<endl;
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
