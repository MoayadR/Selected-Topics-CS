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
vector<vector<int>> adj(110 , vector<int>());
int in[110];
queue<int>q;
vector<int>ans;

void init(){
    memset(in , 0 , sizeof(in));
}

void topo(){
    int u;
    while(!q.empty()){
        u = q.front();
        q.pop();
        ans.push_back(u);
        for (auto v : adj[u]){
            in[v]--;
            if (in[v]==0){
                q.push(v);
            }
        }
    }
}

void solve() {
    init();

    for (int i = 0 ; i<m ; i++){
        int x , y;
        scanf("%d%d",&x,&y);
        in[y]++;
        adj[x].push_back(y);
    }

    for (int i = 1 ; i<=n ; i++){
        if (in[i]==0){
            q.push(i);
        }
    }

    topo();

    for (int i = 0 ; i<ans.size() ; i++){
        if (i == (ans.size() - 1))
        {
            cout<<ans[i];
        }
        else
        {
            cout<<ans[i]<<" ";
        }
    }

    cout<<endl;

    ans.clear();

    for (int i = 1 ; i<=n ; i++){
        adj[i].clear();
    }
}


int main()
{
    katafast
    int t =1;
    // cin >> t;
    for(int i =1 ; i<=t ; i++)
    {
        while(scanf("%d%d",&n,&m) == 2){
            if (n==0 && m==0)
                break;
            solve();
        }
    }
 
    return 0;
}
