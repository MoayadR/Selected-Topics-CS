#include <bits/stdc++.h>
 
using namespace std;
 
#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long
#define endl '\n'
#define INF 1e9
const int MOD = 1000000000;


vector<vector<int>> graph, graphTrans;
vector<bool> V;
vector<int> seq, strongComp;

void dfs_order(int v) {
    V[v] = true;

    for (auto u : graph[v])
        if (!V[u])
            dfs_order(u);

    seq.push_back(v);
}

void dfs_comp(int v) {
    V[v] = true;
    strongComp.push_back(v);

    for (auto u : graphTrans[v])
        if (!V[u])
            dfs_comp(u);
}


void init(int n){
    graph.clear();
    graphTrans.clear();
    graph.resize(n+1 , vector<int>());
    graphTrans.resize(n+1 , vector<int>());
}

void solve() {
    int n;

    cin>> n;

    init(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char x;
            cin>> x;
            if (x == 'Y')
            {
                graph[i].push_back(j);
                graphTrans[j].push_back(i);
            }
        }
    }

    V.clear();
    V.resize(n, false);

    for (int i = 0; i < n; i++)
        if (!V[i])
            dfs_order(i);

    V.clear();
    V.resize(n, false);
    reverse(seq.begin(), seq.end());

    int ans = 0;

    for (auto v : seq)
        if (!V[v]) {
            dfs_comp (v);

            ans++ ;

            strongComp.clear();
        }

    cout<<ans<<endl;
}


int main()
{
    katafast
    int t =1;
    cin >> t;

    for(int i =1 ; i<=t ; i++)
    {
        solve();
    }

    return 0;
}
