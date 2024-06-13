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

vector<vector<int>>adj(30);
bool visited[30];
void dfs(int node)
{
    visited[node] = 1;

    for(auto u : adj[node])
        if (!visited[u])
            dfs(u);
}

void init(){
    adj.clear();
    adj.resize(30);
    memset(visited , 0 , sizeof visited);
}

 
void solve() {
    init();
    char end;
    cin>> end;

    int n ;
    n = (int) end - 'A' + 1;

    string connection;
    cin.ignore();
    while(getline(cin , connection) && connection != ""){
        int x , y;
        x = (int)connection[0] - 'A';
        y = (int)connection[1] - 'A';

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ans = 0;
    for(int i =0 ; i<n ; i++){
        if (!visited[i])
        {
            dfs(i);
            ans++;
        }
    }
    cout<<ans<<endl;
}
 
 
 
int main() {
    katafast
    int t =1;
    cin >> t;
    for(int i =1 ; i<=t ; i++)
    {
        solve();
        if(i != t)
            cout<<endl;
    }
 
    return 0;
} 