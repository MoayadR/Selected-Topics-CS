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

bool visited[(int)1e6+1];
vector<vector<int>>adj(1e6+1);
int longest = 0;
int farthestNode = 0;

void longestPath(int node , int path)
{
    visited[node] = 1;

    if (path > longest)
    {
        longest = path;
        farthestNode = node;
    }

    for (auto c : adj[node])
    {
        if (!visited[c])
            longestPath(c , path+1);
    }
}

void init(){
    memset(visited , 0 , sizeof visited);
}

void solve() {
    init();
    int n; 
    cin>>n ;

    int x , y;
    for(int i = 0 ; i< n-1 ; i++)
    {
        cin>> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    longestPath(1 , 0);
    init();
    longest = 0;
    longestPath(farthestNode , 0);
    cout<<longest<<endl;;
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