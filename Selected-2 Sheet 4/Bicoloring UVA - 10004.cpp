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

vector<vector<int>> adj(205 , vector<int>());
void init(){
    for (int i = 0; i < 205; i++)
    {
        adj[i].clear();
    }
}

bool bipartite(int start){
    int colors[205];
    memset(colors , -1 , sizeof colors);
    colors[0] = 1;

    queue<int>q;
    q.push(start);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(colors[v] == -1){
                colors[v] = 1 - colors[u];
                q.push(v);
            }
            else if(colors[v] == colors[u]){
                return false;
            }
        }
    }
    return true;
}

int n;
void solve() {
    int m;
    
    cin>> m;

    init();
    for (int i = 0; i < m; i++)
    {
        int a , b;
        cin>> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout<< (bipartite(0) ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
}


int main()
{
    katafast
    int t =1;
    // cin >> t;
    for(int i =1 ; i<=t ; i++)
    {
        while(cin>> n && n!=0)
            solve();
    }

    return 0;
}
