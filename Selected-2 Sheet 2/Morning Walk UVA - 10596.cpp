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


int n , m;
vector<vector<int>> adj;
bool vis[210];
void dfs(int i){
    vis[i] = true;
    for(auto e : adj[i]){
        if(!vis[e]) dfs(e);
    }
}

void init(){
    adj.clear();
    adj.resize(n , vector<int>());
    memset(vis , true , sizeof vis);
}

void solve() {
    int countOdd = 0;
    int countEven = 0;

    init();
    for (int i = 0; i < m; i++)
    {
        int a , b;
        cin>> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        vis[a] = false;
        vis[b] = false;
    }

    int components = 0;
    for (int i =0 ;i<n ; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            components++;
        }

        if (components >1)
        {
            printf("Not Possible\n");
            return;
        }

        if (adj[i].size()%2 == 1 )
            countOdd++;
    }

    if (components == 0)
    {
        printf("Not Possible\n");
        return;
    }

    if (countOdd == 0){
        printf("Possible\n");
        return;
    }

    printf("Not Possible\n");
}


int main()
{
    katafast
    int t =1;
    // cin >> t;
    for(int i =1 ; i<=t ; i++)
    {
        while(cin>>n>>m){
            solve();
        }
    }
 
    return 0;
}
