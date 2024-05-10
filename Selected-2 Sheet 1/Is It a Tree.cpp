#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define endl '\n'
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

bool visited[10001];
vector<vector<int>>adj(10001);

bool cyclic(int node , int parent){
    visited[node] = 1;
    
    for(auto c : adj[node])
    {
        if (visited[c] && c != parent)
            return true;
        else if (visited[c])
            continue;

        if (cyclic(c , node))
            return true;
    }
    return false;
}

void init(){
    memset(visited , 0 , sizeof visited);
}

void solve() {
    init();
    int n , m;
    cin>>n >> m;

    int x , y;
    for(int i = 0 ; i< n-1 ; i++)
    {
        cin>> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if (cyclic(1 , -1))
    {
        cout<<"NO"<<endl;
        return; 
    }

    for(int i =1 ; i<=n ; i++)
    {
        if(!visited[i])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return;
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