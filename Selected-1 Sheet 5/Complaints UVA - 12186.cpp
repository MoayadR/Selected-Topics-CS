#include <bits/stdc++.h>

using namespace std;

#define katafast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define ll long long

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

int n , T;
vector<vector<int>>adj(1e5+1);
bool visited[(int)1e5+1];

int req(int x)
{
    double z = ((double)x *(T/100.0));
    return ceil(z);
}

int dfs(int start)
{
    visited[start] = 1;
    int newCnt = 0;
    priority_queue<int>workers;
    for(int & nei : adj[start])
    {
        int temp = dfs(nei);
        workers.push(temp);
        newCnt += temp;
    }

    if(adj[start].size() == 0) // worker
        return 1;

    int sz = adj[start].size();
    while(sz != req((int)adj[start].size()))
    {
        sz--;
        newCnt -= workers.top();
        workers.pop();
    }

    return newCnt; // return all workers num under node
}



void solve(int t) {
    while(cin>> n >> T && n != 0 && T != 0)
    {
        adj.clear();
        adj.resize(1e5+1);

        for(int i =0 ; i<n ; i++)
        {
            int x ;
            cin>> x;
            adj[x].push_back(i+1);
        }

        memset(visited , 0 , sizeof visited);


        cout << dfs(0)<<"\n";


    }
}


int main() {
    katafast
    int t =1;
//    cin>> t;
    for(int i =1 ; i<=t ; i++)
    {
        solve(t);
    }

    return 0;
}